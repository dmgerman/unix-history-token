begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright Massachusetts Institute of Technology 1985 */
end_comment

begin_comment
comment|/* dbm database, mapping color names (strings) to RGB values */
end_comment

begin_comment
comment|/* $Header: rgb.h,v 10.6 86/02/01 15:17:17 tony Rel $ */
end_comment

begin_define
define|#
directive|define
name|RGB_DB
value|"/usr/lib/rgb"
end_define

begin_typedef
typedef|typedef
struct|struct
name|_rgb
block|{
name|unsigned
name|short
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|;
block|}
name|RGB
typedef|;
end_typedef

end_unit

