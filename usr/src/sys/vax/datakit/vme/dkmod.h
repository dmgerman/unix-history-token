begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * one dkmodule per hardware interface to datakit  * a given hardware device == (major device, range of minor devices)  * channel 0 == (dev, lo)  * there are hi-lo channels  */
end_comment

begin_struct
struct|struct
name|dkmodule
block|{
name|unsigned
name|char
modifier|*
name|dkstate
decl_stmt|;
comment|/* open/closed status of channels */
name|queue_t
modifier|*
name|listnrq
decl_stmt|;
comment|/* channel to controller */
name|unsigned
name|short
name|dev
decl_stmt|;
comment|/* major device of datakit interface */
name|unsigned
name|short
name|lo
decl_stmt|,
name|hi
decl_stmt|;
comment|/* range of devs on this controller */
name|unsigned
name|short
name|type
decl_stmt|;
comment|/* type of listener */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|dkmodule
modifier|*
name|dkmodall
argument_list|()
decl_stmt|,
modifier|*
name|getdkmod
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * channel states  */
end_comment

begin_define
define|#
directive|define
name|DKCLOSED
value|0
end_define

begin_define
define|#
directive|define
name|DKRCLOSE
value|1
end_define

begin_comment
comment|/* remote hung up, local still around */
end_comment

begin_define
define|#
directive|define
name|DKLCLOSE
value|2
end_define

begin_comment
comment|/* closed locally, CMC hasn't acked yet */
end_comment

begin_define
define|#
directive|define
name|DKOPEN
value|3
end_define

begin_comment
comment|/* in use */
end_comment

begin_comment
comment|/*  * listener types  */
end_comment

begin_define
define|#
directive|define
name|CMCLD
value|'c'
end_define

begin_define
define|#
directive|define
name|UNIXPLD
value|'u'
end_define

begin_comment
comment|/*  * M_PRICTL messages contain  * one byte of subtype  * perhaps another byte of channel number  */
end_comment

begin_define
define|#
directive|define
name|DKMCLOSE
value|0x00
end_define

begin_comment
comment|/* this channel is closing */
end_comment

begin_define
define|#
directive|define
name|DKMXINIT
value|0x01
end_define

begin_comment
comment|/* re-init URP because of splice */
end_comment

begin_define
define|#
directive|define
name|DKMBUFFER
value|0x02
end_define

begin_comment
comment|/* ok to buffer in driver */
end_comment

end_unit

