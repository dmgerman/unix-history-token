begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Declarations for lsdev(8).  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/devconf.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|devtypes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device type array */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_config
parameter_list|(
name|struct
name|devconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-specific print routine */
end_comment

begin_function_decl
specifier|extern
name|void
name|hprint_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-specific header printer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|findtype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get device type by name */
end_comment

end_unit

