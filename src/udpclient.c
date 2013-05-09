
#include "udpclient.h"

static void udpclient_socket_free(mrb_state *mrb, void *ptr)
{
  close((int)ptr);
}

static struct mrb_data_type udpclient_socket_type = { "UDPSocket", udpclient_socket_free };

static mrb_value udpclient_initialize(mrb_state *mrb, mrb_value self)
{
  int fd = socket(AF_INET,SOCK_DGRAM, 0);
  
  DATA_PTR(self) = (void*)fd;
  DATA_TYPE(self) = &udpclient_socket_type;
  
  // @buf= ""
  // mrb_iv_set(mrb, io, mrb_intern(mrb, "@buf"), mrb_str_new_cstr(mrb, ""));
  return self;
}

static mrb_value udpclient_send(mrb_state *mrb, mrb_value self)
{
  int fd, ret;
  struct sockaddr_in servaddr;
  mrb_value data, addr;
  mrb_int flags, port;
  
  mrb_get_args(mrb, "SiSi", &data, &flags, &addr, &port);
  
  fd = (int) DATA_PTR(self);
  
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr( RSTRING_PTR(addr) );
  servaddr.sin_port = htons(port);

  ret = sendto(fd, RSTRING_PTR(data), RSTRING_LEN(data),
      flags,
      (struct sockaddr *) &servaddr,
      sizeof(servaddr)
    );

  
  return self;
}


void mrb_mruby_udpclient_gem_init(mrb_state *mrb)
{
  struct RClass *udp = mrb_define_class(mrb, "UDPClient", NULL);
  
  int ai = mrb_gc_arena_save(mrb);
  
  mrb_define_method(mrb, udp, "initialize", udpclient_initialize,  ARGS_NONE());
  mrb_define_method(mrb, udp, "send", udpclient_send,  ARGS_REQ(4));
    
  mrb_gc_arena_restore(mrb, ai);
}

void mrb_mruby_udpclient_gem_final(mrb_state* mrb)
{
  
}
