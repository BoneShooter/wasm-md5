if [ ! -d "/build" ]; then
  mkdir /build
fi
cd src
#  -s "ALLOW_MEMORY_GROWTH=1"
#  -s "TOTAL_MEMORY=5265552"
emcc main.cpp md5.cpp -s "ALLOW_MEMORY_GROWTH=1" -s "EXPORTED_FUNCTIONS=['_getMD5']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -o ../build/main.js
cd ..