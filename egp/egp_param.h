begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* egp_param.h */
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_comment
comment|/* defines various egp parameters */
end_comment

begin_comment
comment|/* Retry counts */
end_comment

begin_define
define|#
directive|define
name|NACQ_RETRY
value|5
end_define

begin_comment
comment|/* Max. No. acquire retransmits before  				   switch to longer interval */
end_comment

begin_define
define|#
directive|define
name|NCEASE_RETRY
value|3
end_define

begin_comment
comment|/* Max. No. cease retransmits */
end_comment

begin_define
define|#
directive|define
name|NPOLL
value|2
end_define

begin_comment
comment|/* Max. No. NR polls to send or receive 				   with same id */
end_comment

begin_comment
comment|/* Acquire interval constants */
end_comment

begin_comment
comment|/* MINHELLOINT below is used for neigh. acquire retransmit interval when  * in state UNACQUIRED or ACQUIRE_SENT or cease retry interval when not  * acquired  */
end_comment

begin_define
define|#
directive|define
name|LONGACQINT
value|240
end_define

begin_comment
comment|/* Neigh. acquire retransmit interval (sec) 				   when no response after NACQ_RETRY or 				   after ceased */
end_comment

begin_comment
comment|/* Hello interval constants */
end_comment

begin_define
define|#
directive|define
name|MINHELLOINT
value|30
end_define

begin_comment
comment|/* Minimum interval for sending and 				   receiving hellos */
end_comment

begin_define
define|#
directive|define
name|MAXHELLOINT
value|120
end_define

begin_comment
comment|/* Maximum hello interval, sec. */
end_comment

begin_define
define|#
directive|define
name|HELLOMARGIN
value|2
end_define

begin_comment
comment|/* Margin in hello send interval to allow 				   for delay variation in the network */
end_comment

begin_comment
comment|/* Poll interval constants */
end_comment

begin_define
define|#
directive|define
name|MINPOLLINT
value|120
end_define

begin_comment
comment|/* Minimum interval for sending and receiving 				   polls */
end_comment

begin_define
define|#
directive|define
name|MAXPOLLINT
value|480
end_define

begin_comment
comment|/* Maximum poll interval, sec. */
end_comment

begin_comment
comment|/* repoll interval is set to the hello interval for the particular neighbor */
end_comment

begin_comment
comment|/* Reachability test constants */
end_comment

begin_define
define|#
directive|define
name|NCOMMANDS
value|4
end_define

begin_comment
comment|/* No. commands sent on which reachability is 				   based */
end_comment

begin_define
define|#
directive|define
name|NRESPONSES
value|2
end_define

begin_comment
comment|/* No. responses expected per NCOMMANDs sent, 				   if down,> NRESPONSE+1 => up, 				   if up,< NRESPONSES => down */
end_comment

begin_define
define|#
directive|define
name|NUNREACH
value|60
end_define

begin_comment
comment|/* No. consecutive times neighbor is  				   unreachbable before ceased */
end_comment

begin_comment
comment|/* Command reception rate constants */
end_comment

begin_define
define|#
directive|define
name|CHKCMDTIME
value|480
end_define

begin_comment
comment|/* No. seconds betw. check for recv too many 				   acq., hello or poll commands */
end_comment

begin_define
define|#
directive|define
name|NMAXCMD
value|40
end_define

begin_comment
comment|/* Max. # acq., hello and poll commands 				   allowed during CHKCMDTIME seconds */
end_comment

end_unit

