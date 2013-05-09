require 'open-uri'

MRuby::Gem::Specification.new('mruby-udpclient') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Julien Ammous'
  
  spec.rbfiles = Dir[File.expand_path('../mrblib/**/*.rb', __FILE__)]
  # spec.linker.libraries << %w(dl pthread)

  # if ENV['OS'] == 'Windows_NT'
  #   spec.cc.flags << %w(-pthread)
  # elsif `uname`.chomp == 'Darwin'
  #   spec.cc.flags << %w(-pthread)
  #   spec.linker.flags << %w(-Wl,-allow_stack_execute -all_load)
  #   # From Homebrew
  #   # TODO: make this more dynamic
  #   spec.cc.include_paths << '/usr/local/Cellar/libffi/3.0.11/lib/libffi-3.0.11/include'
  #   spec.linker.library_paths << '/usr/local/Cellar/libffi/3.0.11/lib'
  # else
  #   spec.cc.flags << %w(-pthread)
  #   spec.mruby.cc.flags << %w(-pthread)
  #   spec.mruby.linker.flags << %w(-pthread -Wl,--export-dynamic -Wl,--whole-archive)
  #   spec.mruby.linker.flags_before_libraries << %w(-Wl,--no-whole-archive)
  # end

  # spec.test_preload = "#{dir}/test/mobitest.rb"
  # rubyvm1_rbx = "#{dir}/test/_rubyvm1.rbx"
  # rubyvm1_c = "#{build_dir}/test/_rubyvm1.c"
  # rubyvm1_o = rubyvm1_c.ext('o')
  # spec.test_objs << rubyvm1_o

  # file rubyvm1_o => rubyvm1_c
  # file rubyvm1_c => rubyvm1_rbx do |t|
  #   open(rubyvm1_c, 'w') do |f|
  #     f.puts '#include <stdint.h>'
  #     build.mrbc.run f, rubyvm1_rbx, 'mruby_data__rubyvm1'
  #   end
  # end

end
