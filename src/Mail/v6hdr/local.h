begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Declarations and constants specific to an installation.  * Unix Version 6.  */
end_comment

begin_define
define|#
directive|define
name|MAIL
value|"/bin/mail"
end_define

begin_comment
comment|/* Name of mail sender */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|"/usr/ucb/ex"
end_define

begin_comment
comment|/* Name of text editor */
end_comment

begin_define
define|#
directive|define
name|VISUAL
value|"/usr/ucb/vi"
end_define

begin_comment
comment|/* Name of display editor */
end_comment

begin_define
define|#
directive|define
name|HELPFILE
value|"/usr/lib/Mail.help"
end_define

begin_comment
comment|/* Name of casual help file */
end_comment

begin_define
define|#
directive|define
name|THELPFILE
value|"/usr/lib/Mail.help.~"
end_define

begin_comment
comment|/* Name of casual tilde help */
end_comment

begin_define
define|#
directive|define
name|UIDMASK
value|0377
end_define

begin_comment
comment|/* Significant uid bits */
end_comment

begin_define
define|#
directive|define
name|MASTER
value|"/usr/lib/Mail.rc"
end_define

begin_define
define|#
directive|define
name|stat
value|_stat
end_define

begin_comment
comment|/* Simulate version 7 */
end_comment

begin_define
define|#
directive|define
name|fstat
value|_fstat
end_define

begin_comment
comment|/* Simulate version 7 */
end_comment

begin_comment
comment|/*  * Machine dependent type declarations.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|flag_t
typedef|;
end_typedef

begin_comment
comment|/* flag arguments everywhere */
end_comment

end_unit

