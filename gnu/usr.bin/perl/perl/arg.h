begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: arg.h,v $$Revision: 1.3 $$Date: 1995/05/30 05:02:49 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: arg.h,v $  * Revision 1.3  1995/05/30 05:02:49  rgrimes  * Remove trailing whitespace.  *  * Revision 1.2  1994/09/11  03:17:24  gclarkii  * Changed AF_LOCAL to AF_LOCAL_XX so as not to conflict with 4.4 socket.h  * Added casts to shutup warnings in doio.c  *  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:34  nate  * PERL!  *  * Revision 4.0.1.3  92/06/08  11:44:06  lwall  * patch20: O_PIPE conflicted with Atari  * patch20: clarified debugging output for literals and double-quoted strings  *  * Revision 4.0.1.2  91/11/05  15:51:05  lwall  * patch11: added eval {}  * patch11: added sort {} LIST  *  * Revision 4.0.1.1  91/06/07  10:18:30  lwall  * patch4: length($`), length($&), length($') now optimized to avoid string copy  * patch4: new copyright notice  * patch4: many, many itty-bitty portability fixes  *  * Revision 4.0  91/03/20  01:03:09  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|O_NULL
value|0
end_define

begin_define
define|#
directive|define
name|O_RCAT
value|1
end_define

begin_define
define|#
directive|define
name|O_ITEM
value|2
end_define

begin_define
define|#
directive|define
name|O_SCALAR
value|3
end_define

begin_define
define|#
directive|define
name|O_ITEM2
value|4
end_define

begin_define
define|#
directive|define
name|O_ITEM3
value|5
end_define

begin_define
define|#
directive|define
name|O_CONCAT
value|6
end_define

begin_define
define|#
directive|define
name|O_REPEAT
value|7
end_define

begin_define
define|#
directive|define
name|O_MATCH
value|8
end_define

begin_define
define|#
directive|define
name|O_NMATCH
value|9
end_define

begin_define
define|#
directive|define
name|O_SUBST
value|10
end_define

begin_define
define|#
directive|define
name|O_NSUBST
value|11
end_define

begin_define
define|#
directive|define
name|O_ASSIGN
value|12
end_define

begin_define
define|#
directive|define
name|O_LOCAL
value|13
end_define

begin_define
define|#
directive|define
name|O_AASSIGN
value|14
end_define

begin_define
define|#
directive|define
name|O_SASSIGN
value|15
end_define

begin_define
define|#
directive|define
name|O_CHOP
value|16
end_define

begin_define
define|#
directive|define
name|O_DEFINED
value|17
end_define

begin_define
define|#
directive|define
name|O_UNDEF
value|18
end_define

begin_define
define|#
directive|define
name|O_STUDY
value|19
end_define

begin_define
define|#
directive|define
name|O_POW
value|20
end_define

begin_define
define|#
directive|define
name|O_MULTIPLY
value|21
end_define

begin_define
define|#
directive|define
name|O_DIVIDE
value|22
end_define

begin_define
define|#
directive|define
name|O_MODULO
value|23
end_define

begin_define
define|#
directive|define
name|O_ADD
value|24
end_define

begin_define
define|#
directive|define
name|O_SUBTRACT
value|25
end_define

begin_define
define|#
directive|define
name|O_LEFT_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|O_RIGHT_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|O_LT
value|28
end_define

begin_define
define|#
directive|define
name|O_GT
value|29
end_define

begin_define
define|#
directive|define
name|O_LE
value|30
end_define

begin_define
define|#
directive|define
name|O_GE
value|31
end_define

begin_define
define|#
directive|define
name|O_EQ
value|32
end_define

begin_define
define|#
directive|define
name|O_NE
value|33
end_define

begin_define
define|#
directive|define
name|O_NCMP
value|34
end_define

begin_define
define|#
directive|define
name|O_BIT_AND
value|35
end_define

begin_define
define|#
directive|define
name|O_XOR
value|36
end_define

begin_define
define|#
directive|define
name|O_BIT_OR
value|37
end_define

begin_define
define|#
directive|define
name|O_AND
value|38
end_define

begin_define
define|#
directive|define
name|O_OR
value|39
end_define

begin_define
define|#
directive|define
name|O_COND_EXPR
value|40
end_define

begin_define
define|#
directive|define
name|O_COMMA
value|41
end_define

begin_define
define|#
directive|define
name|O_NEGATE
value|42
end_define

begin_define
define|#
directive|define
name|O_NOT
value|43
end_define

begin_define
define|#
directive|define
name|O_COMPLEMENT
value|44
end_define

begin_define
define|#
directive|define
name|O_SELECT
value|45
end_define

begin_define
define|#
directive|define
name|O_WRITE
value|46
end_define

begin_define
define|#
directive|define
name|O_DBMOPEN
value|47
end_define

begin_define
define|#
directive|define
name|O_DBMCLOSE
value|48
end_define

begin_define
define|#
directive|define
name|O_OPEN
value|49
end_define

begin_define
define|#
directive|define
name|O_TRANS
value|50
end_define

begin_define
define|#
directive|define
name|O_NTRANS
value|51
end_define

begin_define
define|#
directive|define
name|O_CLOSE
value|52
end_define

begin_define
define|#
directive|define
name|O_EACH
value|53
end_define

begin_define
define|#
directive|define
name|O_VALUES
value|54
end_define

begin_define
define|#
directive|define
name|O_KEYS
value|55
end_define

begin_define
define|#
directive|define
name|O_LARRAY
value|56
end_define

begin_define
define|#
directive|define
name|O_ARRAY
value|57
end_define

begin_define
define|#
directive|define
name|O_AELEM
value|58
end_define

begin_define
define|#
directive|define
name|O_DELETE
value|59
end_define

begin_define
define|#
directive|define
name|O_LHASH
value|60
end_define

begin_define
define|#
directive|define
name|O_HASH
value|61
end_define

begin_define
define|#
directive|define
name|O_HELEM
value|62
end_define

begin_define
define|#
directive|define
name|O_LAELEM
value|63
end_define

begin_define
define|#
directive|define
name|O_LHELEM
value|64
end_define

begin_define
define|#
directive|define
name|O_LSLICE
value|65
end_define

begin_define
define|#
directive|define
name|O_ASLICE
value|66
end_define

begin_define
define|#
directive|define
name|O_HSLICE
value|67
end_define

begin_define
define|#
directive|define
name|O_LASLICE
value|68
end_define

begin_define
define|#
directive|define
name|O_LHSLICE
value|69
end_define

begin_define
define|#
directive|define
name|O_SPLICE
value|70
end_define

begin_define
define|#
directive|define
name|O_PUSH
value|71
end_define

begin_define
define|#
directive|define
name|O_POP
value|72
end_define

begin_define
define|#
directive|define
name|O_SHIFT
value|73
end_define

begin_define
define|#
directive|define
name|O_UNPACK
value|74
end_define

begin_define
define|#
directive|define
name|O_SPLIT
value|75
end_define

begin_define
define|#
directive|define
name|O_LENGTH
value|76
end_define

begin_define
define|#
directive|define
name|O_SPRINTF
value|77
end_define

begin_define
define|#
directive|define
name|O_SUBSTR
value|78
end_define

begin_define
define|#
directive|define
name|O_PACK
value|79
end_define

begin_define
define|#
directive|define
name|O_GREP
value|80
end_define

begin_define
define|#
directive|define
name|O_JOIN
value|81
end_define

begin_define
define|#
directive|define
name|O_SLT
value|82
end_define

begin_define
define|#
directive|define
name|O_SGT
value|83
end_define

begin_define
define|#
directive|define
name|O_SLE
value|84
end_define

begin_define
define|#
directive|define
name|O_SGE
value|85
end_define

begin_define
define|#
directive|define
name|O_SEQ
value|86
end_define

begin_define
define|#
directive|define
name|O_SNE
value|87
end_define

begin_define
define|#
directive|define
name|O_SCMP
value|88
end_define

begin_define
define|#
directive|define
name|O_SUBR
value|89
end_define

begin_define
define|#
directive|define
name|O_DBSUBR
value|90
end_define

begin_define
define|#
directive|define
name|O_CALLER
value|91
end_define

begin_define
define|#
directive|define
name|O_SORT
value|92
end_define

begin_define
define|#
directive|define
name|O_REVERSE
value|93
end_define

begin_define
define|#
directive|define
name|O_WARN
value|94
end_define

begin_define
define|#
directive|define
name|O_DIE
value|95
end_define

begin_define
define|#
directive|define
name|O_PRTF
value|96
end_define

begin_define
define|#
directive|define
name|O_PRINT
value|97
end_define

begin_define
define|#
directive|define
name|O_CHDIR
value|98
end_define

begin_define
define|#
directive|define
name|O_EXIT
value|99
end_define

begin_define
define|#
directive|define
name|O_RESET
value|100
end_define

begin_define
define|#
directive|define
name|O_LIST
value|101
end_define

begin_define
define|#
directive|define
name|O_EOF
value|102
end_define

begin_define
define|#
directive|define
name|O_GETC
value|103
end_define

begin_define
define|#
directive|define
name|O_TELL
value|104
end_define

begin_define
define|#
directive|define
name|O_RECV
value|105
end_define

begin_define
define|#
directive|define
name|O_READ
value|106
end_define

begin_define
define|#
directive|define
name|O_SYSREAD
value|107
end_define

begin_define
define|#
directive|define
name|O_SYSWRITE
value|108
end_define

begin_define
define|#
directive|define
name|O_SEND
value|109
end_define

begin_define
define|#
directive|define
name|O_SEEK
value|110
end_define

begin_define
define|#
directive|define
name|O_RETURN
value|111
end_define

begin_define
define|#
directive|define
name|O_REDO
value|112
end_define

begin_define
define|#
directive|define
name|O_NEXT
value|113
end_define

begin_define
define|#
directive|define
name|O_LAST
value|114
end_define

begin_define
define|#
directive|define
name|O_DUMP
value|115
end_define

begin_define
define|#
directive|define
name|O_GOTO
value|116
end_define

begin_define
define|#
directive|define
name|O_INDEX
value|117
end_define

begin_define
define|#
directive|define
name|O_RINDEX
value|118
end_define

begin_define
define|#
directive|define
name|O_TIME
value|119
end_define

begin_define
define|#
directive|define
name|O_TMS
value|120
end_define

begin_define
define|#
directive|define
name|O_LOCALTIME
value|121
end_define

begin_define
define|#
directive|define
name|O_GMTIME
value|122
end_define

begin_define
define|#
directive|define
name|O_TRUNCATE
value|123
end_define

begin_define
define|#
directive|define
name|O_LSTAT
value|124
end_define

begin_define
define|#
directive|define
name|O_STAT
value|125
end_define

begin_define
define|#
directive|define
name|O_CRYPT
value|126
end_define

begin_define
define|#
directive|define
name|O_ATAN2
value|127
end_define

begin_define
define|#
directive|define
name|O_SIN
value|128
end_define

begin_define
define|#
directive|define
name|O_COS
value|129
end_define

begin_define
define|#
directive|define
name|O_RAND
value|130
end_define

begin_define
define|#
directive|define
name|O_SRAND
value|131
end_define

begin_define
define|#
directive|define
name|O_EXP
value|132
end_define

begin_define
define|#
directive|define
name|O_LOG
value|133
end_define

begin_define
define|#
directive|define
name|O_SQRT
value|134
end_define

begin_define
define|#
directive|define
name|O_INT
value|135
end_define

begin_define
define|#
directive|define
name|O_ORD
value|136
end_define

begin_define
define|#
directive|define
name|O_ALARM
value|137
end_define

begin_define
define|#
directive|define
name|O_SLEEP
value|138
end_define

begin_define
define|#
directive|define
name|O_RANGE
value|139
end_define

begin_define
define|#
directive|define
name|O_F_OR_R
value|140
end_define

begin_define
define|#
directive|define
name|O_FLIP
value|141
end_define

begin_define
define|#
directive|define
name|O_FLOP
value|142
end_define

begin_define
define|#
directive|define
name|O_FORK
value|143
end_define

begin_define
define|#
directive|define
name|O_WAIT
value|144
end_define

begin_define
define|#
directive|define
name|O_WAITPID
value|145
end_define

begin_define
define|#
directive|define
name|O_SYSTEM
value|146
end_define

begin_define
define|#
directive|define
name|O_EXEC_OP
value|147
end_define

begin_define
define|#
directive|define
name|O_HEX
value|148
end_define

begin_define
define|#
directive|define
name|O_OCT
value|149
end_define

begin_define
define|#
directive|define
name|O_CHOWN
value|150
end_define

begin_define
define|#
directive|define
name|O_KILL
value|151
end_define

begin_define
define|#
directive|define
name|O_UNLINK
value|152
end_define

begin_define
define|#
directive|define
name|O_CHMOD
value|153
end_define

begin_define
define|#
directive|define
name|O_UTIME
value|154
end_define

begin_define
define|#
directive|define
name|O_UMASK
value|155
end_define

begin_define
define|#
directive|define
name|O_MSGGET
value|156
end_define

begin_define
define|#
directive|define
name|O_SHMGET
value|157
end_define

begin_define
define|#
directive|define
name|O_SEMGET
value|158
end_define

begin_define
define|#
directive|define
name|O_MSGCTL
value|159
end_define

begin_define
define|#
directive|define
name|O_SHMCTL
value|160
end_define

begin_define
define|#
directive|define
name|O_SEMCTL
value|161
end_define

begin_define
define|#
directive|define
name|O_MSGSND
value|162
end_define

begin_define
define|#
directive|define
name|O_MSGRCV
value|163
end_define

begin_define
define|#
directive|define
name|O_SEMOP
value|164
end_define

begin_define
define|#
directive|define
name|O_SHMREAD
value|165
end_define

begin_define
define|#
directive|define
name|O_SHMWRITE
value|166
end_define

begin_define
define|#
directive|define
name|O_RENAME
value|167
end_define

begin_define
define|#
directive|define
name|O_LINK
value|168
end_define

begin_define
define|#
directive|define
name|O_MKDIR
value|169
end_define

begin_define
define|#
directive|define
name|O_RMDIR
value|170
end_define

begin_define
define|#
directive|define
name|O_GETPPID
value|171
end_define

begin_define
define|#
directive|define
name|O_GETPGRP
value|172
end_define

begin_define
define|#
directive|define
name|O_SETPGRP
value|173
end_define

begin_define
define|#
directive|define
name|O_GETPRIORITY
value|174
end_define

begin_define
define|#
directive|define
name|O_SETPRIORITY
value|175
end_define

begin_define
define|#
directive|define
name|O_CHROOT
value|176
end_define

begin_define
define|#
directive|define
name|O_FCNTL
value|177
end_define

begin_define
define|#
directive|define
name|O_IOCTL
value|178
end_define

begin_define
define|#
directive|define
name|O_FLOCK
value|179
end_define

begin_define
define|#
directive|define
name|O_UNSHIFT
value|180
end_define

begin_define
define|#
directive|define
name|O_REQUIRE
value|181
end_define

begin_define
define|#
directive|define
name|O_DOFILE
value|182
end_define

begin_define
define|#
directive|define
name|O_EVAL
value|183
end_define

begin_define
define|#
directive|define
name|O_FTRREAD
value|184
end_define

begin_define
define|#
directive|define
name|O_FTRWRITE
value|185
end_define

begin_define
define|#
directive|define
name|O_FTREXEC
value|186
end_define

begin_define
define|#
directive|define
name|O_FTEREAD
value|187
end_define

begin_define
define|#
directive|define
name|O_FTEWRITE
value|188
end_define

begin_define
define|#
directive|define
name|O_FTEEXEC
value|189
end_define

begin_define
define|#
directive|define
name|O_FTIS
value|190
end_define

begin_define
define|#
directive|define
name|O_FTEOWNED
value|191
end_define

begin_define
define|#
directive|define
name|O_FTROWNED
value|192
end_define

begin_define
define|#
directive|define
name|O_FTZERO
value|193
end_define

begin_define
define|#
directive|define
name|O_FTSIZE
value|194
end_define

begin_define
define|#
directive|define
name|O_FTMTIME
value|195
end_define

begin_define
define|#
directive|define
name|O_FTATIME
value|196
end_define

begin_define
define|#
directive|define
name|O_FTCTIME
value|197
end_define

begin_define
define|#
directive|define
name|O_FTSOCK
value|198
end_define

begin_define
define|#
directive|define
name|O_FTCHR
value|199
end_define

begin_define
define|#
directive|define
name|O_FTBLK
value|200
end_define

begin_define
define|#
directive|define
name|O_FTFILE
value|201
end_define

begin_define
define|#
directive|define
name|O_FTDIR
value|202
end_define

begin_define
define|#
directive|define
name|O_FTPIPE
value|203
end_define

begin_define
define|#
directive|define
name|O_FTLINK
value|204
end_define

begin_define
define|#
directive|define
name|O_SYMLINK
value|205
end_define

begin_define
define|#
directive|define
name|O_READLINK
value|206
end_define

begin_define
define|#
directive|define
name|O_FTSUID
value|207
end_define

begin_define
define|#
directive|define
name|O_FTSGID
value|208
end_define

begin_define
define|#
directive|define
name|O_FTSVTX
value|209
end_define

begin_define
define|#
directive|define
name|O_FTTTY
value|210
end_define

begin_define
define|#
directive|define
name|O_FTTEXT
value|211
end_define

begin_define
define|#
directive|define
name|O_FTBINARY
value|212
end_define

begin_define
define|#
directive|define
name|O_SOCKET
value|213
end_define

begin_define
define|#
directive|define
name|O_BIND
value|214
end_define

begin_define
define|#
directive|define
name|O_CONNECT
value|215
end_define

begin_define
define|#
directive|define
name|O_LISTEN
value|216
end_define

begin_define
define|#
directive|define
name|O_ACCEPT
value|217
end_define

begin_define
define|#
directive|define
name|O_GHBYNAME
value|218
end_define

begin_define
define|#
directive|define
name|O_GHBYADDR
value|219
end_define

begin_define
define|#
directive|define
name|O_GHOSTENT
value|220
end_define

begin_define
define|#
directive|define
name|O_GNBYNAME
value|221
end_define

begin_define
define|#
directive|define
name|O_GNBYADDR
value|222
end_define

begin_define
define|#
directive|define
name|O_GNETENT
value|223
end_define

begin_define
define|#
directive|define
name|O_GPBYNAME
value|224
end_define

begin_define
define|#
directive|define
name|O_GPBYNUMBER
value|225
end_define

begin_define
define|#
directive|define
name|O_GPROTOENT
value|226
end_define

begin_define
define|#
directive|define
name|O_GSBYNAME
value|227
end_define

begin_define
define|#
directive|define
name|O_GSBYPORT
value|228
end_define

begin_define
define|#
directive|define
name|O_GSERVENT
value|229
end_define

begin_define
define|#
directive|define
name|O_SHOSTENT
value|230
end_define

begin_define
define|#
directive|define
name|O_SNETENT
value|231
end_define

begin_define
define|#
directive|define
name|O_SPROTOENT
value|232
end_define

begin_define
define|#
directive|define
name|O_SSERVENT
value|233
end_define

begin_define
define|#
directive|define
name|O_EHOSTENT
value|234
end_define

begin_define
define|#
directive|define
name|O_ENETENT
value|235
end_define

begin_define
define|#
directive|define
name|O_EPROTOENT
value|236
end_define

begin_define
define|#
directive|define
name|O_ESERVENT
value|237
end_define

begin_define
define|#
directive|define
name|O_SOCKPAIR
value|238
end_define

begin_define
define|#
directive|define
name|O_SHUTDOWN
value|239
end_define

begin_define
define|#
directive|define
name|O_GSOCKOPT
value|240
end_define

begin_define
define|#
directive|define
name|O_SSOCKOPT
value|241
end_define

begin_define
define|#
directive|define
name|O_GETSOCKNAME
value|242
end_define

begin_define
define|#
directive|define
name|O_GETPEERNAME
value|243
end_define

begin_define
define|#
directive|define
name|O_SSELECT
value|244
end_define

begin_define
define|#
directive|define
name|O_FILENO
value|245
end_define

begin_define
define|#
directive|define
name|O_BINMODE
value|246
end_define

begin_define
define|#
directive|define
name|O_VEC
value|247
end_define

begin_define
define|#
directive|define
name|O_GPWNAM
value|248
end_define

begin_define
define|#
directive|define
name|O_GPWUID
value|249
end_define

begin_define
define|#
directive|define
name|O_GPWENT
value|250
end_define

begin_define
define|#
directive|define
name|O_SPWENT
value|251
end_define

begin_define
define|#
directive|define
name|O_EPWENT
value|252
end_define

begin_define
define|#
directive|define
name|O_GGRNAM
value|253
end_define

begin_define
define|#
directive|define
name|O_GGRGID
value|254
end_define

begin_define
define|#
directive|define
name|O_GGRENT
value|255
end_define

begin_define
define|#
directive|define
name|O_SGRENT
value|256
end_define

begin_define
define|#
directive|define
name|O_EGRENT
value|257
end_define

begin_define
define|#
directive|define
name|O_GETLOGIN
value|258
end_define

begin_define
define|#
directive|define
name|O_OPEN_DIR
value|259
end_define

begin_define
define|#
directive|define
name|O_READDIR
value|260
end_define

begin_define
define|#
directive|define
name|O_TELLDIR
value|261
end_define

begin_define
define|#
directive|define
name|O_SEEKDIR
value|262
end_define

begin_define
define|#
directive|define
name|O_REWINDDIR
value|263
end_define

begin_define
define|#
directive|define
name|O_CLOSEDIR
value|264
end_define

begin_define
define|#
directive|define
name|O_SYSCALL
value|265
end_define

begin_define
define|#
directive|define
name|O_PIPE_OP
value|266
end_define

begin_define
define|#
directive|define
name|O_TRY
value|267
end_define

begin_define
define|#
directive|define
name|O_EVALONCE
value|268
end_define

begin_define
define|#
directive|define
name|MAXO
value|269
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|opname
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|opname
index|[]
init|=
block|{
literal|"NULL"
block|,
literal|"RCAT"
block|,
literal|"ITEM"
block|,
literal|"SCALAR"
block|,
literal|"ITEM2"
block|,
literal|"ITEM3"
block|,
literal|"CONCAT"
block|,
literal|"REPEAT"
block|,
literal|"MATCH"
block|,
literal|"NMATCH"
block|,
literal|"SUBST"
block|,
literal|"NSUBST"
block|,
literal|"ASSIGN"
block|,
literal|"LOCAL"
block|,
literal|"AASSIGN"
block|,
literal|"SASSIGN"
block|,
literal|"CHOP"
block|,
literal|"DEFINED"
block|,
literal|"UNDEF"
block|,
literal|"STUDY"
block|,
literal|"POW"
block|,
literal|"MULTIPLY"
block|,
literal|"DIVIDE"
block|,
literal|"MODULO"
block|,
literal|"ADD"
block|,
literal|"SUBTRACT"
block|,
literal|"LEFT_SHIFT"
block|,
literal|"RIGHT_SHIFT"
block|,
literal|"LT"
block|,
literal|"GT"
block|,
literal|"LE"
block|,
literal|"GE"
block|,
literal|"EQ"
block|,
literal|"NE"
block|,
literal|"NCMP"
block|,
literal|"BIT_AND"
block|,
literal|"XOR"
block|,
literal|"BIT_OR"
block|,
literal|"AND"
block|,
literal|"OR"
block|,
literal|"COND_EXPR"
block|,
literal|"COMMA"
block|,
literal|"NEGATE"
block|,
literal|"NOT"
block|,
literal|"COMPLEMENT"
block|,
literal|"SELECT"
block|,
literal|"WRITE"
block|,
literal|"DBMOPEN"
block|,
literal|"DBMCLOSE"
block|,
literal|"OPEN"
block|,
literal|"TRANS"
block|,
literal|"NTRANS"
block|,
literal|"CLOSE"
block|,
literal|"EACH"
block|,
literal|"VALUES"
block|,
literal|"KEYS"
block|,
literal|"LARRAY"
block|,
literal|"ARRAY"
block|,
literal|"AELEM"
block|,
literal|"DELETE"
block|,
literal|"LHASH"
block|,
literal|"HASH"
block|,
literal|"HELEM"
block|,
literal|"LAELEM"
block|,
literal|"LHELEM"
block|,
literal|"LSLICE"
block|,
literal|"ASLICE"
block|,
literal|"HSLICE"
block|,
literal|"LASLICE"
block|,
literal|"LHSLICE"
block|,
literal|"SPLICE"
block|,
literal|"PUSH"
block|,
literal|"POP"
block|,
literal|"SHIFT"
block|,
literal|"UNPACK"
block|,
literal|"SPLIT"
block|,
literal|"LENGTH"
block|,
literal|"SPRINTF"
block|,
literal|"SUBSTR"
block|,
literal|"PACK"
block|,
literal|"GREP"
block|,
literal|"JOIN"
block|,
literal|"SLT"
block|,
literal|"SGT"
block|,
literal|"SLE"
block|,
literal|"SGE"
block|,
literal|"SEQ"
block|,
literal|"SNE"
block|,
literal|"SCMP"
block|,
literal|"SUBR"
block|,
literal|"DBSUBR"
block|,
literal|"CALLER"
block|,
literal|"SORT"
block|,
literal|"REVERSE"
block|,
literal|"WARN"
block|,
literal|"DIE"
block|,
literal|"PRINTF"
block|,
literal|"PRINT"
block|,
literal|"CHDIR"
block|,
literal|"EXIT"
block|,
literal|"RESET"
block|,
literal|"LIST"
block|,
literal|"EOF"
block|,
literal|"GETC"
block|,
literal|"TELL"
block|,
literal|"RECV"
block|,
literal|"READ"
block|,
literal|"SYSREAD"
block|,
literal|"SYSWRITE"
block|,
literal|"SEND"
block|,
literal|"SEEK"
block|,
literal|"RETURN"
block|,
literal|"REDO"
block|,
literal|"NEXT"
block|,
literal|"LAST"
block|,
literal|"DUMP"
block|,
literal|"GOTO"
block|,
comment|/* shudder */
literal|"INDEX"
block|,
literal|"RINDEX"
block|,
literal|"TIME"
block|,
literal|"TIMES"
block|,
literal|"LOCALTIME"
block|,
literal|"GMTIME"
block|,
literal|"TRUNCATE"
block|,
literal|"LSTAT"
block|,
literal|"STAT"
block|,
literal|"CRYPT"
block|,
literal|"ATAN2"
block|,
literal|"SIN"
block|,
literal|"COS"
block|,
literal|"RAND"
block|,
literal|"SRAND"
block|,
literal|"EXP"
block|,
literal|"LOG"
block|,
literal|"SQRT"
block|,
literal|"INT"
block|,
literal|"ORD"
block|,
literal|"ALARM"
block|,
literal|"SLEEP"
block|,
literal|"RANGE"
block|,
literal|"FLIP_OR_RANGE"
block|,
literal|"FLIP"
block|,
literal|"FLOP"
block|,
literal|"FORK"
block|,
literal|"WAIT"
block|,
literal|"WAITPID"
block|,
literal|"SYSTEM"
block|,
literal|"EXEC"
block|,
literal|"HEX"
block|,
literal|"OCT"
block|,
literal|"CHOWN"
block|,
literal|"KILL"
block|,
literal|"UNLINK"
block|,
literal|"CHMOD"
block|,
literal|"UTIME"
block|,
literal|"UMASK"
block|,
literal|"MSGGET"
block|,
literal|"SHMGET"
block|,
literal|"SEMGET"
block|,
literal|"MSGCTL"
block|,
literal|"SHMCTL"
block|,
literal|"SEMCTL"
block|,
literal|"MSGSND"
block|,
literal|"MSGRCV"
block|,
literal|"SEMOP"
block|,
literal|"SHMREAD"
block|,
literal|"SHMWRITE"
block|,
literal|"RENAME"
block|,
literal|"LINK"
block|,
literal|"MKDIR"
block|,
literal|"RMDIR"
block|,
literal|"GETPPID"
block|,
literal|"GETPGRP"
block|,
literal|"SETPGRP"
block|,
literal|"GETPRIORITY"
block|,
literal|"SETPRIORITY"
block|,
literal|"CHROOT"
block|,
literal|"FCNTL"
block|,
literal|"SYSIOCTL"
block|,
literal|"FLOCK"
block|,
literal|"UNSHIFT"
block|,
literal|"REQUIRE"
block|,
literal|"DOFILE"
block|,
literal|"EVAL"
block|,
literal|"FTRREAD"
block|,
literal|"FTRWRITE"
block|,
literal|"FTREXEC"
block|,
literal|"FTEREAD"
block|,
literal|"FTEWRITE"
block|,
literal|"FTEEXEC"
block|,
literal|"FTIS"
block|,
literal|"FTEOWNED"
block|,
literal|"FTROWNED"
block|,
literal|"FTZERO"
block|,
literal|"FTSIZE"
block|,
literal|"FTMTIME"
block|,
literal|"FTATIME"
block|,
literal|"FTCTIME"
block|,
literal|"FTSOCK"
block|,
literal|"FTCHR"
block|,
literal|"FTBLK"
block|,
literal|"FTFILE"
block|,
literal|"FTDIR"
block|,
literal|"FTPIPE"
block|,
literal|"FTLINK"
block|,
literal|"SYMLINK"
block|,
literal|"READLINK"
block|,
literal|"FTSUID"
block|,
literal|"FTSGID"
block|,
literal|"FTSVTX"
block|,
literal|"FTTTY"
block|,
literal|"FTTEXT"
block|,
literal|"FTBINARY"
block|,
literal|"SOCKET"
block|,
literal|"BIND"
block|,
literal|"CONNECT"
block|,
literal|"LISTEN"
block|,
literal|"ACCEPT"
block|,
literal|"GHBYNAME"
block|,
literal|"GHBYADDR"
block|,
literal|"GHOSTENT"
block|,
literal|"GNBYNAME"
block|,
literal|"GNBYADDR"
block|,
literal|"GNETENT"
block|,
literal|"GPBYNAME"
block|,
literal|"GPBYNUMBER"
block|,
literal|"GPROTOENT"
block|,
literal|"GSBYNAME"
block|,
literal|"GSBYPORT"
block|,
literal|"GSERVENT"
block|,
literal|"SHOSTENT"
block|,
literal|"SNETENT"
block|,
literal|"SPROTOENT"
block|,
literal|"SSERVENT"
block|,
literal|"EHOSTENT"
block|,
literal|"ENETENT"
block|,
literal|"EPROTOENT"
block|,
literal|"ESERVENT"
block|,
literal|"SOCKPAIR"
block|,
literal|"SHUTDOWN"
block|,
literal|"GSOCKOPT"
block|,
literal|"SSOCKOPT"
block|,
literal|"GETSOCKNAME"
block|,
literal|"GETPEERNAME"
block|,
literal|"SSELECT"
block|,
literal|"FILENO"
block|,
literal|"BINMODE"
block|,
literal|"VEC"
block|,
literal|"GPWNAM"
block|,
literal|"GPWUID"
block|,
literal|"GPWENT"
block|,
literal|"SPWENT"
block|,
literal|"EPWENT"
block|,
literal|"GGRNAM"
block|,
literal|"GGRGID"
block|,
literal|"GGRENT"
block|,
literal|"SGRENT"
block|,
literal|"EGRENT"
block|,
literal|"GETLOGIN"
block|,
literal|"OPENDIR"
block|,
literal|"READDIR"
block|,
literal|"TELLDIR"
block|,
literal|"SEEKDIR"
block|,
literal|"REWINDDIR"
block|,
literal|"CLOSEDIR"
block|,
literal|"SYSCALL"
block|,
literal|"PIPE"
block|,
literal|"TRY"
block|,
literal|"EVALONCE"
block|,
literal|"269"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|A_NULL
value|0
end_define

begin_define
define|#
directive|define
name|A_EXPR
value|1
end_define

begin_define
define|#
directive|define
name|A_CMD
value|2
end_define

begin_define
define|#
directive|define
name|A_STAB
value|3
end_define

begin_define
define|#
directive|define
name|A_LVAL
value|4
end_define

begin_define
define|#
directive|define
name|A_SINGLE
value|5
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|6
end_define

begin_define
define|#
directive|define
name|A_BACKTICK
value|7
end_define

begin_define
define|#
directive|define
name|A_READ
value|8
end_define

begin_define
define|#
directive|define
name|A_SPAT
value|9
end_define

begin_define
define|#
directive|define
name|A_LEXPR
value|10
end_define

begin_define
define|#
directive|define
name|A_ARYLEN
value|11
end_define

begin_define
define|#
directive|define
name|A_ARYSTAB
value|12
end_define

begin_define
define|#
directive|define
name|A_LARYLEN
value|13
end_define

begin_define
define|#
directive|define
name|A_GLOB
value|14
end_define

begin_define
define|#
directive|define
name|A_WORD
value|15
end_define

begin_define
define|#
directive|define
name|A_INDREAD
value|16
end_define

begin_define
define|#
directive|define
name|A_LARYSTAB
value|17
end_define

begin_define
define|#
directive|define
name|A_STAR
value|18
end_define

begin_define
define|#
directive|define
name|A_LSTAR
value|19
end_define

begin_define
define|#
directive|define
name|A_WANTARRAY
value|20
end_define

begin_define
define|#
directive|define
name|A_LENSTAB
value|21
end_define

begin_define
define|#
directive|define
name|A_MASK
value|31
end_define

begin_define
define|#
directive|define
name|A_DONT
value|32
end_define

begin_comment
comment|/* or this into type to suppress evaluation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|argname
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|argname
index|[]
init|=
block|{
literal|"A_NULL"
block|,
literal|"EXPR"
block|,
literal|"CMD"
block|,
literal|"STAB"
block|,
literal|"LVAL"
block|,
literal|"LITERAL"
block|,
literal|"DOUBLEQUOTE"
block|,
literal|"BACKTICK"
block|,
literal|"READ"
block|,
literal|"SPAT"
block|,
literal|"LEXPR"
block|,
literal|"ARYLEN"
block|,
literal|"ARYSTAB"
block|,
literal|"LARYLEN"
block|,
literal|"GLOB"
block|,
literal|"WORD"
block|,
literal|"INDREAD"
block|,
literal|"LARYSTAB"
block|,
literal|"STAR"
block|,
literal|"LSTAR"
block|,
literal|"WANTARRAY"
block|,
literal|"LENSTAB"
block|,
literal|"22"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|bool
name|hoistable
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|bool
name|hoistable
index|[]
init|=
block|{
literal|0
block|,
comment|/* A_NULL */
literal|0
block|,
comment|/* EXPR */
literal|1
block|,
comment|/* CMD */
literal|1
block|,
comment|/* STAB */
literal|0
block|,
comment|/* LVAL */
literal|1
block|,
comment|/* SINGLE */
literal|0
block|,
comment|/* DOUBLE */
literal|0
block|,
comment|/* BACKTICK */
literal|0
block|,
comment|/* READ */
literal|0
block|,
comment|/* SPAT */
literal|0
block|,
comment|/* LEXPR */
literal|1
block|,
comment|/* ARYLEN */
literal|1
block|,
comment|/* ARYSTAB */
literal|0
block|,
comment|/* LARYLEN */
literal|0
block|,
comment|/* GLOB */
literal|1
block|,
comment|/* WORD */
literal|0
block|,
comment|/* INDREAD */
literal|0
block|,
comment|/* LARYSTAB */
literal|1
block|,
comment|/* STAR */
literal|1
block|,
comment|/* LSTAR */
literal|1
block|,
comment|/* WANTARRAY */
literal|0
block|,
comment|/* LENSTAB */
literal|0
block|,
comment|/* 21 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|argptr
block|{
name|ARG
modifier|*
name|arg_arg
decl_stmt|;
name|char
modifier|*
name|arg_cval
decl_stmt|;
name|STAB
modifier|*
name|arg_stab
decl_stmt|;
name|SPAT
modifier|*
name|arg_spat
decl_stmt|;
name|CMD
modifier|*
name|arg_cmd
decl_stmt|;
name|STR
modifier|*
name|arg_str
decl_stmt|;
name|HASH
modifier|*
name|arg_hash
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|arg
block|{
name|union
name|argptr
name|arg_ptr
decl_stmt|;
name|short
name|arg_len
decl_stmt|;
name|unsigned
name|short
name|arg_type
decl_stmt|;
name|unsigned
name|short
name|arg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AF_ARYOK
value|1
end_define

begin_comment
comment|/* op can handle multiple values here */
end_comment

begin_define
define|#
directive|define
name|AF_POST
value|2
end_define

begin_comment
comment|/* post *crement this item */
end_comment

begin_define
define|#
directive|define
name|AF_PRE
value|4
end_define

begin_comment
comment|/* pre *crement this item */
end_comment

begin_define
define|#
directive|define
name|AF_UP
value|8
end_define

begin_comment
comment|/* increment rather than decrement */
end_comment

begin_define
define|#
directive|define
name|AF_COMMON
value|16
end_define

begin_comment
comment|/* left and right have symbols in common */
end_comment

begin_define
define|#
directive|define
name|AF_DEPR
value|32
end_define

begin_comment
comment|/* an older form of the construct */
end_comment

begin_define
define|#
directive|define
name|AF_LISTISH
value|64
end_define

begin_comment
comment|/* turn into list if important */
end_comment

begin_define
define|#
directive|define
name|AF_LOCAL_XX
value|128
end_define

begin_comment
comment|/* list of local variables */
end_comment

begin_comment
comment|/*  * Most of the ARG pointers are used as pointers to arrays of ARG.  When  * so used, the 0th element is special, and represents the operator to  * use on the list of arguments following.  The arg_len in the 0th element  * gives the maximum argument number, and the arg_str is used to store  * the return value in a more-or-less static location.  Sorry it's not  * re-entrant (yet), but it sure makes it efficient.  The arg_type of the  * 0th element is an operator (O_*) rather than an argument type (A_*).  */
end_comment

begin_define
define|#
directive|define
name|Nullarg
value|Null(ARG*)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXT
name|unsigned
name|short
name|opargs
index|[
name|MAXO
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A
parameter_list|(
name|e1
parameter_list|,
name|e2
parameter_list|,
name|e3
parameter_list|)
value|(e1+(e2<<2)+(e3<<4))
end_define

begin_define
define|#
directive|define
name|A5
parameter_list|(
name|e1
parameter_list|,
name|e2
parameter_list|,
name|e3
parameter_list|,
name|e4
parameter_list|,
name|e5
parameter_list|)
value|(e1+(e2<<2)+(e3<<4)+(e4<<6)+(e5<<8))
end_define

begin_decl_stmt
name|unsigned
name|short
name|opargs
index|[
name|MAXO
operator|+
literal|1
index|]
init|=
block|{
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NULL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RCAT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ITEM */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SCALAR */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ITEM2 */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ITEM3 */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CONCAT */
name|A
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* REPEAT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* MATCH */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NMATCH */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SUBST */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NSUBST */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ASSIGN */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LOCAL */
name|A
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* AASSIGN */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SASSIGN */
name|A
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CHOP */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DEFINED */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UNDEF */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* STUDY */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* POW */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* MULTIPLY */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DIVIDE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* MODULO */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ADD */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SUBTRACT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LEFT_SHIFT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RIGHT_SHIFT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EQ */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NCMP */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* BIT_AND */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* XOR */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* BIT_OR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* AND */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* OR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* COND_EXPR */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* COMMA */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NEGATE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NOT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* COMPLEMENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SELECT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* WRITE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* DBMOPEN */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DBMCLOSE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* OPEN */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TRANS */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NTRANS */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CLOSE */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EACH */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* VALUES */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* KEYS */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LARRAY */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ARRAY */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* AELEM */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DELETE */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LHASH */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* HASH */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* HELEM */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LAELEM */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LHELEM */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
block|,
comment|/* LSLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ASLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* HSLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LASLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LHSLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SPLICE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* PUSH */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* POP */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SHIFT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UNPACK */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SPLIT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LENGTH */
name|A
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SPRINTF */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SUBSTR */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* PACK */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GREP */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* JOIN */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SLT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SGT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SLE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SGE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SEQ */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SNE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SCMP */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SUBR */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DBSUBR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CALLER */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SORT */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* REVERSE */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* WARN */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DIE */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* PRINTF */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* PRINT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CHDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EXIT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RESET */
name|A
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LIST */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EOF */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETC */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TELL */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RECV */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
block|,
comment|/* READ */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
block|,
comment|/* SYSREAD */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
block|,
comment|/* SYSWRITE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
block|,
comment|/* SEND */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SEEK */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RETURN */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* REDO */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* NEXT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LAST */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DUMP */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GOTO */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* INDEX */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* RINDEX */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TIME */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TIMES */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LOCALTIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GMTIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TRUNCATE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LSTAT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* STAT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CRYPT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ATAN2 */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SIN */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* COS */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RAND */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SRAND */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EXP */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LOG */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SQRT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* INT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ORD */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ALARM */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SLEEP */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RANGE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* F_OR_R */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FLIP */
name|A
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FLOP */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FORK */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* WAIT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* WAITPID */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SYSTEM */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EXEC */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* HEX */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* OCT */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CHOWN */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* KILL */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UNLINK */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CHMOD */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UTIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UMASK */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* MSGGET */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SHMGET */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SEMGET */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* MSGCTL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SHMCTL */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SEMCTL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* MSGSND */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* MSGRCV */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SEMOP */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SHMREAD */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SHMWRITE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RENAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LINK */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* MKDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* RMDIR */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETPPID */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETPGRP */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SETPGRP */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETPRIORITY */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SETPRIORITY */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CHROOT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* FCNTL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SYSIOCTL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FLOCK */
name|A
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* UNSHIFT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* REQUIRE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* DOFILE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EVAL */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTRREAD */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTRWRITE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTREXEC */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTEREAD */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTEWRITE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTEEXEC */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTIS */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTEOWNED */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTROWNED */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTZERO */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTSIZE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTMTIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTATIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTCTIME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTSOCK */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTCHR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTBLK */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTFILE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTPIPE */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTLINK */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SYMLINK */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* READLINK */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTSUID */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTSGID */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTSVTX */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTTTY */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTTEXT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FTBINARY */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SOCKET */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* BIND */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CONNECT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* LISTEN */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ACCEPT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GHBYNAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GHBYADDR */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GHOSTENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GNBYNAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GNBYADDR */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GNETENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPBYNAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPBYNUMBER */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPROTOENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GSBYNAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GSBYPORT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GSERVENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SHOSTENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SNETENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SPROTOENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SSERVENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EHOSTENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ENETENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EPROTOENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* ESERVENT */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* SOCKPAIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SHUTDOWN */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* GSOCKOPT */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SSOCKOPT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETSOCKNAME */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETPEERNAME */
name|A5
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SSELECT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* FILENO */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* BINMODE */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
block|,
comment|/* VEC */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPWNAM */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPWUID */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GPWENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SPWENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EPWENT */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GGRNAM */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GGRGID */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GGRENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SGRENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EGRENT */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* GETLOGIN */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* OPENDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* READDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TELLDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SEEKDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* REWINDDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* CLOSEDIR */
name|A
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
block|,
comment|/* SYSCALL */
name|A
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
block|,
comment|/* PIPE */
name|A
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* TRY */
name|A
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
comment|/* EVALONCE */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|A
end_undef

begin_undef
undef|#
directive|undef
name|A5
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|do_trans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_split
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_eof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|do_tell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|do_seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_tms
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|do_push
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|nextargv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|do_fttext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_slice
parameter_list|()
function_decl|;
end_function_decl

end_unit

