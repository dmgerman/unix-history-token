begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Target environment for FreeBSD.  It is the same as the generic  * target, except it arranges to suppress the use of "/" as a comment  * character.  Some code in the FreeBSD kernel uses "/" to mean  * division.  (What a concept.)  */
end_comment

begin_define
define|#
directive|define
name|TE_FreeBSD
value|1
end_define

begin_include
include|#
directive|include
file|"te-generic.h"
end_include

end_unit

