begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.17 $ ** **  Here be a set of NNTP response codes as defined in RFC977 and elsewhere. **  The reponse codes are three digits, RFI, defined like this: **	R, Response: **		1xx	Informative message **		2xx	Command ok **		3xx	Command ok so far, send the rest of it. **		4xx	Command was correct, but couldn't be performed for **			some reason. **		5xx	Command unimplemented, or incorrect, or a serious **			program error occurred. **	F, Function: **		x0x	Connection, setup, and miscellaneous messages **		x1x	Newsgroup selection **		x2x	Article selection **		x3x	Distribution functions **		x4x	Posting **		x8x	Nonstandard extensions (AUTHINFO, XGTITLE) **		x9x	Debugging output **	I, Information: **		No defined semantics */
end_comment

begin_define
define|#
directive|define
name|NNTP_HELPOK_VAL
value|100
end_define

begin_define
define|#
directive|define
name|NNTP_BAD_COMMAND_VAL
value|500
end_define

begin_define
define|#
directive|define
name|NNTP_BAD_COMMAND
value|"500 Syntax error or bad command"
end_define

begin_define
define|#
directive|define
name|NNTP_TEMPERR_VAL
value|503
end_define

begin_define
define|#
directive|define
name|NNTP_ACCESS
value|"502 Permission denied"
end_define

begin_define
define|#
directive|define
name|NNTP_ACCESS_VAL
value|502
end_define

begin_define
define|#
directive|define
name|NNTP_GOODBYE_ACK
value|"205"
end_define

begin_define
define|#
directive|define
name|NNTP_GOODBYE_ACK_VAL
value|205
end_define

begin_define
define|#
directive|define
name|NNTP_GOODBYE
value|"400"
end_define

begin_define
define|#
directive|define
name|NNTP_GOODBYE_VAL
value|400
end_define

begin_define
define|#
directive|define
name|NNTP_HAVEIT
value|"435 Duplicate"
end_define

begin_define
define|#
directive|define
name|NNTP_HAVEIT_BADID
value|"435 Bad Message-ID"
end_define

begin_define
define|#
directive|define
name|NNTP_HAVEIT_VAL
value|435
end_define

begin_define
define|#
directive|define
name|NNTP_LIST_FOLLOWS
value|"215"
end_define

begin_define
define|#
directive|define
name|NNTP_LIST_FOLLOWS_VAL
value|215
end_define

begin_define
define|#
directive|define
name|NNTP_HELP_FOLLOWS
value|"100 Legal commands"
end_define

begin_define
define|#
directive|define
name|NNTP_HELP_FOLLOWS_VAL
value|100
end_define

begin_define
define|#
directive|define
name|NNTP_NOTHING_FOLLOWS_VAL
value|223
end_define

begin_define
define|#
directive|define
name|NNTP_ARTICLE_FOLLOWS
value|"220"
end_define

begin_define
define|#
directive|define
name|NNTP_ARTICLE_FOLLOWS_VAL
value|220
end_define

begin_define
define|#
directive|define
name|NNTP_NEWGROUPS_FOLLOWS_VAL
value|231
end_define

begin_define
define|#
directive|define
name|NNTP_HEAD_FOLLOWS
value|"221"
end_define

begin_define
define|#
directive|define
name|NNTP_HEAD_FOLLOWS_VAL
value|221
end_define

begin_define
define|#
directive|define
name|NNTP_BODY_FOLLOWS_VAL
value|222
end_define

begin_define
define|#
directive|define
name|NNTP_OVERVIEW_FOLLOWS_VAL
value|224
end_define

begin_define
define|#
directive|define
name|NNTP_DATE_FOLLOWS_VAL
value|111
end_define

begin_define
define|#
directive|define
name|NNTP_POSTOK
value|"200"
end_define

begin_define
define|#
directive|define
name|NNTP_POSTOK_VAL
value|200
end_define

begin_define
define|#
directive|define
name|NNTP_START_POST_VAL
value|340
end_define

begin_define
define|#
directive|define
name|NNTP_NOPOSTOK_VAL
value|201
end_define

begin_define
define|#
directive|define
name|NNTP_SLAVEOK_VAL
value|202
end_define

begin_define
define|#
directive|define
name|NNTP_REJECTIT_VAL
value|437
end_define

begin_define
define|#
directive|define
name|NNTP_REJECTIT_EMPTY
value|"437 Empty article"
end_define

begin_define
define|#
directive|define
name|NNTP_DONTHAVEIT
value|"430"
end_define

