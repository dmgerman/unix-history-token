begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1985, Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* util.c		Various utilities  *  *	SoundBell	Generate audible bell  *	SetKeyClick	Control key click  *	SetAutoRepeat	Control auto repeat  *	SetLockLED	Control Lock LED  *	SetVideo	Disable/enable video  *	QueryShape	Determine shapes  *	ResolveColors	does nothing  *	StoreColors	does nothing  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<vaxuba/qvioctl.h>
end_include

begin_include
include|#
directive|include
file|"ddxqvss.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|vsdev
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LK_REPEAT_ON
value|0xe3
end_define

begin_comment
comment|/* enable autorepeat across kbd */
end_comment

begin_define
define|#
directive|define
name|LK_REPEAT_OFF
value|0xe1
end_define

begin_comment
comment|/* diable autorepeat across kbd */
end_comment

begin_define
define|#
directive|define
name|LK_ENABLE_CLICK
value|0x1b
end_define

begin_comment
comment|/* enable keyclick / set volume	*/
end_comment

begin_define
define|#
directive|define
name|LK_DISABLE_CLICK
value|0x99
end_define

begin_comment
comment|/* disable keyclick entirely	*/
end_comment

begin_define
define|#
directive|define
name|LK_ENABLE_BELL
value|0x23
end_define

begin_comment
comment|/* enable bell / set volume 	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LK_RING_BELL
end_ifndef

begin_comment
comment|/* can go away after 1.2 is out */
end_comment

begin_define
define|#
directive|define
name|LK_RING_BELL
value|0xa7
end_define

begin_comment
comment|/* command to ring a bell 	*/
end_comment

begin_define
define|#
directive|define
name|LED_1
value|0x81
end_define

begin_comment
comment|/* led 1 on the keyboard	*/
end_comment

begin_define
define|#
directive|define
name|LED_2
value|0x82
end_define

begin_comment
comment|/* led 2 on the keyboard	*/
end_comment

begin_define
define|#
directive|define
name|LED_3
value|0x84
end_define

begin_comment
comment|/* led 3 on the keyboard	*/
end_comment

begin_define
define|#
directive|define
name|LED_4
value|0x88
end_define

begin_comment
comment|/* led 4 on the keyboard	*/
end_comment

begin_define
define|#
directive|define
name|LK_LED_ENABLE
value|0x13
end_define

begin_comment
comment|/* turn on led			*/
end_comment

begin_define
define|#
directive|define
name|LK_LED_DISABLE
value|0x11
end_define

begin_comment
comment|/* turn off led			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sound bell, volume between 0 (quiet) and 7 (loud) */
end_comment

begin_macro
name|SoundBell
argument_list|(
argument|volume
argument_list|)
end_macro

