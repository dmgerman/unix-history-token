begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  */
end_comment

begin_define
define|#
directive|define
name|SUN_COMPAT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|N_SIZE
end_ifndef

begin_define
define|#
directive|define
name|N_SIZE
value|0xc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If compiled with GNU C, use the built-in alloca */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"md.h"
end_include

begin_include
include|#
directive|include
file|"link.h"
end_include

begin_comment
comment|/* Macro to control the number of undefined references printed */
end_comment

begin_define
define|#
directive|define
name|MAX_UREFS_PRINTED
value|10
end_define

begin_comment
comment|/* Align to power-of-two boundary */
end_comment

begin_define
define|#
directive|define
name|PALIGN
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
value|(((x) +  (u_long)(p) - 1)& (-(u_long)(p)))
end_define

begin_comment
comment|/* Align to machine dependent boundary */
end_comment

begin_define
define|#
directive|define
name|MALIGN
parameter_list|(
name|x
parameter_list|)
value|PALIGN(x,MAX_ALIGNMENT)
end_define

begin_comment
comment|/* Define this to specify the default executable format.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_MAGIC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_MAGIC
value|QMAGIC
end_define

begin_decl_stmt
specifier|extern
name|int
name|netzmagic
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_MAGIC
value|ZMAGIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEMANGLE_CPLUSPLUS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|demangle
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|demangle
parameter_list|(
name|name
parameter_list|)
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ok.  Following are the relocation information macros.  If your  * system should not be able to use the default set (below), you must  * define the following:   *   relocation_info: This must be typedef'd (or #define'd) to the type  * of structure that is stored in the relocation info section of your  * a.out files.  Often this is defined in the a.out.h for your system.  *  *   RELOC_ADDRESS (rval): Offset into the current section of the  *<whatever> to be relocated.  *Must be an lvalue*.  *  *   RELOC_EXTERN_P (rval):  Is this relocation entry based on an  * external symbol (1), or was it fully resolved upon entering the  * loader (0) in which case some combination of the value in memory  * (if RELOC_MEMORY_ADD_P) and the extra (if RELOC_ADD_EXTRA) contains  * what the value of the relocation actually was.  *Must be an lvalue*.  *  *   RELOC_TYPE (rval): If this entry was fully resolved upon  * entering the loader, what type should it be relocated as?  *  *   RELOC_SYMBOL (rval): If this entry was not fully resolved upon  * entering the loader, what is the index of it's symbol in the symbol  * table?  *Must be a lvalue*.  *  *   RELOC_MEMORY_ADD_P (rval): This should return true if the final  * relocation value output here should be added to memory, or if the  * section of memory described should simply be set to the relocation  * value.  *  *   RELOC_ADD_EXTRA (rval): (Optional) This macro, if defined, gives  * an extra value to be added to the relocation value based on the  * individual relocation entry.  *Must be an lvalue if defined*.  *  *   RELOC_PCREL_P (rval): True if the relocation value described is  * pc relative.  *  *   RELOC_VALUE_RIGHTSHIFT (rval): Number of bits right to shift the  * final relocation value before putting it where it belongs.  *  *   RELOC_TARGET_SIZE (rval): log to the base 2 of the number of  * bytes of size this relocation entry describes; 1 byte == 0; 2 bytes  * == 1; 4 bytes == 2, and etc.  This is somewhat redundant (we could  * do everything in terms of the bit operators below), but having this  * macro could end up producing better code on machines without fancy  * bit twiddling.  Also, it's easier to understand/code big/little  * endian distinctions with this macro.  *  *   RELOC_TARGET_BITPOS (rval): The starting bit position within the  * object described in RELOC_TARGET_SIZE in which the relocation value  * will go.  *  *   RELOC_TARGET_BITSIZE (rval): How many bits are to be replaced  * with the bits of the relocation value.  It may be assumed by the  * code that the relocation value will fit into this many bits.  This  * may be larger than RELOC_TARGET_SIZE if such be useful.  *  *  *		Things I haven't implemented  *		----------------------------  *  *    Values for RELOC_TARGET_SIZE other than 0, 1, or 2.  *  *    Pc relative relocation for External references.  *  *  */
end_comment

begin_comment
comment|/* Default macros */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RELOC_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|RELOC_ADDRESS
parameter_list|(
name|r
parameter_list|)
value|((r)->r_address)
end_define

begin_define
define|#
directive|define
name|RELOC_EXTERN_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_extern)
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE
parameter_list|(
name|r
parameter_list|)
value|((r)->r_symbolnum)
end_define

