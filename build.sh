if [ ! -d "/build" ]; then
  mkdir /build
fi
cd src
#  -s "ALLOW_MEMORY_GROWTH=1"
#  -s "TOTAL_MEMORY=16777216"  16Mb
#  -s "TOTAL_STACK=15728640"   15Mb
emcc main.cpp md5.cpp -s "ALLOW_MEMORY_GROWTH=1" -s "TOTAL_STACK=15728640" -s "TOTAL_MEMORY=16777216" -s "EXPORTED_FUNCTIONS=['_getMD5']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -o ../build/main.js
cd ..