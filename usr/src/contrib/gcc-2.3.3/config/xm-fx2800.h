begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Alliant FX/2800 running Concentrix 2.x. */
end_comment

begin_include
include|#
directive|include
file|"xm-i860.h"
end_include

begin_comment
comment|/*  * vfprintf is not present prior to Concentrix 2.2. Unfortunately, there  * does not seem to be a cpp symbol that identifies OS revision. Undefine  * the following if running 2.1 or older.  *  -- hyc@hanauma.jpl.nasa.gov  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

end_unit

