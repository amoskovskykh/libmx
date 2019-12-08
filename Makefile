INC = libmx

SRC = mx_printchar \
mx_print_unicode \
mx_printstr \
mx_print_strarr \
mx_printint \
mx_pow \
mx_sqrt \
mx_nbr_to_hex \
mx_hex_to_nbr \
mx_itoa \
mx_foreach \
mx_binary_search \
mx_bubble_sort \
mx_quicksort \
\
mx_strlen \
mx_swap_char \
mx_str_reverse \
mx_strdel \
mx_del_strarr \
mx_get_char_index \
mx_strdup \
mx_strndup \
mx_strcpy \
mx_strncpy \
mx_strcmp \
mx_strcat \
mx_strstr \
mx_get_substr_index \
mx_count_substr \
mx_count_words \
mx_strnew \
mx_strtrim \
mx_del_extra_spaces \
mx_strsplit \
mx_strjoin \
mx_file_to_str \
mx_read_line \
mx_replace_substr \
\
mx_memset \
mx_memcpy \
mx_memccpy \
mx_memcmp \
mx_memchr \
mx_memrchr \
mx_memmem \
mx_memmove \
mx_realloc \
\
mx_create_node \
mx_push_front \
mx_push_back \
mx_pop_front \
mx_pop_back \
mx_list_size \
mx_sort_list \
\
mx_isspace \
mx_strncmp \
mx_printlist \
mx_exp_search \
mx_bin_search \
mx_memjoin \
mx_strchr \

SRCS = $(addsuffix .c, $(SRC))
INCS = $(addsuffix .h, $(INC))
OBJS = $(SRCS:.c=.o)
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INCS)) .
	@clang $(CFLAGS) -c $(SRCS) -I $(INCS)
	@ar -rc libmx.a $(OBJS)
	@mkdir obj
	@mv $(OBJS) obj

uninstall: clean
	@rm -rf libmx.a

clean:
	@rm -rf ./obj
	@rm -rf $(INCS)
	@rm -rf $(SRCS)

reinstall: uninstall install