begin_define
define|#
directive|define
name|NNTP_DONTHAVEIT_VAL
value|430
end_define

begin_define
define|#
directive|define
name|NNTP_RESENDIT_NOHIST
value|"436 Can't write history"
end_define

begin_define
define|#
directive|define
name|NNTP_RESENDIT_NOSPACE
value|"436 No space"
end_define

begin_define
define|#
directive|define
name|NNTP_RESENDIT_VAL
value|436
end_define

begin_define
define|#
directive|define
name|NNTP_POSTEDOK
value|"240 Article posted"
end_define

begin_define
define|#
directive|define
name|NNTP_POSTEDOK_VAL
value|240
end_define

begin_define
define|#
directive|define
name|NNTP_POSTFAIL_VAL
value|441
end_define

begin_define
define|#
directive|define
name|NNTP_GROUPOK_VAL
value|211
end_define

begin_define
define|#
directive|define
name|NNTP_SENDIT
value|"335"
end_define

begin_define
define|#
directive|define
name|NNTP_SENDIT_VAL
value|335
end_define

begin_define
define|#
directive|define
name|NNTP_SYNTAX_USE
value|"501 Bad command use"
end_define

begin_define
define|#
directive|define
name|NNTP_SYNTAX_VAL
value|501
end_define

begin_define
define|#
directive|define
name|NNTP_TOOKIT
value|"235"
end_define

begin_define
define|#
directive|define
name|NNTP_TOOKIT_VAL
value|235
end_define

begin_define
define|#
directive|define
name|NNTP_NOTINGROUP
value|"412 Not in a newsgroup"
end_define

begin_define
define|#
directive|define
name|NNTP_NOTINGROUP_VAL
value|412
end_define

begin_define
define|#
directive|define
name|NNTP_NOSUCHGROUP
value|"411 No such group"
end_define

begin_define
define|#
directive|define
name|NNTP_NOSUCHGROUP_VAL
value|411
end_define

begin_define
define|#
directive|define
name|NNTP_NEWNEWSOK
value|"230 New news follows"
end_define

begin_define
define|#
directive|define
name|NNTP_NOARTINGRP
value|"423 Bad article number"
end_define

begin_define
define|#
directive|define
name|NNTP_NOARTINGRP_VAL
value|423
end_define

begin_define
define|#
directive|define
name|NNTP_NOCURRART
value|"420 No current article"
end_define

begin_define
define|#
directive|define
name|NNTP_NOCURRART_VAL
value|420
end_define

begin_define
define|#
directive|define
name|NNTP_NONEXT_VAL
value|421
end_define

begin_define
define|#
directive|define
name|NNTP_NOPREV_VAL
value|422
end_define

begin_define
define|#
directive|define
name|NNTP_CANTPOST
value|"440 Posting not allowed"
end_define

begin_define
define|#
directive|define
name|NNTP_CANTPOST_VAL
value|440
end_define

begin_comment
comment|/* **  The first character of an NNTP reply can be used as a category class. */
end_comment

begin_define
define|#
directive|define
name|NNTP_CLASS_OK
value|'2'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_ERROR
value|'4'
end_define

begin_define
define|#
directive|define
name|NNTP_CLASS_FATAL
value|'5'
end_define

begin_comment
comment|/* **  The NNTP protocol currently has no way to say "offer me this article **  later, but don't close the connection."  That will be fixed in NNTP2. #define NNTP_RESENDIT_LATER		"?" #define NNTP_RESENDIT_LATER_VAL		? */
end_comment

begin_comment
comment|/* **  Authentication commands from the RFC update (not official). */
end_comment

begin_define
define|#
directive|define
name|NNTP_AUTH_NEEDED
value|"480"
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_NEEDED_VAL
value|480
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_BAD
value|"481"
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_NEXT
value|"381"
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_NEXT_VAL
value|381
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_OK
value|"281"
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_OK_VAL
value|281
end_define

begin_define
define|#
directive|define
name|NNTP_AUTH_REJECT_VAL
value|482
end_define

begin_comment
comment|/* **  XGTITLE, from ANU news. */
end_comment

begin_define
define|#
directive|define
name|NNTP_XGTITLE_BAD
value|481
end_define

begin_comment
comment|/* Yes, 481. */
end_comment

begin_define
define|#
directive|define
name|NNTP_XGTITLE_OK
value|282
end_define

begin_define
define|#
directive|define
name|NNTP_STRLEN
value|512
end_define

end_unit

