begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_STATES_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_STATES_H_
end_define

begin_define
define|#
directive|define
name|ST_ERROR
value|0x0
end_define

begin_define
define|#
directive|define
name|TP_CLOSED
value|0x1
end_define

begin_define
define|#
directive|define
name|TP_CRSENT
value|0x2
end_define

begin_define
define|#
directive|define
name|TP_AKWAIT
value|0x3
end_define

begin_define
define|#
directive|define
name|TP_OPEN
value|0x4
end_define

begin_define
define|#
directive|define
name|TP_CLOSING
value|0x5
end_define

begin_define
define|#
directive|define
name|TP_REFWAIT
value|0x6
end_define

begin_define
define|#
directive|define
name|TP_LISTENING
value|0x7
end_define

begin_define
define|#
directive|define
name|TP_CONFIRMING
value|0x8
end_define

begin_define
define|#
directive|define
name|tp_NSTATES
value|0x9
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

