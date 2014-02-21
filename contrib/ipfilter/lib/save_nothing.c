begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"ipmon.h"
end_include

begin_decl_stmt
specifier|static
name|void
modifier|*
name|nothing_parse
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|nothing_destroy
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|nothing_send
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|ipmon_msg_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|nothing_opts_s
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|raw
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
block|}
name|nothing_opts_t
typedef|;
end_typedef

begin_decl_stmt
name|ipmon_saver_t
name|nothingsaver
init|=
block|{
literal|"nothing"
block|,
name|nothing_destroy
block|,
name|NULL
block|,
comment|/* dup */
name|NULL
block|,
comment|/* match */
name|nothing_parse
block|,
name|NULL
block|,
comment|/* print */
name|nothing_send
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
modifier|*
name|nothing_parse
parameter_list|(
name|char
modifier|*
modifier|*
name|strings
parameter_list|)
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
if|#
directive|if
literal|0
block|strings = strings;
comment|/* gcc -Wextra */
endif|#
directive|endif
name|ctx
operator|=
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ctx
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|nothing_destroy
parameter_list|(
name|ctx
parameter_list|)
name|void
modifier|*
name|ctx
decl_stmt|;
block|{
name|free
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|nothing_send
parameter_list|(
name|ctx
parameter_list|,
name|msg
parameter_list|)
name|void
modifier|*
name|ctx
decl_stmt|;
name|ipmon_msg_t
modifier|*
name|msg
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|ctx = ctx;
comment|/* gcc -Wextra */
block|msg = msg;
comment|/* gcc -Wextra */
endif|#
directive|endif
comment|/* 	 * Do nothing 	 */
return|return
literal|0
return|;
block|}
end_function

end_unit

