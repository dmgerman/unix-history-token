begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   various arguments for bib and listrefs processors */
end_comment

begin_comment
comment|/* constants */
end_comment

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|err
value|-1
end_define

begin_define
define|#
directive|define
name|REFSIZE
value|1024
end_define

begin_comment
comment|/* maximum size of reference string    */
end_comment

begin_comment
comment|/* reference citation marker genrated in pass 1 */
end_comment

begin_define
define|#
directive|define
name|CITEMARK
value|(char) 02
end_define

begin_define
define|#
directive|define
name|CITEEND
value|(char) 03
end_define

begin_comment
comment|/* file names */
end_comment

begin_comment
comment|/* output of invert, input file for references */
end_comment

begin_define
define|#
directive|define
name|INDXFILE
value|"INDEX"
end_define

begin_comment
comment|/* pass1 reference collection file */
end_comment

begin_define
define|#
directive|define
name|TMPREFFILE
value|"/usr/tmp/bibrXXXXXX"
end_define

begin_comment
comment|/* pass2 text collection file */
end_comment

begin_define
define|#
directive|define
name|TMPTEXTFILE
value|"/usr/tmp/bibpXXXXXX"
end_define

begin_comment
comment|/* temp file used in invert */
end_comment

begin_define
define|#
directive|define
name|INVTEMPFILE
value|"/usr/tmp/invertXXXXXX"
end_define

begin_comment
comment|/* common words */
end_comment

begin_define
define|#
directive|define
name|COMFILE
value|"/usr/lib/bmac/common"
end_define

begin_comment
comment|/* default system dictionary */
end_comment

begin_define
define|#
directive|define
name|SYSINDEX
value|"/usr/dict/papers/INDEX"
end_define

begin_comment
comment|/* where macro libraries live */
end_comment

begin_define
define|#
directive|define
name|BMACLIB
value|"/usr/lib/bmac"
end_define

begin_comment
comment|/* default style of references */
end_comment

begin_define
define|#
directive|define
name|DEFSTYLE
value|"/usr/lib/bmac/bib.stdsn"
end_define

begin_comment
comment|/* size limits */
end_comment

begin_comment
comment|/* maximum number of characters in common file */
end_comment

begin_define
define|#
directive|define
name|MAXCOMM
value|300
end_define

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

