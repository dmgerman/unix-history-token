begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Response codes for NNTP server  *  * @(#)response_codes.h	1.6	(Berkeley) 2/6/86  *  * First digit:  *  *	1xx	Informative message  *	2xx	Command ok  *	3xx	Command ok so far, continue  *	4xx	Command was correct, but couldn't be performed  *		for some specified reason.  *	5xx	Command unimplemented, incorrect, or a  *		program error has occured.  *  * Second digit:  *  *	x0x	Connection, setup, miscellaneous  *	x1x	Newsgroup selection  *	x2x	Article selection  *	x3x	Distribution  *	x4x	Posting  */
end_comment

begin_define
define|#
directive|define
name|CHAR_INF
value|'1'
end_define

begin_define
define|#
directive|define
name|CHAR_OK
value|'2'
end_define

begin_define
define|#
directive|define
name|CHAR_CONT
value|'3'
end_define

begin_define
define|#
directive|define
name|CHAR_ERR
value|'4'
end_define

begin_define
define|#
directive|define
name|CHAR_FATAL
value|'5'
end_define

begin_define
define|#
directive|define
name|INF_HELP
value|100
end_define

begin_comment
comment|/* Help text on way */
end_comment

begin_define
define|#
directive|define
name|INF_DEBUG
value|199
end_define

begin_comment
comment|/* Debug output */
end_comment

begin_define
define|#
directive|define
name|OK_CANPOST
value|200
end_define

begin_comment
comment|/* Hello; you can post */
end_comment

begin_define
define|#
directive|define
name|OK_NOPOST
value|201
end_define

begin_comment
comment|/* Hello; you can't post */
end_comment

begin_define
define|#
directive|define
name|OK_SLAVE
value|202
end_define

begin_comment
comment|/* Slave status noted */
end_comment

begin_define
define|#
directive|define
name|OK_GOODBYE
value|205
end_define

begin_comment
comment|/* Closing connection */
end_comment

begin_define
define|#
directive|define
name|OK_GROUP
value|211
end_define

begin_comment
comment|/* Group selected */
end_comment

begin_define
define|#
directive|define
name|OK_GROUPS
value|215
end_define

begin_comment
comment|/* Newsgroups follow */
end_comment

begin_define
define|#
directive|define
name|OK_ARTICLE
value|220
end_define

begin_comment
comment|/* Article (head& body) follows */
end_comment

begin_define
define|#
directive|define
name|OK_HEAD
value|221
end_define

begin_comment
comment|/* Head follows */
end_comment

begin_define
define|#
directive|define
name|OK_BODY
value|222
end_define

begin_comment
comment|/* Body follows */
end_comment

begin_define
define|#
directive|define
name|OK_NOTEXT
value|223
end_define

begin_comment
comment|/* No text sent -- stat, next, last */
end_comment

begin_define
define|#
directive|define
name|OK_NEWNEWS
value|230
end_define

begin_comment
comment|/* New articles by message-id follow */
end_comment

begin_define
define|#
directive|define
name|OK_NEWGROUPS
value|231
end_define

begin_comment
comment|/* New newsgroups follow */
end_comment

begin_define
define|#
directive|define
name|OK_XFERED
value|235
end_define

begin_comment
comment|/* Article transferred successfully */
end_comment

begin_define
define|#
directive|define
name|OK_POSTED
value|240
end_define

begin_comment
comment|/* Article posted successfully */
end_comment

begin_define
define|#
directive|define
name|CONT_XFER
value|335
end_define

begin_comment
comment|/* Continue to send article */
end_comment

begin_define
define|#
directive|define
name|CONT_POST
value|340
end_define

begin_comment
comment|/* Continue to post article */
end_comment

begin_define
define|#
directive|define
name|ERR_GOODBYE
value|400
end_define

begin_comment
comment|/* Have to hang up for some reason */
end_comment

begin_define
define|#
directive|define
name|ERR_NOGROUP
value|411
end_define

begin_comment
comment|/* No such newsgroup */
end_comment

begin_define
define|#
directive|define
name|ERR_NCING
value|412
end_define

begin_comment
comment|/* Not currently in newsgroup */
end_comment

begin_define
define|#
directive|define
name|ERR_NOCRNT
value|420
end_define

begin_comment
comment|/* No current article selected */
end_comment

begin_define
define|#
directive|define
name|ERR_NONEXT
value|421
end_define

begin_comment
comment|/* No next article in this group */
end_comment

begin_define
define|#
directive|define
name|ERR_NOPREV
value|422
end_define

begin_comment
comment|/* No previous article in this group */
end_comment

begin_define
define|#
directive|define
name|ERR_NOARTIG
value|423
end_define

begin_comment
comment|/* No such article in this group */
end_comment

begin_define
define|#
directive|define
name|ERR_NOART
value|430
end_define

begin_comment
comment|/* No such article at all */
end_comment

begin_define
define|#
directive|define
name|ERR_GOTIT
value|435
end_define

begin_comment
comment|/* Already got that article, don't send */
end_comment

begin_define
define|#
directive|define
name|ERR_XFERFAIL
value|436
end_define

begin_comment
comment|/* Transfer failed */
end_comment

begin_define
define|#
directive|define
name|ERR_XFERRJCT
value|437
end_define

begin_comment
comment|/* Article rejected, don't resend */
end_comment

begin_define
define|#
directive|define
name|ERR_NOPOST
value|440
end_define

begin_comment
comment|/* Posting not allowed */
end_comment

begin_define
define|#
directive|define
name|ERR_POSTFAIL
value|441
end_define

begin_comment
comment|/* Posting failed */
end_comment

begin_define
define|#
directive|define
name|ERR_COMMAND
value|500
end_define

begin_comment
comment|/* Command not recognized */
end_comment

begin_define
define|#
directive|define
name|ERR_CMDSYN
value|501
end_define

begin_comment
comment|/* Command syntax error */
end_comment

begin_define
define|#
directive|define
name|ERR_ACCESS
value|502
end_define

begin_comment
comment|/* Access to server denied */
end_comment

begin_define
define|#
directive|define
name|ERR_FAULT
value|503
end_define

begin_comment
comment|/* Program fault, command not performed */
end_comment

end_unit

