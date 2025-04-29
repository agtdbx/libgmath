project('libgmath', 'cpp',
		version : '1.0',
		default_options : ['warning_level=3',
							'cpp_std=c++14'])

includes = include_directories('srcs')

srcs = [
	'srcs/gmath/random.cpp',
]

lib = library('gmath',
			srcs,
			include_directories: includes,
			install : true)

dep_libmath = declare_dependency(link_with: lib, include_directories: includes)

meson.override_dependency('libgmath', dep_libmath)

if get_option('test')
executable('libgmathTest',
			'srcs/main.cpp',
			srcs,
			include_directories: includes,
			install : true)
endif
