begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * linux/kernel/chr_drv/sound/adlib_card.c  *   * Detection routine for the AdLib card.  *   * (C) 1992  Hannu Savolainen (hsavolai@cs.helsinki.fi) See COPYING for further  * details. Should be distributed with this file.  */
end_comment

begin_include
include|#
directive|include
file|"sound_config.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIGURE_SOUNDCARD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_YM3812
argument_list|)
end_if

begin_function
name|long
name|attach_adlib_card
parameter_list|(
name|long
name|mem_start
parameter_list|,
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
if|if
condition|(
name|opl3_detect
argument_list|(
name|FM_MONO
argument_list|)
condition|)
block|{
name|mem_start
operator|=
name|opl3_init
argument_list|(
name|mem_start
argument_list|)
expr_stmt|;
block|}
return|return
name|mem_start
return|;
block|}
end_function

begin_function
name|int
name|probe_adlib
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
return|return
name|opl3_detect
argument_list|(
name|FM_MONO
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

