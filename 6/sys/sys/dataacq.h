begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header for general data acquisition definitions.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DATAACQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DATAACQ_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Period in microseconds between analog I/O samples.  */
end_comment

begin_define
define|#
directive|define
name|AD_MICRO_PERIOD_SET
value|_IOW('A', 1, long)
end_define

begin_define
define|#
directive|define
name|AD_MICRO_PERIOD_GET
value|_IOR('A', 2, long)
end_define

begin_comment
comment|/* Gain list support.  Initially all gains are 1.  If the board  * supports no gains at all then AD_NGAINS_GET will return a 0.  *  * AD_NGAINS_GET: Return the number of gains the board supports  *  * AD_SUPPORTED_GAINS: Get the supported gains.  * The driver will copy out "ngains" doubles,  * where "ngains" is obtained with AD_NGAINS_GET.  *  * AD_GAINS_SET: Set the gain list.  The driver will copy in "ngains" ints.  *  * AD_GAINS_GET: Get the gain list.  The driver will copy out "ngains" ints.  */
end_comment

begin_define
define|#
directive|define
name|AD_NGAINS_GET
value|_IOR('A', 3, int)
end_define

begin_define
define|#
directive|define
name|AD_NCHANS_GET
value|_IOR('A', 4, int)
end_define

begin_define
define|#
directive|define
name|AD_SUPPORTED_GAINS
value|_IO('A', 5)
end_define

begin_define
define|#
directive|define
name|AD_GAINS_SET
value|_IO('A', 6)
end_define

begin_define
define|#
directive|define
name|AD_GAINS_GET
value|_IO('A', 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DATAACQ_H_ */
end_comment

end_unit

