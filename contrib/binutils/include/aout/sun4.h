begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPARC-specific values for a.out files */
end_comment

begin_comment
comment|/* Some systems, e.g., AIX, may have defined this in header files already    included.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_PAGE_SIZE
end_undef

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x2000
end_define

begin_comment
comment|/* 8K.  aka NBPG in<sys/param.h> */
end_comment

begin_comment
comment|/* Note that some SPARCs have 4K pages, some 8K, some others.  */
end_comment

begin_define
define|#
directive|define
name|SEG_SIZE_SPARC
value|TARGET_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|SEG_SIZE_SUN3
value|0x20000
end_define

begin_comment
comment|/* Resolution of r/w protection hw */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|TARGET_PAGE_SIZE
end_define

begin_comment
comment|/* Location 0 is not accessible */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_comment
comment|/* Non-default definitions of the accessor macros... */
end_comment

begin_comment
comment|/* Segment size varies on Sun-3 versus Sun-4.  */
end_comment

begin_define
define|#
directive|define
name|N_SEGSIZE
parameter_list|(
name|x
parameter_list|)
value|(N_MACHTYPE(x) == M_SPARC?	SEG_SIZE_SPARC:	\ 			 N_MACHTYPE(x) == M_68020?	SEG_SIZE_SUN3:	\
comment|/* Guess? */
value|TARGET_PAGE_SIZE)
end_define

begin_comment
comment|/* Virtual Address of text segment from the a.out file.  For OMAGIC,    (almost always "unlinked .o's" these days), should be zero.    Sun added a kludge so that shared libraries linked ZMAGIC get    an address of zero if a_entry (!!!) is lower than the otherwise    expected text address.  These kludges have gotta go!    For linked files, should reflect reality if we know it.  */
end_comment

begin_comment
comment|/* This differs from the version in aout64.h (which we override by defining    it here) only for NMAGIC (we return TEXT_START_ADDR+EXEC_BYTES_SIZE;    they return 0).  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_MAGIC(x)==OMAGIC? 0 \      : (N_MAGIC(x) == ZMAGIC&& (x).a_entry< TEXT_START_ADDR)? 0 \      : TEXT_START_ADDR+EXEC_BYTES_SIZE)
end_define

begin_comment
comment|/* When a file is linked against a shared library on SunOS 4, the    dynamic bit in the exec header is set, and the first symbol in the    symbol table is __DYNAMIC.  Its value is the address of the    following structure.  */
end_comment

