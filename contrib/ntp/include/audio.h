begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file for audio drivers  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_define
define|#
directive|define
name|AUDIO_BUFSIZ
value|160
end_define

begin_comment
comment|/* codec buffer size (Solaris only) */
end_comment

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
name|int
name|audio_init
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|audio_gain
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|audio_show
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

