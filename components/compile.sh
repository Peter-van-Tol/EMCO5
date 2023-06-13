#!/bin/bash
clean=$true
while test $# -gt 0; do
  case "$1" in
    -nc|--no-clean)
        shift
        echo "Not cleaning"
        shift
        ;;
    -h|--help)
        echo "compile - compile and install the components for EMCO5"
        echo " "
        echo "compile [options]"
        echo " "
        echo "options:"
        echo "-h,  --help       show this brief help"
        echo "-nc, --no-clean   do not clean files after compilation"
        exit 0
        break
      ;;
  esac
done

# Processing of all the components
for f in ./*comp; 
    do echo "Processing $f...";
    halcompile --install $f;
    if [ !$clean ] ; then
        echo  rm ${f%.*}.c ${f%.*}.so
        rm ${f%.*}.c ${f%.*}.so
    fi
done
