begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is te-i386aix.h and is built from pieces of code from    Minh Tran-Le<TRANLE@INTELLICORP.COM> by rich@cygnus.com.  */
end_comment

begin_define
define|#
directive|define
name|TE_I386AIX
value|1
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/* Undefine REVERSE_SORT_RELOCS to keep the relocation entries sorted    in ascending vaddr.  */
end_comment

begin_undef
undef|#
directive|undef
name|REVERSE_SORT_RELOCS
end_undef

begin_comment
comment|/* Define KEEP_RELOC_INFO so that the strip reloc info flag F_RELFLG is    not used in the filehdr for COFF output.  */
end_comment

begin_define
define|#
directive|define
name|KEEP_RELOC_INFO
end_define

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 79  * End:  */
end_comment

begin_comment
comment|/* end of te-i386aix.h */
end_comment

end_unit