begin_decl_stmt
name|int
name|volume
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|qv_kpcmd
name|ioc
decl_stmt|;
name|volume
operator|=
name|volume
operator|&
literal|7
expr_stmt|;
name|volume
operator|=
literal|7
operator|-
name|volume
expr_stmt|;
name|ioc
operator|.
name|nbytes
operator|=
literal|1
expr_stmt|;
name|ioc
operator|.
name|cmd
operator|=
name|LK_ENABLE_BELL
expr_stmt|;
name|ioc
operator|.
name|par
index|[
literal|0
index|]
operator|=
name|volume
expr_stmt|;
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
expr_stmt|;
name|ioc
operator|.
name|nbytes
operator|=
literal|0
expr_stmt|;
name|ioc
operator|.
name|cmd
operator|=
name|LK_RING_BELL
expr_stmt|;
return|return
operator|(
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Set key click, volume between -1 (default), 0 (off) and 8 (loud) */
end_comment

begin_macro
name|SetKeyClick
argument_list|(
argument|volume
argument_list|)
end_macro

begin_decl_stmt
name|int
name|volume
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|qv_kpcmd
name|ioc
decl_stmt|;
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|volume
operator|<
literal|0
condition|)
name|volume
operator|=
literal|6
expr_stmt|;
if|if
condition|(
name|volume
operator|>
literal|0
condition|)
block|{
name|volume
operator|-=
literal|1
expr_stmt|;
if|if
condition|(
name|volume
operator|>
literal|7
condition|)
name|volume
operator|=
literal|7
expr_stmt|;
name|volume
operator|=
literal|7
operator|-
name|volume
expr_stmt|;
name|ioc
operator|.
name|nbytes
operator|=
literal|1
expr_stmt|;
name|ioc
operator|.
name|cmd
operator|=
name|LK_ENABLE_CLICK
expr_stmt|;
name|ioc
operator|.
name|par
index|[
literal|0
index|]
operator|=
name|volume
expr_stmt|;
name|ret
operator|=
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|volume
operator|==
literal|0
condition|)
block|{
name|ioc
operator|.
name|nbytes
operator|=
literal|0
expr_stmt|;
name|ioc
operator|.
name|cmd
operator|=
name|LK_DISABLE_CLICK
expr_stmt|;
name|ret
operator|=
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Set autorepeat */
end_comment

begin_macro
name|SetAutoRepeat
argument_list|(
argument|onoff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|onoff
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|qv_kpcmd
name|ioc
decl_stmt|;
specifier|register
name|char
modifier|*
name|divsets
decl_stmt|;
name|divsets
operator|=
name|onoff
condition|?
operator|(
name|char
operator|*
operator|)
name|AutoRepeatLKMode
argument_list|()
else|:
operator|(
name|char
operator|*
operator|)
name|UpDownLKMode
argument_list|()
expr_stmt|;
name|ioc
operator|.
name|nbytes
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ioc
operator|.
name|cmd
operator|=
operator|*
name|divsets
operator|++
condition|)
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
expr_stmt|;
name|ioc
operator|.
name|cmd
operator|=
operator|(
operator|(
name|onoff
operator|>
literal|0
operator|)
condition|?
name|LK_REPEAT_ON
else|:
name|LK_REPEAT_OFF
operator|)
expr_stmt|;
return|return
operator|(
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
operator|)
return|;
block|}
end_block

begin_function
name|int
name|SetVideo
parameter_list|(
name|onoff
parameter_list|)
name|int
name|onoff
decl_stmt|;
block|{
return|return
operator|(
name|onoff
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_macro
name|QueryShape
argument_list|(
argument|shape
argument_list|,
argument|width
argument_list|,
argument|height
argument_list|)
end_macro

begin_decl_stmt
name|int
name|shape
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|width
decl_stmt|,
modifier|*
name|height
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|shape
condition|)
block|{
case|case
name|CursorShape
case|:
comment|/* braindamaged qvss cursor.... */
if|if
condition|(
operator|*
name|width
operator|>
literal|16
condition|)
operator|*
name|width
operator|=
literal|16
expr_stmt|;
if|if
condition|(
operator|*
name|height
operator|>
literal|16
condition|)
operator|*
name|height
operator|=
literal|16
expr_stmt|;
break|break;
case|case
name|TileShape
case|:
operator|*
name|width
operator|=
operator|*
name|height
operator|=
literal|16
expr_stmt|;
break|break;
block|}
block|}
end_block

begin_macro
name|SetLockLED
argument_list|(
argument|onoff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|onoff
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|qv_kpcmd
name|ioc
decl_stmt|;
if|if
condition|(
name|onoff
condition|)
name|ioc
operator|.
name|cmd
operator|=
name|LK_LED_ENABLE
expr_stmt|;
else|else
name|ioc
operator|.
name|cmd
operator|=
name|LK_LED_DISABLE
expr_stmt|;
name|ioc
operator|.
name|par
index|[
literal|0
index|]
operator|=
name|LED_3
expr_stmt|;
name|ioc
operator|.
name|par
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|ioc
operator|.
name|nbytes
operator|=
literal|1
expr_stmt|;
name|ioctl
argument_list|(
name|vsdev
argument_list|,
name|QIOCKPCMD
argument_list|,
operator|&
name|ioc
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_macro
name|ResolveColor
argument_list|(
argument|red
argument_list|,
argument|green
argument_list|,
argument|blue
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|short
modifier|*
name|red
decl_stmt|,
modifier|*
name|green
decl_stmt|,
modifier|*
name|blue
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|StoreColors
argument_list|(
argument|count
argument_list|,
argument|entries
argument_list|)
end_macro

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ColorDef
modifier|*
name|entries
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

