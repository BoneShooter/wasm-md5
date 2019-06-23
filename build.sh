if [ ! -d "/build" ]; then
  mkdir /build
fi
cd src
emcc main.cpp md5.cpp -s "ALLOW_MEMORY_GROWTH=1" -s "EXPORTED_FUNCTIONS=['_getMD5']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -o ../build/main.js
cd ..