begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%M%	%I%	%E%	*/
end_comment

begin_comment
comment|/*  * Header prepended to each a.out file.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* size of text segment */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* size of initialized data */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* size of symbol table */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* size of text relocation */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* size of data relocation */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* entry point */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_comment
comment|/*  * Macros which take exec structures as arguments and tell whether  * the file has a reasonable magic number or offsets to text|symbols|strings.  */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x).a_magic)!=OMAGIC&& ((x).a_magic)!=NMAGIC&& ((x).a_magic)!=ZMAGIC)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|((x).a_magic==ZMAGIC ? 1024 : sizeof (struct exec))
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_TXTOFF(x) + (x).a_text+(x).a_data + (x).a_trsize+(x).a_drsize)
end_define

begin_include
include|#
directive|include
file|<a.out.h>
end_include

end_unit

