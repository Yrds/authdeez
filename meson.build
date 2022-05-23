project('authdeez', 'cpp', version: '0.0.1')

sources = files(
  'src/main.cpp',
  'src/lib.cpp'
  )

include = include_directories('src')

openssl_subproj = subproject('openssl')
openssl_dep = openssl_subproj.get_variable('openssl_dep')

cmake = import('cmake')

cppcodec_subproj = cmake.subproject('cppcodec')
cppcodec_dep = cppcodec_subproj.dependency('cppcodec')

dependencies = []
dependencies += openssl_dep
dependencies += cppcodec_dep

executable('authdeez', sources, dependencies: dependencies, include_directories: include)



# Tests
gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_dep')

dependencies += gtest_dep

## To new tests just add a .cpp file
test_files = files(
  'src/lib.cpp',
  'tests/hmac.cpp',
  'tests/otp.cpp',
  'tests/encoder.cpp',
  'tests/strings.cpp',
  'tests/main.cpp',
  )

all_tests = executable('all_tests', test_files, dependencies: dependencies, 
  include_directories: include)

test('all', all_tests)
