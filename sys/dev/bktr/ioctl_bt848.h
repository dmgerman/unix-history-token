begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * extensions to ioctl_meteor.h for the bt848 cards  *  * $Id$  */
end_comment

begin_comment
comment|/*  * tuner types for the   */
end_comment

begin_define
define|#
directive|define
name|TUNERTYPE_NABCST
value|1
end_define

begin_define
define|#
directive|define
name|TUNERTYPE_CABLEIRC
value|2
end_define

begin_define
define|#
directive|define
name|TUNERTYPE_CABLEHRC
value|3
end_define

begin_define
define|#
directive|define
name|TUNERTYPE_WEUROPE
value|4
end_define

begin_comment
comment|/*  * XXX: this is a hack, should be in ioctl_meteor.h  * here to avoid touching that file for now...  */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETCHNL
value|_IOW('x', 32, unsigned int)
end_define

begin_comment
comment|/* set channel */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETCHNL
value|_IOR('x', 32, unsigned int)
end_define

begin_comment
comment|/* get channel */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETTYPE
value|_IOW('x', 33, unsigned int)
end_define

begin_comment
comment|/* set tuner type */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETTYPE
value|_IOR('x', 33, unsigned int)
end_define

begin_comment
comment|/* get tuner type */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETSTATUS
value|_IOR('x', 34, unsigned int)
end_define

begin_comment
comment|/* get tuner status */
end_comment

begin_comment
comment|/*  * XXX: more bad magic,  *      we need to fix the METEORGINPUT to return something public  *      duplicate them here for now...  */
end_comment

begin_define
define|#
directive|define
name|METEOR_DEV0
value|0x00001000
end_define

begin_define
define|#
directive|define
name|METEOR_DEV1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|METEOR_DEV2
value|0x00004000
end_define

end_unit

