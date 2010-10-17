begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"emul.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|criself_bfd_name
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|criself_bfd_name
parameter_list|()
block|{
name|abort
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_define
define|#
directive|define
name|emul_bfd_name
value|criself_bfd_name
end_define

begin_define
define|#
directive|define
name|emul_format
value|&elf_format_ops
end_define

begin_define
define|#
directive|define
name|emul_name
value|"criself"
end_define

begin_define
define|#
directive|define
name|emul_struct_name
value|criself
end_define

begin_define
define|#
directive|define
name|emul_default_endian
value|0
end_define

begin_include
include|#
directive|include
file|"emul-target.h"
end_include

end_unit