begin_struct
struct|struct
name|external_sun4_dynamic
block|{
comment|/* The version number of the structure.  SunOS 4.1.x creates files      with version number 3, which is what this structure is based on.      According to gdb, version 2 is similar.  I believe that version 2      used a different type of procedure linkage table, and there may      have been other differences.  */
name|bfd_byte
name|ld_version
index|[
literal|4
index|]
decl_stmt|;
comment|/* The virtual address of a 28 byte structure used in debugging.      The contents are filled in at run time by ld.so.  */
name|bfd_byte
name|ldd
index|[
literal|4
index|]
decl_stmt|;
comment|/* The virtual address of another structure with information about      how to relocate the executable at run time.  */
name|bfd_byte
name|ld
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The size of the debugging structure pointed to by the debugger    field of __DYNAMIC.  */
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_SUN4_DYNAMIC_DEBUGGER_SIZE
value|(24)
end_define

begin_comment
comment|/* The structure pointed to by the linker field of __DYNAMIC.  As far    as I can tell, most of the addresses in this structure are offsets    within the file, but some are actually virtual addresses.  */
end_comment

begin_struct
struct|struct
name|internal_sun4_dynamic_link
block|{
comment|/* Linked list of loaded objects.  This is filled in at runtime by      ld.so and probably by dlopen.  */
name|unsigned
name|long
name|ld_loaded
decl_stmt|;
comment|/* The address of the list of names of shared objects which must be      included at runtime.  Each entry in the list is 16 bytes: the 4      byte address of the string naming the object (e.g., for -lc this      is "c"); 4 bytes of flags--the high bit is whether to search for      the object using the library path; the 2 byte major version      number; the 2 byte minor version number; the 4 byte address of      the next entry in the list (zero if this is the last entry).  The      version numbers seem to only be non-zero when doing library      searching.  */
name|unsigned
name|long
name|ld_need
decl_stmt|;
comment|/* The address of the path to search for the shared objects which      must be included.  This points to a string in PATH format which      is generated from the -L arguments to the linker.  According to      the man page, ld.so implicitly adds ${LD_LIBRARY_PATH} to the      beginning of this string and /lib:/usr/lib:/usr/local/lib to the      end.  The string is terminated by a null byte.  This field is      zero if there is no additional path.  */
name|unsigned
name|long
name|ld_rules
decl_stmt|;
comment|/* The address of the global offset table.  This appears to be a      virtual address, not a file offset.  The first entry in the      global offset table seems to be the virtual address of the      sun4_dynamic structure (the same value as the __DYNAMIC symbol).      The global offset table is used for PIC code to hold the      addresses of variables.  A dynamically linked file which does not      itself contain PIC code has a four byte global offset table.  */
name|unsigned
name|long
name|ld_got
decl_stmt|;
comment|/* The address of the procedure linkage table.  This appears to be a      virtual address, not a file offset.       On a SPARC, the table is composed of 12 byte entries, each of      which consists of three instructions.  The first entry is          sethi %hi(0),%g1 	 jmp %g1 	 nop      These instructions are changed by ld.so into a jump directly into      ld.so itself.  Each subsequent entry is          save %sp, -96, %sp 	 call<address of first entry in procedure linkage table><reloc_number | 0x01000000>      The reloc_number is the number of the reloc to use to resolve      this entry.  The reloc will be a JMP_SLOT reloc against some      symbol that is not defined in this object file but should be      defined in a shared object (if it is not, ld.so will report a      runtime error and exit).  The constant 0x010000000 turns the      reloc number into a sethi of %g0, which does nothing since %g0 is      hardwired to zero.       When one of these entries is executed, it winds up calling into      ld.so.  ld.so looks at the reloc number, available via the return      address, to determine which entry this is.  It then looks at the      reloc and patches up the entry in the table into a sethi and jmp      to the real address followed by a nop.  This means that the reloc      lookup only has to happen once, and it also means that the      relocation only needs to be done if the function is actually      called.  The relocation is expensive because ld.so must look up      the symbol by name.       The size of the procedure linkage table is given by the ld_plt_sz      field.  */
name|unsigned
name|long
name|ld_plt
decl_stmt|;
comment|/* The address of the relocs.  These are in the same format as      ordinary relocs.  Symbol index numbers refer to the symbols      pointed to by ld_stab.  I think the only way to determine the      number of relocs is to assume that all the bytes from ld_rel to      ld_hash contain reloc entries.  */
name|unsigned
name|long
name|ld_rel
decl_stmt|;
comment|/* The address of a hash table of symbols.  The hash table has      roughly the same number of entries as there are dynamic symbols;      I think the only way to get the exact size is to assume that      every byte from ld_hash to ld_stab is devoted to the hash table.       Each entry in the hash table is eight bytes.  The first four      bytes are a symbol index into the dynamic symbols.  The second      four bytes are the index of the next hash table entry in the      bucket.  The ld_buckets field gives the number of buckets, say B.      The first B entries in the hash table each start a bucket which      is chained through the second four bytes of each entry.  A value      of zero ends the chain.       The hash function is simply          h = 0;          while (*string != '\0') 	   h = (h<< 1) + *string++; 	 h&= 0x7fffffff;       To look up a symbol, compute the hash value of the name.  Take      the modulos of hash value and the number of buckets.  Start at      that entry in the hash table.  See if the symbol (from the first      four bytes of the hash table entry) has the name you are looking      for.  If not, use the chain field (the second four bytes of the      hash table entry) to move on to the next entry in this bucket.      If the chain field is zero you have reached the end of the      bucket, and the symbol is not in the hash table.  */
name|unsigned
name|long
name|ld_hash
decl_stmt|;
comment|/* The address of the symbol table.  This is a list of      external_nlist structures.  The string indices are relative to      the ld_symbols field.  I think the only way to determine the      number of symbols is to assume that all the bytes between ld_stab      and ld_symbols are external_nlist structures.  */
name|unsigned
name|long
name|ld_stab
decl_stmt|;
comment|/* I don't know what this is for.  It seems to always be zero.  */
name|unsigned
name|long
name|ld_stab_hash
decl_stmt|;
comment|/* The number of buckets in the hash table.  */
name|unsigned
name|long
name|ld_buckets
decl_stmt|;
comment|/* The address of the symbol string table.  The first string in this      string table need not be the empty string.  */
name|unsigned
name|long
name|ld_symbols
decl_stmt|;
comment|/* The size in bytes of the symbol string table.  */
name|unsigned
name|long
name|ld_symb_size
decl_stmt|;
comment|/* The size in bytes of the text segment.  */
name|unsigned
name|long
name|ld_text
decl_stmt|;
comment|/* The size in bytes of the procedure linkage table.  */
name|unsigned
name|long
name|ld_plt_sz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The external form of the structure.  */
end_comment

begin_struct
struct|struct
name|external_sun4_dynamic_link
block|{
name|bfd_byte
name|ld_loaded
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_need
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_rules
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_got
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_plt
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_rel
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_hash
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_stab
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_stab_hash
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_buckets
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_symbols
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_symb_size
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_text
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|ld_plt_sz
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

