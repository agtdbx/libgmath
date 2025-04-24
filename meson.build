project('libmath', 'cpp',
		version : '1.0',
		default_options : ['warning_level=3',
							'cpp_std=c++14'])

includes = include_directories('include')

lib = library('math',
			'srcs/gmath.cpp',
			'srcs/Vec2.cpp',
			include_directories: includes,
			install : true)

dep_libmath = declare_dependency(link_with: lib, include_directories: includes)

meson.override_dependency('libmath', dep_libmath)

if get_option('test')
executable('libmathTest',
			'srcs/main.cpp',
			'srcs/gmath.cpp',
			'srcs/Vec2.cpp',
			include_directories: includes,
			install : true)
endif
