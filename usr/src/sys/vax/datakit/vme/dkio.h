begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Datakit ioctls  */
end_comment

begin_define
define|#
directive|define
name|DIOCLHN
value|(('d'<<8)|32)
end_define

begin_comment
comment|/* announce mgr channel */
end_comment

begin_define
define|#
directive|define
name|DIOCHUP
value|(('d'<<8)|33)
end_define

begin_comment
comment|/* tell ctlr to reinitialize */
end_comment

begin_define
define|#
directive|define
name|DIOCSTREAM
value|(('d'<<8)|34)
end_define

begin_comment
comment|/* no input delimiters */
end_comment

begin_define
define|#
directive|define
name|DIOCRECORD
value|(('d'<<8)|35)
end_define

begin_comment
comment|/* input delimiters */
end_comment

begin_define
define|#
directive|define
name|DIOCCHAN
value|(('d'<<8)|38)
end_define

begin_comment
comment|/* suggest channel # */
end_comment

begin_define
define|#
directive|define
name|DIOCSTOP
value|(('d'<<8)|39)
end_define

begin_comment
comment|/* delay input for cmcld */
end_comment

begin_define
define|#
directive|define
name|DIOCSTART
value|(('d'<<8)|40)
end_define

begin_comment
comment|/* restart input for cmcld */
end_comment

begin_define
define|#
directive|define
name|DIOCNXCL
value|(('d'<<8)|41)
end_define

begin_comment
comment|/* turn off exclusive use */
end_comment

begin_define
define|#
directive|define
name|DIOCXWIN
value|(('d'<<8)|42)
end_define

begin_comment
comment|/* set xmtr window sizes */
end_comment

begin_define
define|#
directive|define
name|DIOCSCTL
value|(('d'<<8)|43)
end_define

begin_comment
comment|/* send control character */
end_comment

begin_define
define|#
directive|define
name|DIOCRCTL
value|(('d'<<8)|44)
end_define

begin_comment
comment|/* receive stored control character */
end_comment

begin_define
define|#
directive|define
name|KIOCISURP
value|(('k'<<8)|1)
end_define

begin_comment
comment|/* is URP already turned on? */
end_comment

begin_define
define|#
directive|define
name|KIOCINIT
value|(('k'<<8)|2)
end_define

begin_comment
comment|/* force transmitter reinit */
end_comment

begin_define
define|#
directive|define
name|KIOCSHUT
value|(('k'<<8)|3)
end_define

begin_comment
comment|/* shut down all chans, force reinit */
end_comment

end_unit

