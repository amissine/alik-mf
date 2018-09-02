default:
	for f in demo/*.c; do \
    gcc -flto -std=c11 -O3 -DSERVER -o $$(basename "$$f" ".c")-server -Isrc "$$f"; \
    gcc -flto -std=c11 -O3 -o $$(basename "$$f" ".c")-client -Isrc "$$f"; \
  done

d1:
	./d1-udp-server NULL 3000
