begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  drt0.c:     Static Constructor Initialization for Dynamically  *                    Linked Libraries  *  Author:           James Kempf  *  Created On:       Fri Dec 21 08:31:07 1990  *  Last Modified By: James Kempf  *  Last Modified On: Wed Apr 24 10:41:25 1991  *  Update Count:     46 */
end_comment

begin_comment
comment|/*This horrible, crufty hack is necessary because the people who */
end_comment

begin_comment
comment|/*  implemented PIC code didn't have enough time to change the   */
end_comment

begin_comment
comment|/*  linker to make it properly create relocatable files using    */
end_comment

begin_comment
comment|/*  the -r switch when PIC code was involved.                    */
end_comment

begin_include
include|#
directive|include
file|"init_main.c"
end_include

begin_comment
comment|/* That's right, .c */
end_comment

begin_include
include|#
directive|include
file|"init.c"
end_include

begin_define
define|#
directive|define
name|DYNAMIC_LIBS
end_define

begin_include
include|#
directive|include
file|"dynamic_lib.c"
end_include

end_unit

