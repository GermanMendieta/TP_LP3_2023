# compilador 
CC := g++ 
CFLAGS := -fpermissive -lpthread 
  
 # direcciones 
SRC_DIR := src 
BUILD_DIR := build 
  
 # Compilacion manual 1 a 1 
listing%: 
	$(eval listing := $(@)) 
	$(eval obj_dir := $(shell find $(SRC_DIR) -type d -name $(listing))) 
	$(eval arch_dest := $(shell echo $(obj_dir) | sed "s/src/build/g"))
	$(eval build_dir := $(shell dirname $(arch_dest))) 
	@mkdir -p $(build_dir)  
	$(CC) $(CFLAGS) -o $(arch_dest) $(obj_dir)/* ; 
  
  
 # Se define una variable con la lista de archivos del directorio
$(eval DIRS := $(shell basename -a $(shell find $(SRC_DIR) -type d -name listing*))) 
  
 # Crear un objetivo que aplica la regla a cada archivo 
all: $(DIRS) 
	@for file in $^; do \ 
		$(MAKE) "$$file"; \ 
		done 
  
clean:  
	@rm $(BUILD_DIR) -rf 


  
.PHONY: clean all
