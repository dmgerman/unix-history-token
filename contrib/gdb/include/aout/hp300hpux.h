begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Special version of<a.out.h> for use under hp-ux.    Copyright (C) 1988,1993 Free Software Foundation, Inc. */
end_comment

begin_struct
struct|struct
name|hp300hpux_exec_bytes
block|{
name|unsigned
name|char
name|e_info
index|[
literal|4
index|]
decl_stmt|;
comment|/* a_machtype/a_magic */
name|unsigned
name|char
name|e_spare1
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_spare2
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_text
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of text, in bytes */
name|unsigned
name|char
name|e_data
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of data, in bytes */
name|unsigned
name|char
name|e_bss
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of uninitialized data area , in bytes */
name|unsigned
name|char
name|e_trsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of relocation info for text, in bytes*/
name|unsigned
name|char
name|e_drsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* length of relocation info for data, in bytes*/
name|unsigned
name|char
name|e_passize
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = pascal interface size */
name|unsigned
name|char
name|e_syms
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = symbol table size */
name|unsigned
name|char
name|e_spare5
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = debug name table size */
name|unsigned
name|char
name|e_entry
index|[
literal|4
index|]
decl_stmt|;
comment|/* start address */
name|unsigned
name|char
name|e_spare6
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = source line table size */
name|unsigned
name|char
name|e_supsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* HP = value table size */
name|unsigned
name|char
name|e_drelocs
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_extension
index|[
literal|4
index|]
decl_stmt|;
comment|/* file offset of extension */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXEC_BYTES_SIZE
value|64
end_define

begin_struct
struct|struct
name|hp300hpux_nlist_bytes
block|{
name|unsigned
name|char
name|e_value
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_type
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|e_length
index|[
literal|1
index|]
decl_stmt|;
comment|/* length of ascii symbol name */
name|unsigned
name|char
name|e_almod
index|[
literal|2
index|]
decl_stmt|;
comment|/* alignment mod */
name|unsigned
name|char
name|e_shlib
index|[
literal|2
index|]
decl_stmt|;
comment|/* info about dynamic linking */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXTERNAL_NLIST_SIZE
value|10
end_define

begin_struct
struct|struct
name|hp300hpux_reloc
block|{
name|unsigned
name|char
name|r_address
index|[
literal|4
index|]
decl_stmt|;
comment|/* offset of of data to relocate */
name|unsigned
name|char
name|r_index
index|[
literal|2
index|]
decl_stmt|;
comment|/* symbol table index of symbol         */
name|unsigned
name|char
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* relocation type                      */
name|unsigned
name|char
name|r_length
index|[
literal|1
index|]
decl_stmt|;
comment|/* length of item to reloc              */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hp300hpux_header_extension
block|{
name|unsigned
name|char
name|e_syms
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|unique_headers
index|[
literal|12
operator|*
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|e_header
index|[
literal|2
index|]
decl_stmt|;
comment|/* type of header */
name|unsigned
name|char
name|e_version
index|[
literal|2
index|]
decl_stmt|;
comment|/* version        */
name|unsigned
name|char
name|e_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* bytes following*/
name|unsigned
name|char
name|e_extension
index|[
literal|4
index|]
decl_stmt|;
comment|/* file offset of next extension */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXTERNAL_EXTENSION_HEADER_SIZE
value|(16*4)
end_define

begin_comment
comment|/* hpux separates object files (0x106) and impure executables (0x107)  */
end_comment

begin_comment
comment|/* but the bfd code does not distinguish between them. Since we want to*/
end_comment

begin_comment
comment|/* read hpux .o files, we add an special define and use it below in    */
end_comment

begin_comment
comment|/* offset and address calculations.                                    */
end_comment

begin_define
define|#
directive|define
name|HPUX_DOT_O_MAGIC
value|0x106
end_define

begin_define
define|#
directive|define
name|OMAGIC
value|0x107
end_define

begin_comment
comment|/* object file or impure executable.  */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0x108
end_define

begin_comment
comment|/* Code indicating pure executable.   */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0x10B
end_define

begin_comment
comment|/* demand-paged executable.           */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* libaout.h only uses the lower 8 bits */
end_comment

begin_define
define|#
directive|define
name|HP98x6_ID
value|0x20A
end_define

begin_define
define|#
directive|define
name|HP9000S200_ID
value|0x20C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HP98x6_ID
value|0x0A
end_define

begin_define
define|#
directive|define
name|HP9000S200_ID
value|0x0C
end_define

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|((_N_BADMAG (x)) || (_N_BADMACH (x)))
end_define

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|((N_MAGIC(x)==OMAGIC || N_MAGIC(x)==HPUX_DOT_O_MAGIC) ? \         (N_TXTADDR(x)+N_TXTSIZE(x)) \      :  (N_SEGSIZE(x) + ((N_TXTADDR(x)+N_TXTSIZE(x)-1)& ~(N_SEGSIZE(x)-1))))
end_define

begin_define
define|#
directive|define
name|_N_BADMACH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((N_MACHTYPE (x)) != HP9000S200_ID)&&                                 \  ((N_MACHTYPE (x)) != HP98x6_ID))
end_define

begin_define
define|#
directive|define
name|_N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(N_MAGIC(x) != HPUX_DOT_O_MAGIC \&& N_MAGIC(x) != OMAGIC		\&& N_MAGIC(x) != NMAGIC		\&& N_MAGIC(x) != ZMAGIC )
end_define

begin_undef
undef|#
directive|undef
name|_N_HDROFF
end_undef

begin_define
define|#
directive|define
name|_N_HDROFF
parameter_list|(
name|x
parameter_list|)
value|(SEGMENT_SIZE - (sizeof (struct exec)))
end_define

begin_undef
undef|#
directive|undef
name|N_DATOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_PASOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_SYMOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_SUPOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_TRELOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_DRELOFF
end_undef

begin_undef
undef|#
directive|undef
name|N_STROFF
end_undef

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TXTOFF(x) + N_TXTSIZE(x) )
end_define

begin_define
define|#
directive|define
name|N_PASOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DATOFF(x) + (x).a_data)
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|( N_PASOFF(x)
comment|/* + (x).a_passize*/
value|)
end_define

begin_define
define|#
directive|define
name|N_SUPOFF
parameter_list|(
name|x
parameter_list|)
value|( N_SYMOFF(x) + (x).a_syms )
end_define

begin_define
define|#
directive|define
name|N_TRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_SUPOFF(x)
comment|/* + 0 (x).a_supsize*/
value|)
end_define

begin_define
define|#
directive|define
name|N_DRELOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TRELOFF(x) + (x).a_trsize )
end_define

begin_define
define|#
directive|define
name|N_EXTHOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DRELOFF(x)
comment|/*  + 0 (x).a_drsize */
value|)
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|( 0
comment|/* no string table */
value|)
end_define

begin_comment
comment|/* use these when the file has gnu symbol tables */
end_comment

begin_define
define|#
directive|define
name|N_GNU_TRELOFF
parameter_list|(
name|x
parameter_list|)
value|(N_DATOFF(x) + (x).a_data)
end_define

begin_define
define|#
directive|define
name|N_GNU_DRELOFF
parameter_list|(
name|x
parameter_list|)
value|(N_GNU_TRELOFF(x) + (x).a_trsize)
end_define

begin_define
define|#
directive|define
name|N_GNU_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|(N_GNU_DRELOFF(x) + (x).a_drsize)
end_define

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0
end_define

begin_undef
undef|#
directive|undef
name|N_SHARED_LIB
end_undef

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|( 0
comment|/* no shared libraries */
value|)
end_define

end_unit