begin_define
define|#
directive|define
name|RELOC_SYMBOL
parameter_list|(
name|r
parameter_list|)
value|((r)->r_symbolnum)
end_define

begin_define
define|#
directive|define
name|RELOC_MEMORY_SUB_P
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_MEMORY_ADD_P
parameter_list|(
name|r
parameter_list|)
value|1
end_define

begin_undef
undef|#
directive|undef
name|RELOC_ADD_EXTRA
end_undef

begin_define
define|#
directive|define
name|RELOC_PCREL_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_pcrel)
end_define

begin_define
define|#
directive|define
name|RELOC_VALUE_RIGHTSHIFT
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RTLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SUN_COMPAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|RELOC_TARGET_SIZE
parameter_list|(
name|r
parameter_list|)
value|(2)
end_define

begin_comment
comment|/* !!!!! Sun BUG compatible */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELOC_TARGET_SIZE
parameter_list|(
name|r
parameter_list|)
value|((r)->r_length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RELOC_TARGET_BITPOS
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_TARGET_BITSIZE
parameter_list|(
name|r
parameter_list|)
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|nounderscore
end_ifdef

begin_define
define|#
directive|define
name|LPREFIX
value|'.'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LPREFIX
value|'L'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TEXT_START
end_ifndef

begin_define
define|#
directive|define
name|TEXT_START
parameter_list|(
name|x
parameter_list|)
value|N_TXTADDR(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DATA_START
end_ifndef

begin_define
define|#
directive|define
name|DATA_START
parameter_list|(
name|x
parameter_list|)
value|N_DATADDR(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If a this type of symbol is encountered, its name is a warning    message to print each time the symbol referenced by the next symbol    table entry is referenced.     This feature may be used to allow backwards compatibility with    certain functions (eg. gets) but to discourage programmers from    their use.     So if, for example, you wanted to have ld print a warning whenever    the function "gets" was used in their C program, you would add the    following to the assembler file in which gets is defined:  	.stabs "Obsolete function \"gets\" referenced",30,0,0,0 	.stabs "_gets",1,0,0,0     These .stabs do not necessarily have to be in the same file as the    gets function, they simply must exist somewhere in the compilation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_WARNING
end_ifndef

begin_define
define|#
directive|define
name|N_WARNING
value|0x1E
end_define

begin_comment
comment|/* Warning message to print if symbol 				   included */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is input to ld */
end_comment

begin_comment
comment|/* Special global symbol types understood by GNU LD.  */
end_comment

begin_comment
comment|/* The following type indicates the definition of a symbol as being    an indirect reference to another symbol.  The other symbol    appears as an undefined reference, immediately following this symbol.     Indirection is asymmetrical.  The other symbol's value will be used    to satisfy requests for the indirect symbol, but not vice versa.    If the other symbol does not have a definition, libraries will    be searched to find a definition.     So, for example, the following two lines placed in an assembler    input file would result in an object file which would direct gnu ld    to resolve all references to symbol "foo" as references to symbol    "bar".  	.stabs "_foo",11,0,0,0 	.stabs "_bar",1,0,0,0     Note that (11 == (N_INDR | N_EXT)) and (1 == (N_UNDF | N_EXT)).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_INDR
end_ifndef

begin_define
define|#
directive|define
name|N_INDR
value|0xa
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following symbols refer to set elements.  These are expected    only in input to the loader; they should not appear in loader    output (unless relocatable output is requested).  To be recognized    by the loader, the input symbols must have their N_EXT bit set.    All the N_SET[ATDB] symbols with the same name form one set.  The    loader collects all of these elements at load time and outputs a    vector for each name.    Space (an array of 32 bit words) is allocated for the set in the    data section, and the n_value field of each set element value is    stored into one word of the array.    The first word of the array is the length of the set (number of    elements).  The last word of the vector is set to zero for possible    use by incremental loaders.  The array is ordered by the linkage    order; the first symbols which the linker encounters will be first    in the array.     In C syntax this looks like:  	struct set_vector { 	  unsigned int length; 	  unsigned int vector[length]; 	  unsigned int always_zero; 	};     Before being placed into the array, each element is relocated    according to its type.  This allows the loader to create an array    of pointers to objects automatically.  N_SETA type symbols will not    be relocated.     The address of the set is made into an N_SETV symbol    whose name is the same as the name of the set.    This symbol acts like a N_DATA global symbol    in that it can satisfy undefined external references.     For the purposes of determining whether or not to load in a library    file, set element definitions are not considered "real    definitions"; they will not cause the loading of a library    member.     If relocatable output is requested, none of this processing is    done.  The symbols are simply relocated and passed through to the    output file.     So, for example, the following three lines of assembler code    (whether in one file or scattered between several different ones)    will produce a three element vector (total length is five words;    see above), referenced by the symbol "_xyzzy", which will have the    addresses of the routines _init1, _init2, and _init3.     *NOTE*: If symbolic addresses are used in the n_value field of the    defining .stabs, those symbols must be defined in the same file as    that containing the .stabs.  	.stabs "_xyzzy",23,0,0,_init1 	.stabs "_xyzzy",23,0,0,_init2 	.stabs "_xyzzy",23,0,0,_init3     Note that (23 == (N_SETT | N_EXT)).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SETA
end_ifndef

begin_define
define|#
directive|define
name|N_SETA
value|0x14
end_define

begin_comment
comment|/* Absolute set element symbol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is input to LD, in a .o file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SETT
end_ifndef

begin_define
define|#
directive|define
name|N_SETT
value|0x16
end_define

begin_comment
comment|/* Text set element symbol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is input to LD, in a .o file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SETD
end_ifndef

begin_define
define|#
directive|define
name|N_SETD
value|0x18
end_define

begin_comment
comment|/* Data set element symbol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is input to LD, in a .o file. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_SETB
end_ifndef

begin_define
define|#
directive|define
name|N_SETB
value|0x1A
end_define

begin_comment
comment|/* Bss set element symbol */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is input to LD, in a .o file. */
end_comment

begin_comment
comment|/* Macros dealing with the set element symbols defined in a.out.h */
end_comment

begin_define
define|#
directive|define
name|SET_ELEMENT_P
parameter_list|(
name|x
parameter_list|)
value|((x)>= N_SETA&& (x)<= (N_SETB|N_EXT))
end_define

begin_define
define|#
directive|define
name|TYPE_OF_SET_ELEMENT
parameter_list|(
name|x
parameter_list|)
value|((x) - N_SETA + N_ABS)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|N_SETV
end_ifndef

begin_define
define|#
directive|define
name|N_SETV
value|0x1C
end_define

begin_comment
comment|/* Pointer to set vector in data area. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is output from LD. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_STAB__
end_ifndef

begin_comment
comment|/* Line number for the data section.  This is to be used to describe    the source location of a variable declaration. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_DSLINE
end_ifndef

begin_define
define|#
directive|define
name|N_DSLINE
value|(N_SLINE+N_DATA-N_TEXT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Line number for the bss section.  This is to be used to describe    the source location of a variable declaration.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_BSLINE
end_ifndef

begin_define
define|#
directive|define
name|N_BSLINE
value|(N_SLINE+N_BSS-N_TEXT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNU_STAB__ */
end_comment

begin_comment
comment|/* Number of buckets in symbol hash table */
end_comment

begin_define
define|#
directive|define
name|SYMTABSIZE
value|1009
end_define

begin_comment
comment|/* # of global symbols referenced and not defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|undefined_global_sym_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of weak symbols referenced and not defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|undefined_weak_sym_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of undefined symbols referenced by shared objects */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|undefined_shobj_sym_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of multiply defined symbols. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|multiple_def_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of common symbols. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|common_defined_global_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of warning symbols encountered. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_sym_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|list_warning_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define a linked list of strings which define symbols which should be  * treated as set elements even though they aren't.  Any symbol with a prefix  * matching one of these should be treated as a set element.  *  * This is to make up for deficiencies in many assemblers which aren't willing  * to pass any stabs through to the loader which they don't understand.  */
end_comment

begin_struct
struct|struct
name|string_list_element
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|struct
name|string_list_element
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|glosym
struct_decl|;
end_struct_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__symbol_defined__
end_ifndef

begin_define
define|#
directive|define
name|__symbol_defined__
end_define

begin_typedef
typedef|typedef
name|struct
name|glosym
name|symbol
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|entry_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the entry symbol, if any */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|edata_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol _edata */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|etext_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol _etext */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|end_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol _end */
end_comment

begin_comment
comment|/*  * Section start addresses.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total size of text. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of text */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_pad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clear space between text and data */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|data_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total size of data. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|data_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of data */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|data_pad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* part of bss segment within data */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bss_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total size of bss. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bss_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of bss */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|text_reloc_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total size of text relocation. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|data_reloc_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total size of data relocation. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|magic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file magic. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|relocatable_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of a page. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|page_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|search_dirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Directories to search for libraries. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_search_dirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of above. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|write_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write a load map (`-M') */
end_comment

begin_include
include|#
directive|include
file|"dynamic.h"
end_include

end_unit

