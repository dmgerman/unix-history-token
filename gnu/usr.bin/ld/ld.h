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

begin_define
define|#
directive|define
name|RELOC_JMPTAB_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_jmptable)
end_define

begin_define
define|#
directive|define
name|RELOC_BASEREL_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_baserel)
end_define

begin_define
define|#
directive|define
name|RELOC_RELATIVE_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_relative)
end_define

begin_define
define|#
directive|define
name|RELOC_COPY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_copy)
end_define

begin_define
define|#
directive|define
name|RELOC_LAZY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_jmptable)
end_define

begin_define
define|#
directive|define
name|CHECK_GOT_RELOC
parameter_list|(
name|r
parameter_list|)
value|((r)->r_pcrel)
end_define

begin_define
define|#
directive|define
name|RELOC_INIT_SEGMENT_RELOC
parameter_list|(
name|r
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_GOTOFF
end_ifndef

begin_define
define|#
directive|define
name|MAX_GOTOFF
value|(LONG_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN_GOTOFF
end_ifndef

begin_define
define|#
directive|define
name|MIN_GOTOFF
value|(LONG_MIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Internal representation of relocation types  */
end_comment

begin_define
define|#
directive|define
name|RELTYPE_EXTERN
value|1
end_define

begin_define
define|#
directive|define
name|RELTYPE_JMPSLOT
value|2
end_define

begin_define
define|#
directive|define
name|RELTYPE_BASEREL
value|4
end_define

begin_define
define|#
directive|define
name|RELTYPE_RELATIVE
value|8
end_define

begin_define
define|#
directive|define
name|RELTYPE_COPY
value|16
end_define

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

begin_define
define|#
directive|define
name|N_ISWEAK
parameter_list|(
name|p
parameter_list|)
value|(N_BIND(p)& BIND_WEAK)
end_define

begin_typedef
typedef|typedef
struct|struct
name|localsymbol
block|{
name|struct
name|nzlist
name|nzlist
decl_stmt|;
comment|/* n[z]list from file */
name|struct
name|glosym
modifier|*
name|symbol
decl_stmt|;
comment|/* Corresponding global symbol, 						   if any */
name|struct
name|localsymbol
modifier|*
name|next
decl_stmt|;
comment|/* List of definitions */
name|struct
name|file_entry
modifier|*
name|entry
decl_stmt|;
comment|/* Backpointer to file */
name|long
name|gotslot_offset
decl_stmt|;
comment|/* Position in GOT, if any */
name|int
name|symbolnum
decl_stmt|;
comment|/* Position in output nlist */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|LS_L_SYMBOL
value|1
comment|/* Local symbol starts with an `L' */
define|#
directive|define
name|LS_WRITE
value|2
comment|/* Symbol goes in output symtable */
define|#
directive|define
name|LS_RENAME
value|4
comment|/* xlat name to `<file>.<name>' */
define|#
directive|define
name|LS_HASGOTSLOT
value|8
comment|/* This symbol has a GOT entry */
define|#
directive|define
name|LS_WARNING
value|16
comment|/* Second part of a N_WARNING duo */
block|}
name|localsymbol_t
typedef|;
end_typedef

begin_comment
comment|/* Symbol table */
end_comment

begin_comment
comment|/*  * Global symbol data is recorded in these structures, one for each global  * symbol. They are found via hashing in 'symtab', which points to a vector  * of buckets. Each bucket is a chain of these structures through the link  * field.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|glosym
block|{
name|struct
name|glosym
modifier|*
name|link
decl_stmt|;
comment|/* Next symbol hash bucket. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this symbol.  */
name|long
name|value
decl_stmt|;
comment|/* Value of this symbol */
name|localsymbol_t
modifier|*
name|refs
decl_stmt|;
comment|/* Chain of local symbols from object 				   files pertaining to this global 				   symbol */
name|localsymbol_t
modifier|*
name|sorefs
decl_stmt|;
comment|/* Same for local symbols from shared 				   object files. */
name|char
modifier|*
name|warning
decl_stmt|;
comment|/* message, from N_WARNING nlists */
name|int
name|common_size
decl_stmt|;
comment|/* Common size */
name|int
name|symbolnum
decl_stmt|;
comment|/* Symbol index in output symbol table */
name|int
name|rrs_symbolnum
decl_stmt|;
comment|/* Symbol index in RRS symbol table */
name|localsymbol_t
modifier|*
name|def_lsp
decl_stmt|;
comment|/* The local symbol that gave this 					   global symbol its definition */
name|char
name|defined
decl_stmt|;
comment|/* Definition of this symbol */
name|char
name|so_defined
decl_stmt|;
comment|/* Definition of this symbol in a shared 				   object. These go into the RRS symbol table */
name|u_char
name|undef_refs
decl_stmt|;
comment|/* Count of number of "undefined" 				   messages printed for this symbol */
name|u_char
name|mult_defs
decl_stmt|;
comment|/* Same for "multiply defined" symbols */
name|struct
name|glosym
modifier|*
name|alias
decl_stmt|;
comment|/* For symbols of type N_INDR, this 				   points at the real symbol. */
name|int
name|setv_count
decl_stmt|;
comment|/* Number of elements in N_SETV symbols */
name|int
name|size
decl_stmt|;
comment|/* Size of this symbol (either from N_SIZE 				   symbols or a from shared object's RRS */
name|int
name|aux
decl_stmt|;
comment|/* Auxiliary type information conveyed in 				   the `n_other' field of nlists */
comment|/* The offset into one of the RRS tables, -1 if not used */
name|long
name|jmpslot_offset
decl_stmt|;
name|long
name|gotslot_offset
decl_stmt|;
name|long
name|flags
decl_stmt|;
define|#
directive|define
name|GS_DEFINED
value|0x1
comment|/* Symbol has definition (notyetused)*/
define|#
directive|define
name|GS_REFERENCED
value|0x2
comment|/* Symbol is referred to by something 					   interesting */
define|#
directive|define
name|GS_TRACE
value|0x4
comment|/* Symbol will be traced */
define|#
directive|define
name|GS_HASJMPSLOT
value|0x8
comment|/*				 */
define|#
directive|define
name|GS_HASGOTSLOT
value|0x10
comment|/* Some state bits concerning    */
define|#
directive|define
name|GS_CPYRELOCRESERVED
value|0x20
comment|/* entries in GOT and PLT tables */
define|#
directive|define
name|GS_CPYRELOCCLAIMED
value|0x40
comment|/*				 */
define|#
directive|define
name|GS_WEAK
value|0x80
comment|/* Symbol is weakly defined */
block|}
name|symbol
typedef|;
end_typedef

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
comment|/* The symbol hash table: a vector of SYMTABSIZE pointers to struct glosym. */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|symtab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FOR_EACH_SYMBOL
parameter_list|(
name|i
parameter_list|,
name|sp
parameter_list|)
value|{					\ 	int i;							\ 	for (i = 0; i< SYMTABSIZE; i++) {				\ 		register symbol *sp;				\ 		for (sp = symtab[i]; sp; sp = sp->link)
end_define

begin_define
define|#
directive|define
name|END_EACH_SYMBOL
value|}}
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

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|got_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol __GLOBAL_OFFSET_TABLE_ */
end_comment

begin_decl_stmt
specifier|extern
name|symbol
modifier|*
name|dynamic_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the symbol __DYNAMIC */
end_comment

begin_comment
comment|/*  * Each input file, and each library member ("subfile") being loaded, has a  * `file_entry' structure for it.  *  * For files specified by command args, these are contained in the vector which  * `file_table' points to.  *  * For library members, they are dynamically allocated, and chained through the  * `chain' field. The chain is found in the `subfiles' field of the  * `file_entry'. The `file_entry' objects for the members have `superfile'  * fields pointing to the one for the library.  */
end_comment

begin_struct
struct|struct
name|file_entry
block|{
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Name of this file.  */
comment|/* 	 * Name to use for the symbol giving address of text start Usually 	 * the same as filename, but for a file spec'd with -l this is the -l 	 * switch itself rather than the filename. 	 */
name|char
modifier|*
name|local_sym_name
decl_stmt|;
name|struct
name|exec
name|header
decl_stmt|;
comment|/* The file's a.out header.  */
name|localsymbol_t
modifier|*
name|symbols
decl_stmt|;
comment|/* Symbol table of the file. */
name|int
name|nsymbols
decl_stmt|;
comment|/* Number of symbols in above array. */
name|int
name|string_size
decl_stmt|;
comment|/* Size in bytes of string table. */
name|char
modifier|*
name|strings
decl_stmt|;
comment|/* Pointer to the string table when 					   in core, NULL otherwise */
name|int
name|strings_offset
decl_stmt|;
comment|/* Offset of string table, 					   (normally N_STROFF() + 4) */
comment|/* 	 * Next two used only if `relocatable_output' or if needed for 	 * output of undefined reference line numbers. 	 */
name|struct
name|relocation_info
modifier|*
name|textrel
decl_stmt|;
comment|/* Text relocations */
name|int
name|ntextrel
decl_stmt|;
comment|/* # of text relocations */
name|struct
name|relocation_info
modifier|*
name|datarel
decl_stmt|;
comment|/* Data relocations */
name|int
name|ndatarel
decl_stmt|;
comment|/* # of data relocations */
comment|/* 	 * Relation of this file's segments to the output file. 	 */
name|int
name|text_start_address
decl_stmt|;
comment|/* Start of this file's text segment 					   in the output file core image. */
name|int
name|data_start_address
decl_stmt|;
comment|/* Start of this file's data segment 					   in the output file core image. */
name|int
name|bss_start_address
decl_stmt|;
comment|/* Start of this file's bss segment 					   in the output file core image. */
name|struct
name|file_entry
modifier|*
name|subfiles
decl_stmt|;
comment|/* For a library, points to chain of 					   entries for the library members. */
name|struct
name|file_entry
modifier|*
name|superfile
decl_stmt|;
comment|/* For library member, points to the 					   library's own entry.  */
name|struct
name|file_entry
modifier|*
name|chain
decl_stmt|;
comment|/* For library member, points to next 					   entry for next member.  */
name|int
name|starting_offset
decl_stmt|;
comment|/* For a library member, offset of the 					   member within the archive. Zero for 					   files that are not library members.*/
name|int
name|total_size
decl_stmt|;
comment|/* Size of contents of this file, 					   if library member. */
ifdef|#
directive|ifdef
name|SUN_COMPAT
name|struct
name|file_entry
modifier|*
name|silly_archive
decl_stmt|;
comment|/* For shared libraries which have 					    a .sa companion */
endif|#
directive|endif
name|int
name|lib_major
decl_stmt|,
name|lib_minor
decl_stmt|;
comment|/* Version numbers of a shared object */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|E_IS_LIBRARY
value|1
comment|/* File is a an archive */
define|#
directive|define
name|E_HEADER_VALID
value|2
comment|/* File's header has been read */
define|#
directive|define
name|E_SEARCH_DIRS
value|4
comment|/* Search directories for file */
define|#
directive|define
name|E_SEARCH_DYNAMIC
value|8
comment|/* Search for shared libs allowed */
define|#
directive|define
name|E_JUST_SYMS
value|0x10
comment|/* File is used for incremental load */
define|#
directive|define
name|E_DYNAMIC
value|0x20
comment|/* File is a shared object */
define|#
directive|define
name|E_SCRAPPED
value|0x40
comment|/* Ignore this file */
define|#
directive|define
name|E_SYMBOLS_USED
value|0x80
comment|/* Symbols from this entry were used */
define|#
directive|define
name|E_SECONDCLASS
value|0x100
comment|/* Shared object is a subsidiary */
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * Runtime Relocation Section (RRS).  * This describes the data structures that go into the output text and data  * segments to support the run-time linker. The RRS can be empty (plain old  * static linking), or can just exist of GOT and PLT entries (in case of  * statically linked PIC code).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_section_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What's in the RRS section */
end_comment

begin_define
define|#
directive|define
name|RRS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RRS_PARTIAL
value|1
end_define

begin_define
define|#
directive|define
name|RRS_FULL
value|2
end_define

begin_decl_stmt
specifier|extern
name|int
name|rrs_text_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of RRS text additions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_text_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of above */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_data_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of RRS data additions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rrs_data_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of above */
end_comment

begin_comment
comment|/* Version number to put in __DYNAMIC (set by -V) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|soversion
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_SOVERSION
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_SOVERSION
value|LD_VERSION_BSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|pc_relocation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current PC reloc value */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|number_of_shobjs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of shared objects linked in */
end_comment

begin_comment
comment|/* Current link mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|link_mode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DYNAMIC
value|1
end_define

begin_comment
comment|/* Consider shared libraries */
end_comment

begin_define
define|#
directive|define
name|SYMBOLIC
value|2
end_define

begin_comment
comment|/* Force symbolic resolution */
end_comment

begin_define
define|#
directive|define
name|FORCEARCHIVE
value|4
end_define

begin_comment
comment|/* Force inclusion of all members 					   of archives */
end_comment

begin_define
define|#
directive|define
name|SHAREABLE
value|8
end_define

begin_comment
comment|/* Build a shared object */
end_comment

begin_define
define|#
directive|define
name|SILLYARCHIVE
value|16
end_define

begin_comment
comment|/* Process .sa companions, if any */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outstream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exec
name|outheader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output file header. */
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
name|oldmagic
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|read_header
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_symbols
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_strings
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_entry_relocation
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enter_file_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_file_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_element_prefixed_p
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|text_offset
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_open
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|each_file
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|each_full_file
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|check_each_file
name|__P
argument_list|(
operator|(
name|unsigned
name|long
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mywrite
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|padfile
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In warnings.c: */
end_comment

begin_decl_stmt
name|void
name|perror_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|perror_file
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_symbols
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|get_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prline_file_name
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_warnings
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In etc.c: */
end_comment

begin_decl_stmt
name|void
modifier|*
name|xmalloc
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|xrealloc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|concat
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In symbol.c: */
end_comment

begin_decl_stmt
name|void
name|symtab_init
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|symbol
modifier|*
name|getsym
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|getsym_soft
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In lib.c: */
end_comment

begin_decl_stmt
name|void
name|search_library
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_shared_object
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|findlib
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In shlib.c: */
end_comment

begin_decl_stmt
name|char
modifier|*
name|findshlib
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|find_lib_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|search_lib_dir
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_search_dir
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_search_path
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|std_search_path
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getdewey
name|__P
argument_list|(
operator|(
name|int
index|[]
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmpndewey
name|__P
argument_list|(
operator|(
name|int
index|[]
operator|,
name|int
operator|,
name|int
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In rrs.c: */
end_comment

begin_decl_stmt
name|void
name|init_rrs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rrs_add_shobj
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_segment_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_jmpslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|localsymbol_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|alloc_rrs_cpy_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|claim_rrs_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_jmpslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|localsymbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|claim_rrs_internal_gotslot
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|localsymbol
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|claim_rrs_cpy_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|claim_rrs_segment_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|file_entry
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|consider_rrs_section_lengths
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|relocate_rrs_addresses
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_rrs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In<md>.c */
end_comment

begin_decl_stmt
name|void
name|md_init_header
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|md_get_addend
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_relocate
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|long
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_fix_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|md_make_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_gotreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_copyreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_set_breakpoint
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SWAP
end_ifdef

begin_decl_stmt
name|void
name|md_swapin_exec_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_exec_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapin_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In xbits.c: */
end_comment

begin_decl_stmt
name|void
name|swap_longs
name|__P
argument_list|(
operator|(
name|long
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_symbols
name|__P
argument_list|(
operator|(
expr|struct
name|nlist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_zsymbols
name|__P
argument_list|(
operator|(
expr|struct
name|nzlist
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_ranlib_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|ranlib
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap__dynamic
name|__P
argument_list|(
operator|(
expr|struct
name|link_dynamic
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_section_dispatch_table
name|__P
argument_list|(
operator|(
expr|struct
name|section_dispatch_table
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_so_debug
name|__P
argument_list|(
operator|(
expr|struct
name|so_debug
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapin_sod
name|__P
argument_list|(
operator|(
expr|struct
name|sod
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapout_sod
name|__P
argument_list|(
operator|(
expr|struct
name|sod
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swapout_fshash
name|__P
argument_list|(
operator|(
expr|struct
name|fshash
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

