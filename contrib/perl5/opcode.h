begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|pp_i_preinc
value|pp_preinc
end_define

begin_define
define|#
directive|define
name|pp_i_predec
value|pp_predec
end_define

begin_define
define|#
directive|define
name|pp_i_postinc
value|pp_postinc
end_define

begin_define
define|#
directive|define
name|pp_i_postdec
value|pp_postdec
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|OP_NULL
block|,
comment|/* 0 */
name|OP_STUB
block|,
comment|/* 1 */
name|OP_SCALAR
block|,
comment|/* 2 */
name|OP_PUSHMARK
block|,
comment|/* 3 */
name|OP_WANTARRAY
block|,
comment|/* 4 */
name|OP_CONST
block|,
comment|/* 5 */
name|OP_GVSV
block|,
comment|/* 6 */
name|OP_GV
block|,
comment|/* 7 */
name|OP_GELEM
block|,
comment|/* 8 */
name|OP_PADSV
block|,
comment|/* 9 */
name|OP_PADAV
block|,
comment|/* 10 */
name|OP_PADHV
block|,
comment|/* 11 */
name|OP_PADANY
block|,
comment|/* 12 */
name|OP_PUSHRE
block|,
comment|/* 13 */
name|OP_RV2GV
block|,
comment|/* 14 */
name|OP_RV2SV
block|,
comment|/* 15 */
name|OP_AV2ARYLEN
block|,
comment|/* 16 */
name|OP_RV2CV
block|,
comment|/* 17 */
name|OP_ANONCODE
block|,
comment|/* 18 */
name|OP_PROTOTYPE
block|,
comment|/* 19 */
name|OP_REFGEN
block|,
comment|/* 20 */
name|OP_SREFGEN
block|,
comment|/* 21 */
name|OP_REF
block|,
comment|/* 22 */
name|OP_BLESS
block|,
comment|/* 23 */
name|OP_BACKTICK
block|,
comment|/* 24 */
name|OP_GLOB
block|,
comment|/* 25 */
name|OP_READLINE
block|,
comment|/* 26 */
name|OP_RCATLINE
block|,
comment|/* 27 */
name|OP_REGCMAYBE
block|,
comment|/* 28 */
name|OP_REGCRESET
block|,
comment|/* 29 */
name|OP_REGCOMP
block|,
comment|/* 30 */
name|OP_MATCH
block|,
comment|/* 31 */
name|OP_QR
block|,
comment|/* 32 */
name|OP_SUBST
block|,
comment|/* 33 */
name|OP_SUBSTCONT
block|,
comment|/* 34 */
name|OP_TRANS
block|,
comment|/* 35 */
name|OP_SASSIGN
block|,
comment|/* 36 */
name|OP_AASSIGN
block|,
comment|/* 37 */
name|OP_CHOP
block|,
comment|/* 38 */
name|OP_SCHOP
block|,
comment|/* 39 */
name|OP_CHOMP
block|,
comment|/* 40 */
name|OP_SCHOMP
block|,
comment|/* 41 */
name|OP_DEFINED
block|,
comment|/* 42 */
name|OP_UNDEF
block|,
comment|/* 43 */
name|OP_STUDY
block|,
comment|/* 44 */
name|OP_POS
block|,
comment|/* 45 */
name|OP_PREINC
block|,
comment|/* 46 */
name|OP_I_PREINC
block|,
comment|/* 47 */
name|OP_PREDEC
block|,
comment|/* 48 */
name|OP_I_PREDEC
block|,
comment|/* 49 */
name|OP_POSTINC
block|,
comment|/* 50 */
name|OP_I_POSTINC
block|,
comment|/* 51 */
name|OP_POSTDEC
block|,
comment|/* 52 */
name|OP_I_POSTDEC
block|,
comment|/* 53 */
name|OP_POW
block|,
comment|/* 54 */
name|OP_MULTIPLY
block|,
comment|/* 55 */
name|OP_I_MULTIPLY
block|,
comment|/* 56 */
name|OP_DIVIDE
block|,
comment|/* 57 */
name|OP_I_DIVIDE
block|,
comment|/* 58 */
name|OP_MODULO
block|,
comment|/* 59 */
name|OP_I_MODULO
block|,
comment|/* 60 */
name|OP_REPEAT
block|,
comment|/* 61 */
name|OP_ADD
block|,
comment|/* 62 */
name|OP_I_ADD
block|,
comment|/* 63 */
name|OP_SUBTRACT
block|,
comment|/* 64 */
name|OP_I_SUBTRACT
block|,
comment|/* 65 */
name|OP_CONCAT
block|,
comment|/* 66 */
name|OP_STRINGIFY
block|,
comment|/* 67 */
name|OP_LEFT_SHIFT
block|,
comment|/* 68 */
name|OP_RIGHT_SHIFT
block|,
comment|/* 69 */
name|OP_LT
block|,
comment|/* 70 */
name|OP_I_LT
block|,
comment|/* 71 */
name|OP_GT
block|,
comment|/* 72 */
name|OP_I_GT
block|,
comment|/* 73 */
name|OP_LE
block|,
comment|/* 74 */
name|OP_I_LE
block|,
comment|/* 75 */
name|OP_GE
block|,
comment|/* 76 */
name|OP_I_GE
block|,
comment|/* 77 */
name|OP_EQ
block|,
comment|/* 78 */
name|OP_I_EQ
block|,
comment|/* 79 */
name|OP_NE
block|,
comment|/* 80 */
name|OP_I_NE
block|,
comment|/* 81 */
name|OP_NCMP
block|,
comment|/* 82 */
name|OP_I_NCMP
block|,
comment|/* 83 */
name|OP_SLT
block|,
comment|/* 84 */
name|OP_SGT
block|,
comment|/* 85 */
name|OP_SLE
block|,
comment|/* 86 */
name|OP_SGE
block|,
comment|/* 87 */
name|OP_SEQ
block|,
comment|/* 88 */
name|OP_SNE
block|,
comment|/* 89 */
name|OP_SCMP
block|,
comment|/* 90 */
name|OP_BIT_AND
block|,
comment|/* 91 */
name|OP_BIT_XOR
block|,
comment|/* 92 */
name|OP_BIT_OR
block|,
comment|/* 93 */
name|OP_NEGATE
block|,
comment|/* 94 */
name|OP_I_NEGATE
block|,
comment|/* 95 */
name|OP_NOT
block|,
comment|/* 96 */
name|OP_COMPLEMENT
block|,
comment|/* 97 */
name|OP_ATAN2
block|,
comment|/* 98 */
name|OP_SIN
block|,
comment|/* 99 */
name|OP_COS
block|,
comment|/* 100 */
name|OP_RAND
block|,
comment|/* 101 */
name|OP_SRAND
block|,
comment|/* 102 */
name|OP_EXP
block|,
comment|/* 103 */
name|OP_LOG
block|,
comment|/* 104 */
name|OP_SQRT
block|,
comment|/* 105 */
name|OP_INT
block|,
comment|/* 106 */
name|OP_HEX
block|,
comment|/* 107 */
name|OP_OCT
block|,
comment|/* 108 */
name|OP_ABS
block|,
comment|/* 109 */
name|OP_LENGTH
block|,
comment|/* 110 */
name|OP_SUBSTR
block|,
comment|/* 111 */
name|OP_VEC
block|,
comment|/* 112 */
name|OP_INDEX
block|,
comment|/* 113 */
name|OP_RINDEX
block|,
comment|/* 114 */
name|OP_SPRINTF
block|,
comment|/* 115 */
name|OP_FORMLINE
block|,
comment|/* 116 */
name|OP_ORD
block|,
comment|/* 117 */
name|OP_CHR
block|,
comment|/* 118 */
name|OP_CRYPT
block|,
comment|/* 119 */
name|OP_UCFIRST
block|,
comment|/* 120 */
name|OP_LCFIRST
block|,
comment|/* 121 */
name|OP_UC
block|,
comment|/* 122 */
name|OP_LC
block|,
comment|/* 123 */
name|OP_QUOTEMETA
block|,
comment|/* 124 */
name|OP_RV2AV
block|,
comment|/* 125 */
name|OP_AELEMFAST
block|,
comment|/* 126 */
name|OP_AELEM
block|,
comment|/* 127 */
name|OP_ASLICE
block|,
comment|/* 128 */
name|OP_EACH
block|,
comment|/* 129 */
name|OP_VALUES
block|,
comment|/* 130 */
name|OP_KEYS
block|,
comment|/* 131 */
name|OP_DELETE
block|,
comment|/* 132 */
name|OP_EXISTS
block|,
comment|/* 133 */
name|OP_RV2HV
block|,
comment|/* 134 */
name|OP_HELEM
block|,
comment|/* 135 */
name|OP_HSLICE
block|,
comment|/* 136 */
name|OP_UNPACK
block|,
comment|/* 137 */
name|OP_PACK
block|,
comment|/* 138 */
name|OP_SPLIT
block|,
comment|/* 139 */
name|OP_JOIN
block|,
comment|/* 140 */
name|OP_LIST
block|,
comment|/* 141 */
name|OP_LSLICE
block|,
comment|/* 142 */
name|OP_ANONLIST
block|,
comment|/* 143 */
name|OP_ANONHASH
block|,
comment|/* 144 */
name|OP_SPLICE
block|,
comment|/* 145 */
name|OP_PUSH
block|,
comment|/* 146 */
name|OP_POP
block|,
comment|/* 147 */
name|OP_SHIFT
block|,
comment|/* 148 */
name|OP_UNSHIFT
block|,
comment|/* 149 */
name|OP_SORT
block|,
comment|/* 150 */
name|OP_REVERSE
block|,
comment|/* 151 */
name|OP_GREPSTART
block|,
comment|/* 152 */
name|OP_GREPWHILE
block|,
comment|/* 153 */
name|OP_MAPSTART
block|,
comment|/* 154 */
name|OP_MAPWHILE
block|,
comment|/* 155 */
name|OP_RANGE
block|,
comment|/* 156 */
name|OP_FLIP
block|,
comment|/* 157 */
name|OP_FLOP
block|,
comment|/* 158 */
name|OP_AND
block|,
comment|/* 159 */
name|OP_OR
block|,
comment|/* 160 */
name|OP_XOR
block|,
comment|/* 161 */
name|OP_COND_EXPR
block|,
comment|/* 162 */
name|OP_ANDASSIGN
block|,
comment|/* 163 */
name|OP_ORASSIGN
block|,
comment|/* 164 */
name|OP_METHOD
block|,
comment|/* 165 */
name|OP_ENTERSUB
block|,
comment|/* 166 */
name|OP_LEAVESUB
block|,
comment|/* 167 */
name|OP_CALLER
block|,
comment|/* 168 */
name|OP_WARN
block|,
comment|/* 169 */
name|OP_DIE
block|,
comment|/* 170 */
name|OP_RESET
block|,
comment|/* 171 */
name|OP_LINESEQ
block|,
comment|/* 172 */
name|OP_NEXTSTATE
block|,
comment|/* 173 */
name|OP_DBSTATE
block|,
comment|/* 174 */
name|OP_UNSTACK
block|,
comment|/* 175 */
name|OP_ENTER
block|,
comment|/* 176 */
name|OP_LEAVE
block|,
comment|/* 177 */
name|OP_SCOPE
block|,
comment|/* 178 */
name|OP_ENTERITER
block|,
comment|/* 179 */
name|OP_ITER
block|,
comment|/* 180 */
name|OP_ENTERLOOP
block|,
comment|/* 181 */
name|OP_LEAVELOOP
block|,
comment|/* 182 */
name|OP_RETURN
block|,
comment|/* 183 */
name|OP_LAST
block|,
comment|/* 184 */
name|OP_NEXT
block|,
comment|/* 185 */
name|OP_REDO
block|,
comment|/* 186 */
name|OP_DUMP
block|,
comment|/* 187 */
name|OP_GOTO
block|,
comment|/* 188 */
name|OP_EXIT
block|,
comment|/* 189 */
name|OP_OPEN
block|,
comment|/* 190 */
name|OP_CLOSE
block|,
comment|/* 191 */
name|OP_PIPE_OP
block|,
comment|/* 192 */
name|OP_FILENO
block|,
comment|/* 193 */
name|OP_UMASK
block|,
comment|/* 194 */
name|OP_BINMODE
block|,
comment|/* 195 */
name|OP_TIE
block|,
comment|/* 196 */
name|OP_UNTIE
block|,
comment|/* 197 */
name|OP_TIED
block|,
comment|/* 198 */
name|OP_DBMOPEN
block|,
comment|/* 199 */
name|OP_DBMCLOSE
block|,
comment|/* 200 */
name|OP_SSELECT
block|,
comment|/* 201 */
name|OP_SELECT
block|,
comment|/* 202 */
name|OP_GETC
block|,
comment|/* 203 */
name|OP_READ
block|,
comment|/* 204 */
name|OP_ENTERWRITE
block|,
comment|/* 205 */
name|OP_LEAVEWRITE
block|,
comment|/* 206 */
name|OP_PRTF
block|,
comment|/* 207 */
name|OP_PRINT
block|,
comment|/* 208 */
name|OP_SYSOPEN
block|,
comment|/* 209 */
name|OP_SYSSEEK
block|,
comment|/* 210 */
name|OP_SYSREAD
block|,
comment|/* 211 */
name|OP_SYSWRITE
block|,
comment|/* 212 */
name|OP_SEND
block|,
comment|/* 213 */
name|OP_RECV
block|,
comment|/* 214 */
name|OP_EOF
block|,
comment|/* 215 */
name|OP_TELL
block|,
comment|/* 216 */
name|OP_SEEK
block|,
comment|/* 217 */
name|OP_TRUNCATE
block|,
comment|/* 218 */
name|OP_FCNTL
block|,
comment|/* 219 */
name|OP_IOCTL
block|,
comment|/* 220 */
name|OP_FLOCK
block|,
comment|/* 221 */
name|OP_SOCKET
block|,
comment|/* 222 */
name|OP_SOCKPAIR
block|,
comment|/* 223 */
name|OP_BIND
block|,
comment|/* 224 */
name|OP_CONNECT
block|,
comment|/* 225 */
name|OP_LISTEN
block|,
comment|/* 226 */
name|OP_ACCEPT
block|,
comment|/* 227 */
name|OP_SHUTDOWN
block|,
comment|/* 228 */
name|OP_GSOCKOPT
block|,
comment|/* 229 */
name|OP_SSOCKOPT
block|,
comment|/* 230 */
name|OP_GETSOCKNAME
block|,
comment|/* 231 */
name|OP_GETPEERNAME
block|,
comment|/* 232 */
name|OP_LSTAT
block|,
comment|/* 233 */
name|OP_STAT
block|,
comment|/* 234 */
name|OP_FTRREAD
block|,
comment|/* 235 */
name|OP_FTRWRITE
block|,
comment|/* 236 */
name|OP_FTREXEC
block|,
comment|/* 237 */
name|OP_FTEREAD
block|,
comment|/* 238 */
name|OP_FTEWRITE
block|,
comment|/* 239 */
name|OP_FTEEXEC
block|,
comment|/* 240 */
name|OP_FTIS
block|,
comment|/* 241 */
name|OP_FTEOWNED
block|,
comment|/* 242 */
name|OP_FTROWNED
block|,
comment|/* 243 */
name|OP_FTZERO
block|,
comment|/* 244 */
name|OP_FTSIZE
block|,
comment|/* 245 */
name|OP_FTMTIME
block|,
comment|/* 246 */
name|OP_FTATIME
block|,
comment|/* 247 */
name|OP_FTCTIME
block|,
comment|/* 248 */
name|OP_FTSOCK
block|,
comment|/* 249 */
name|OP_FTCHR
block|,
comment|/* 250 */
name|OP_FTBLK
block|,
comment|/* 251 */
name|OP_FTFILE
block|,
comment|/* 252 */
name|OP_FTDIR
block|,
comment|/* 253 */
name|OP_FTPIPE
block|,
comment|/* 254 */
name|OP_FTLINK
block|,
comment|/* 255 */
name|OP_FTSUID
block|,
comment|/* 256 */
name|OP_FTSGID
block|,
comment|/* 257 */
name|OP_FTSVTX
block|,
comment|/* 258 */
name|OP_FTTTY
block|,
comment|/* 259 */
name|OP_FTTEXT
block|,
comment|/* 260 */
name|OP_FTBINARY
block|,
comment|/* 261 */
name|OP_CHDIR
block|,
comment|/* 262 */
name|OP_CHOWN
block|,
comment|/* 263 */
name|OP_CHROOT
block|,
comment|/* 264 */
name|OP_UNLINK
block|,
comment|/* 265 */
name|OP_CHMOD
block|,
comment|/* 266 */
name|OP_UTIME
block|,
comment|/* 267 */
name|OP_RENAME
block|,
comment|/* 268 */
name|OP_LINK
block|,
comment|/* 269 */
name|OP_SYMLINK
block|,
comment|/* 270 */
name|OP_READLINK
block|,
comment|/* 271 */
name|OP_MKDIR
block|,
comment|/* 272 */
name|OP_RMDIR
block|,
comment|/* 273 */
name|OP_OPEN_DIR
block|,
comment|/* 274 */
name|OP_READDIR
block|,
comment|/* 275 */
name|OP_TELLDIR
block|,
comment|/* 276 */
name|OP_SEEKDIR
block|,
comment|/* 277 */
name|OP_REWINDDIR
block|,
comment|/* 278 */
name|OP_CLOSEDIR
block|,
comment|/* 279 */
name|OP_FORK
block|,
comment|/* 280 */
name|OP_WAIT
block|,
comment|/* 281 */
name|OP_WAITPID
block|,
comment|/* 282 */
name|OP_SYSTEM
block|,
comment|/* 283 */
name|OP_EXEC
block|,
comment|/* 284 */
name|OP_KILL
block|,
comment|/* 285 */
name|OP_GETPPID
block|,
comment|/* 286 */
name|OP_GETPGRP
block|,
comment|/* 287 */
name|OP_SETPGRP
block|,
comment|/* 288 */
name|OP_GETPRIORITY
block|,
comment|/* 289 */
name|OP_SETPRIORITY
block|,
comment|/* 290 */
name|OP_TIME
block|,
comment|/* 291 */
name|OP_TMS
block|,
comment|/* 292 */
name|OP_LOCALTIME
block|,
comment|/* 293 */
name|OP_GMTIME
block|,
comment|/* 294 */
name|OP_ALARM
block|,
comment|/* 295 */
name|OP_SLEEP
block|,
comment|/* 296 */
name|OP_SHMGET
block|,
comment|/* 297 */
name|OP_SHMCTL
block|,
comment|/* 298 */
name|OP_SHMREAD
block|,
comment|/* 299 */
name|OP_SHMWRITE
block|,
comment|/* 300 */
name|OP_MSGGET
block|,
comment|/* 301 */
name|OP_MSGCTL
block|,
comment|/* 302 */
name|OP_MSGSND
block|,
comment|/* 303 */
name|OP_MSGRCV
block|,
comment|/* 304 */
name|OP_SEMGET
block|,
comment|/* 305 */
name|OP_SEMCTL
block|,
comment|/* 306 */
name|OP_SEMOP
block|,
comment|/* 307 */
name|OP_REQUIRE
block|,
comment|/* 308 */
name|OP_DOFILE
block|,
comment|/* 309 */
name|OP_ENTEREVAL
block|,
comment|/* 310 */
name|OP_LEAVEEVAL
block|,
comment|/* 311 */
name|OP_ENTERTRY
block|,
comment|/* 312 */
name|OP_LEAVETRY
block|,
comment|/* 313 */
name|OP_GHBYNAME
block|,
comment|/* 314 */
name|OP_GHBYADDR
block|,
comment|/* 315 */
name|OP_GHOSTENT
block|,
comment|/* 316 */
name|OP_GNBYNAME
block|,
comment|/* 317 */
name|OP_GNBYADDR
block|,
comment|/* 318 */
name|OP_GNETENT
block|,
comment|/* 319 */
name|OP_GPBYNAME
block|,
comment|/* 320 */
name|OP_GPBYNUMBER
block|,
comment|/* 321 */
name|OP_GPROTOENT
block|,
comment|/* 322 */
name|OP_GSBYNAME
block|,
comment|/* 323 */
name|OP_GSBYPORT
block|,
comment|/* 324 */
name|OP_GSERVENT
block|,
comment|/* 325 */
name|OP_SHOSTENT
block|,
comment|/* 326 */
name|OP_SNETENT
block|,
comment|/* 327 */
name|OP_SPROTOENT
block|,
comment|/* 328 */
name|OP_SSERVENT
block|,
comment|/* 329 */
name|OP_EHOSTENT
block|,
comment|/* 330 */
name|OP_ENETENT
block|,
comment|/* 331 */
name|OP_EPROTOENT
block|,
comment|/* 332 */
name|OP_ESERVENT
block|,
comment|/* 333 */
name|OP_GPWNAM
block|,
comment|/* 334 */
name|OP_GPWUID
block|,
comment|/* 335 */
name|OP_GPWENT
block|,
comment|/* 336 */
name|OP_SPWENT
block|,
comment|/* 337 */
name|OP_EPWENT
block|,
comment|/* 338 */
name|OP_GGRNAM
block|,
comment|/* 339 */
name|OP_GGRGID
block|,
comment|/* 340 */
name|OP_GGRENT
block|,
comment|/* 341 */
name|OP_SGRENT
block|,
comment|/* 342 */
name|OP_EGRENT
block|,
comment|/* 343 */
name|OP_GETLOGIN
block|,
comment|/* 344 */
name|OP_SYSCALL
block|,
comment|/* 345 */
name|OP_LOCK
block|,
comment|/* 346 */
name|OP_THREADSV
block|,
comment|/* 347 */
name|OP_max
block|}
name|opcode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXO
value|348
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
name|EXT
name|char
modifier|*
name|op_name
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|char
modifier|*
name|op_name
index|[]
init|=
block|{
literal|"null"
block|,
literal|"stub"
block|,
literal|"scalar"
block|,
literal|"pushmark"
block|,
literal|"wantarray"
block|,
literal|"const"
block|,
literal|"gvsv"
block|,
literal|"gv"
block|,
literal|"gelem"
block|,
literal|"padsv"
block|,
literal|"padav"
block|,
literal|"padhv"
block|,
literal|"padany"
block|,
literal|"pushre"
block|,
literal|"rv2gv"
block|,
literal|"rv2sv"
block|,
literal|"av2arylen"
block|,
literal|"rv2cv"
block|,
literal|"anoncode"
block|,
literal|"prototype"
block|,
literal|"refgen"
block|,
literal|"srefgen"
block|,
literal|"ref"
block|,
literal|"bless"
block|,
literal|"backtick"
block|,
literal|"glob"
block|,
literal|"readline"
block|,
literal|"rcatline"
block|,
literal|"regcmaybe"
block|,
literal|"regcreset"
block|,
literal|"regcomp"
block|,
literal|"match"
block|,
literal|"qr"
block|,
literal|"subst"
block|,
literal|"substcont"
block|,
literal|"trans"
block|,
literal|"sassign"
block|,
literal|"aassign"
block|,
literal|"chop"
block|,
literal|"schop"
block|,
literal|"chomp"
block|,
literal|"schomp"
block|,
literal|"defined"
block|,
literal|"undef"
block|,
literal|"study"
block|,
literal|"pos"
block|,
literal|"preinc"
block|,
literal|"i_preinc"
block|,
literal|"predec"
block|,
literal|"i_predec"
block|,
literal|"postinc"
block|,
literal|"i_postinc"
block|,
literal|"postdec"
block|,
literal|"i_postdec"
block|,
literal|"pow"
block|,
literal|"multiply"
block|,
literal|"i_multiply"
block|,
literal|"divide"
block|,
literal|"i_divide"
block|,
literal|"modulo"
block|,
literal|"i_modulo"
block|,
literal|"repeat"
block|,
literal|"add"
block|,
literal|"i_add"
block|,
literal|"subtract"
block|,
literal|"i_subtract"
block|,
literal|"concat"
block|,
literal|"stringify"
block|,
literal|"left_shift"
block|,
literal|"right_shift"
block|,
literal|"lt"
block|,
literal|"i_lt"
block|,
literal|"gt"
block|,
literal|"i_gt"
block|,
literal|"le"
block|,
literal|"i_le"
block|,
literal|"ge"
block|,
literal|"i_ge"
block|,
literal|"eq"
block|,
literal|"i_eq"
block|,
literal|"ne"
block|,
literal|"i_ne"
block|,
literal|"ncmp"
block|,
literal|"i_ncmp"
block|,
literal|"slt"
block|,
literal|"sgt"
block|,
literal|"sle"
block|,
literal|"sge"
block|,
literal|"seq"
block|,
literal|"sne"
block|,
literal|"scmp"
block|,
literal|"bit_and"
block|,
literal|"bit_xor"
block|,
literal|"bit_or"
block|,
literal|"negate"
block|,
literal|"i_negate"
block|,
literal|"not"
block|,
literal|"complement"
block|,
literal|"atan2"
block|,
literal|"sin"
block|,
literal|"cos"
block|,
literal|"rand"
block|,
literal|"srand"
block|,
literal|"exp"
block|,
literal|"log"
block|,
literal|"sqrt"
block|,
literal|"int"
block|,
literal|"hex"
block|,
literal|"oct"
block|,
literal|"abs"
block|,
literal|"length"
block|,
literal|"substr"
block|,
literal|"vec"
block|,
literal|"index"
block|,
literal|"rindex"
block|,
literal|"sprintf"
block|,
literal|"formline"
block|,
literal|"ord"
block|,
literal|"chr"
block|,
literal|"crypt"
block|,
literal|"ucfirst"
block|,
literal|"lcfirst"
block|,
literal|"uc"
block|,
literal|"lc"
block|,
literal|"quotemeta"
block|,
literal|"rv2av"
block|,
literal|"aelemfast"
block|,
literal|"aelem"
block|,
literal|"aslice"
block|,
literal|"each"
block|,
literal|"values"
block|,
literal|"keys"
block|,
literal|"delete"
block|,
literal|"exists"
block|,
literal|"rv2hv"
block|,
literal|"helem"
block|,
literal|"hslice"
block|,
literal|"unpack"
block|,
literal|"pack"
block|,
literal|"split"
block|,
literal|"join"
block|,
literal|"list"
block|,
literal|"lslice"
block|,
literal|"anonlist"
block|,
literal|"anonhash"
block|,
literal|"splice"
block|,
literal|"push"
block|,
literal|"pop"
block|,
literal|"shift"
block|,
literal|"unshift"
block|,
literal|"sort"
block|,
literal|"reverse"
block|,
literal|"grepstart"
block|,
literal|"grepwhile"
block|,
literal|"mapstart"
block|,
literal|"mapwhile"
block|,
literal|"range"
block|,
literal|"flip"
block|,
literal|"flop"
block|,
literal|"and"
block|,
literal|"or"
block|,
literal|"xor"
block|,
literal|"cond_expr"
block|,
literal|"andassign"
block|,
literal|"orassign"
block|,
literal|"method"
block|,
literal|"entersub"
block|,
literal|"leavesub"
block|,
literal|"caller"
block|,
literal|"warn"
block|,
literal|"die"
block|,
literal|"reset"
block|,
literal|"lineseq"
block|,
literal|"nextstate"
block|,
literal|"dbstate"
block|,
literal|"unstack"
block|,
literal|"enter"
block|,
literal|"leave"
block|,
literal|"scope"
block|,
literal|"enteriter"
block|,
literal|"iter"
block|,
literal|"enterloop"
block|,
literal|"leaveloop"
block|,
literal|"return"
block|,
literal|"last"
block|,
literal|"next"
block|,
literal|"redo"
block|,
literal|"dump"
block|,
literal|"goto"
block|,
literal|"exit"
block|,
literal|"open"
block|,
literal|"close"
block|,
literal|"pipe_op"
block|,
literal|"fileno"
block|,
literal|"umask"
block|,
literal|"binmode"
block|,
literal|"tie"
block|,
literal|"untie"
block|,
literal|"tied"
block|,
literal|"dbmopen"
block|,
literal|"dbmclose"
block|,
literal|"sselect"
block|,
literal|"select"
block|,
literal|"getc"
block|,
literal|"read"
block|,
literal|"enterwrite"
block|,
literal|"leavewrite"
block|,
literal|"prtf"
block|,
literal|"print"
block|,
literal|"sysopen"
block|,
literal|"sysseek"
block|,
literal|"sysread"
block|,
literal|"syswrite"
block|,
literal|"send"
block|,
literal|"recv"
block|,
literal|"eof"
block|,
literal|"tell"
block|,
literal|"seek"
block|,
literal|"truncate"
block|,
literal|"fcntl"
block|,
literal|"ioctl"
block|,
literal|"flock"
block|,
literal|"socket"
block|,
literal|"sockpair"
block|,
literal|"bind"
block|,
literal|"connect"
block|,
literal|"listen"
block|,
literal|"accept"
block|,
literal|"shutdown"
block|,
literal|"gsockopt"
block|,
literal|"ssockopt"
block|,
literal|"getsockname"
block|,
literal|"getpeername"
block|,
literal|"lstat"
block|,
literal|"stat"
block|,
literal|"ftrread"
block|,
literal|"ftrwrite"
block|,
literal|"ftrexec"
block|,
literal|"fteread"
block|,
literal|"ftewrite"
block|,
literal|"fteexec"
block|,
literal|"ftis"
block|,
literal|"fteowned"
block|,
literal|"ftrowned"
block|,
literal|"ftzero"
block|,
literal|"ftsize"
block|,
literal|"ftmtime"
block|,
literal|"ftatime"
block|,
literal|"ftctime"
block|,
literal|"ftsock"
block|,
literal|"ftchr"
block|,
literal|"ftblk"
block|,
literal|"ftfile"
block|,
literal|"ftdir"
block|,
literal|"ftpipe"
block|,
literal|"ftlink"
block|,
literal|"ftsuid"
block|,
literal|"ftsgid"
block|,
literal|"ftsvtx"
block|,
literal|"fttty"
block|,
literal|"fttext"
block|,
literal|"ftbinary"
block|,
literal|"chdir"
block|,
literal|"chown"
block|,
literal|"chroot"
block|,
literal|"unlink"
block|,
literal|"chmod"
block|,
literal|"utime"
block|,
literal|"rename"
block|,
literal|"link"
block|,
literal|"symlink"
block|,
literal|"readlink"
block|,
literal|"mkdir"
block|,
literal|"rmdir"
block|,
literal|"open_dir"
block|,
literal|"readdir"
block|,
literal|"telldir"
block|,
literal|"seekdir"
block|,
literal|"rewinddir"
block|,
literal|"closedir"
block|,
literal|"fork"
block|,
literal|"wait"
block|,
literal|"waitpid"
block|,
literal|"system"
block|,
literal|"exec"
block|,
literal|"kill"
block|,
literal|"getppid"
block|,
literal|"getpgrp"
block|,
literal|"setpgrp"
block|,
literal|"getpriority"
block|,
literal|"setpriority"
block|,
literal|"time"
block|,
literal|"tms"
block|,
literal|"localtime"
block|,
literal|"gmtime"
block|,
literal|"alarm"
block|,
literal|"sleep"
block|,
literal|"shmget"
block|,
literal|"shmctl"
block|,
literal|"shmread"
block|,
literal|"shmwrite"
block|,
literal|"msgget"
block|,
literal|"msgctl"
block|,
literal|"msgsnd"
block|,
literal|"msgrcv"
block|,
literal|"semget"
block|,
literal|"semctl"
block|,
literal|"semop"
block|,
literal|"require"
block|,
literal|"dofile"
block|,
literal|"entereval"
block|,
literal|"leaveeval"
block|,
literal|"entertry"
block|,
literal|"leavetry"
block|,
literal|"ghbyname"
block|,
literal|"ghbyaddr"
block|,
literal|"ghostent"
block|,
literal|"gnbyname"
block|,
literal|"gnbyaddr"
block|,
literal|"gnetent"
block|,
literal|"gpbyname"
block|,
literal|"gpbynumber"
block|,
literal|"gprotoent"
block|,
literal|"gsbyname"
block|,
literal|"gsbyport"
block|,
literal|"gservent"
block|,
literal|"shostent"
block|,
literal|"snetent"
block|,
literal|"sprotoent"
block|,
literal|"sservent"
block|,
literal|"ehostent"
block|,
literal|"enetent"
block|,
literal|"eprotoent"
block|,
literal|"eservent"
block|,
literal|"gpwnam"
block|,
literal|"gpwuid"
block|,
literal|"gpwent"
block|,
literal|"spwent"
block|,
literal|"epwent"
block|,
literal|"ggrnam"
block|,
literal|"ggrgid"
block|,
literal|"ggrent"
block|,
literal|"sgrent"
block|,
literal|"egrent"
block|,
literal|"getlogin"
block|,
literal|"syscall"
block|,
literal|"lock"
block|,
literal|"threadsv"
block|, }
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
name|EXT
name|char
modifier|*
name|op_desc
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|char
modifier|*
name|op_desc
index|[]
init|=
block|{
literal|"null operation"
block|,
literal|"stub"
block|,
literal|"scalar"
block|,
literal|"pushmark"
block|,
literal|"wantarray"
block|,
literal|"constant item"
block|,
literal|"scalar variable"
block|,
literal|"glob value"
block|,
literal|"glob elem"
block|,
literal|"private variable"
block|,
literal|"private array"
block|,
literal|"private hash"
block|,
literal|"private something"
block|,
literal|"push regexp"
block|,
literal|"ref-to-glob cast"
block|,
literal|"scalar deref"
block|,
literal|"array length"
block|,
literal|"subroutine deref"
block|,
literal|"anonymous subroutine"
block|,
literal|"subroutine prototype"
block|,
literal|"reference constructor"
block|,
literal|"scalar ref constructor"
block|,
literal|"reference-type operator"
block|,
literal|"bless"
block|,
literal|"backticks"
block|,
literal|"glob"
block|,
literal|"<HANDLE>"
block|,
literal|"append I/O operator"
block|,
literal|"regexp comp once"
block|,
literal|"regexp reset interpolation flag"
block|,
literal|"regexp compilation"
block|,
literal|"pattern match"
block|,
literal|"pattern quote"
block|,
literal|"substitution"
block|,
literal|"substitution cont"
block|,
literal|"character translation"
block|,
literal|"scalar assignment"
block|,
literal|"list assignment"
block|,
literal|"chop"
block|,
literal|"scalar chop"
block|,
literal|"safe chop"
block|,
literal|"scalar safe chop"
block|,
literal|"defined operator"
block|,
literal|"undef operator"
block|,
literal|"study"
block|,
literal|"match position"
block|,
literal|"preincrement"
block|,
literal|"integer preincrement"
block|,
literal|"predecrement"
block|,
literal|"integer predecrement"
block|,
literal|"postincrement"
block|,
literal|"integer postincrement"
block|,
literal|"postdecrement"
block|,
literal|"integer postdecrement"
block|,
literal|"exponentiation"
block|,
literal|"multiplication"
block|,
literal|"integer multiplication"
block|,
literal|"division"
block|,
literal|"integer division"
block|,
literal|"modulus"
block|,
literal|"integer modulus"
block|,
literal|"repeat"
block|,
literal|"addition"
block|,
literal|"integer addition"
block|,
literal|"subtraction"
block|,
literal|"integer subtraction"
block|,
literal|"concatenation"
block|,
literal|"string"
block|,
literal|"left bitshift"
block|,
literal|"right bitshift"
block|,
literal|"numeric lt"
block|,
literal|"integer lt"
block|,
literal|"numeric gt"
block|,
literal|"integer gt"
block|,
literal|"numeric le"
block|,
literal|"integer le"
block|,
literal|"numeric ge"
block|,
literal|"integer ge"
block|,
literal|"numeric eq"
block|,
literal|"integer eq"
block|,
literal|"numeric ne"
block|,
literal|"integer ne"
block|,
literal|"spaceship operator"
block|,
literal|"integer spaceship"
block|,
literal|"string lt"
block|,
literal|"string gt"
block|,
literal|"string le"
block|,
literal|"string ge"
block|,
literal|"string eq"
block|,
literal|"string ne"
block|,
literal|"string comparison"
block|,
literal|"bitwise and"
block|,
literal|"bitwise xor"
block|,
literal|"bitwise or"
block|,
literal|"negate"
block|,
literal|"integer negate"
block|,
literal|"not"
block|,
literal|"1's complement"
block|,
literal|"atan2"
block|,
literal|"sin"
block|,
literal|"cos"
block|,
literal|"rand"
block|,
literal|"srand"
block|,
literal|"exp"
block|,
literal|"log"
block|,
literal|"sqrt"
block|,
literal|"int"
block|,
literal|"hex"
block|,
literal|"oct"
block|,
literal|"abs"
block|,
literal|"length"
block|,
literal|"substr"
block|,
literal|"vec"
block|,
literal|"index"
block|,
literal|"rindex"
block|,
literal|"sprintf"
block|,
literal|"formline"
block|,
literal|"ord"
block|,
literal|"chr"
block|,
literal|"crypt"
block|,
literal|"upper case first"
block|,
literal|"lower case first"
block|,
literal|"upper case"
block|,
literal|"lower case"
block|,
literal|"quote metachars"
block|,
literal|"array deref"
block|,
literal|"known array element"
block|,
literal|"array element"
block|,
literal|"array slice"
block|,
literal|"each"
block|,
literal|"values"
block|,
literal|"keys"
block|,
literal|"delete"
block|,
literal|"exists operator"
block|,
literal|"hash deref"
block|,
literal|"hash elem"
block|,
literal|"hash slice"
block|,
literal|"unpack"
block|,
literal|"pack"
block|,
literal|"split"
block|,
literal|"join"
block|,
literal|"list"
block|,
literal|"list slice"
block|,
literal|"anonymous list"
block|,
literal|"anonymous hash"
block|,
literal|"splice"
block|,
literal|"push"
block|,
literal|"pop"
block|,
literal|"shift"
block|,
literal|"unshift"
block|,
literal|"sort"
block|,
literal|"reverse"
block|,
literal|"grep"
block|,
literal|"grep iterator"
block|,
literal|"map"
block|,
literal|"map iterator"
block|,
literal|"flipflop"
block|,
literal|"range (or flip)"
block|,
literal|"range (or flop)"
block|,
literal|"logical and"
block|,
literal|"logical or"
block|,
literal|"logical xor"
block|,
literal|"conditional expression"
block|,
literal|"logical and assignment"
block|,
literal|"logical or assignment"
block|,
literal|"method lookup"
block|,
literal|"subroutine entry"
block|,
literal|"subroutine exit"
block|,
literal|"caller"
block|,
literal|"warn"
block|,
literal|"die"
block|,
literal|"reset"
block|,
literal|"line sequence"
block|,
literal|"next statement"
block|,
literal|"debug next statement"
block|,
literal|"iteration finalizer"
block|,
literal|"block entry"
block|,
literal|"block exit"
block|,
literal|"block"
block|,
literal|"foreach loop entry"
block|,
literal|"foreach loop iterator"
block|,
literal|"loop entry"
block|,
literal|"loop exit"
block|,
literal|"return"
block|,
literal|"last"
block|,
literal|"next"
block|,
literal|"redo"
block|,
literal|"dump"
block|,
literal|"goto"
block|,
literal|"exit"
block|,
literal|"open"
block|,
literal|"close"
block|,
literal|"pipe"
block|,
literal|"fileno"
block|,
literal|"umask"
block|,
literal|"binmode"
block|,
literal|"tie"
block|,
literal|"untie"
block|,
literal|"tied"
block|,
literal|"dbmopen"
block|,
literal|"dbmclose"
block|,
literal|"select system call"
block|,
literal|"select"
block|,
literal|"getc"
block|,
literal|"read"
block|,
literal|"write"
block|,
literal|"write exit"
block|,
literal|"printf"
block|,
literal|"print"
block|,
literal|"sysopen"
block|,
literal|"sysseek"
block|,
literal|"sysread"
block|,
literal|"syswrite"
block|,
literal|"send"
block|,
literal|"recv"
block|,
literal|"eof"
block|,
literal|"tell"
block|,
literal|"seek"
block|,
literal|"truncate"
block|,
literal|"fcntl"
block|,
literal|"ioctl"
block|,
literal|"flock"
block|,
literal|"socket"
block|,
literal|"socketpair"
block|,
literal|"bind"
block|,
literal|"connect"
block|,
literal|"listen"
block|,
literal|"accept"
block|,
literal|"shutdown"
block|,
literal|"getsockopt"
block|,
literal|"setsockopt"
block|,
literal|"getsockname"
block|,
literal|"getpeername"
block|,
literal|"lstat"
block|,
literal|"stat"
block|,
literal|"-R"
block|,
literal|"-W"
block|,
literal|"-X"
block|,
literal|"-r"
block|,
literal|"-w"
block|,
literal|"-x"
block|,
literal|"-e"
block|,
literal|"-O"
block|,
literal|"-o"
block|,
literal|"-z"
block|,
literal|"-s"
block|,
literal|"-M"
block|,
literal|"-A"
block|,
literal|"-C"
block|,
literal|"-S"
block|,
literal|"-c"
block|,
literal|"-b"
block|,
literal|"-f"
block|,
literal|"-d"
block|,
literal|"-p"
block|,
literal|"-l"
block|,
literal|"-u"
block|,
literal|"-g"
block|,
literal|"-k"
block|,
literal|"-t"
block|,
literal|"-T"
block|,
literal|"-B"
block|,
literal|"chdir"
block|,
literal|"chown"
block|,
literal|"chroot"
block|,
literal|"unlink"
block|,
literal|"chmod"
block|,
literal|"utime"
block|,
literal|"rename"
block|,
literal|"link"
block|,
literal|"symlink"
block|,
literal|"readlink"
block|,
literal|"mkdir"
block|,
literal|"rmdir"
block|,
literal|"opendir"
block|,
literal|"readdir"
block|,
literal|"telldir"
block|,
literal|"seekdir"
block|,
literal|"rewinddir"
block|,
literal|"closedir"
block|,
literal|"fork"
block|,
literal|"wait"
block|,
literal|"waitpid"
block|,
literal|"system"
block|,
literal|"exec"
block|,
literal|"kill"
block|,
literal|"getppid"
block|,
literal|"getpgrp"
block|,
literal|"setpgrp"
block|,
literal|"getpriority"
block|,
literal|"setpriority"
block|,
literal|"time"
block|,
literal|"times"
block|,
literal|"localtime"
block|,
literal|"gmtime"
block|,
literal|"alarm"
block|,
literal|"sleep"
block|,
literal|"shmget"
block|,
literal|"shmctl"
block|,
literal|"shmread"
block|,
literal|"shmwrite"
block|,
literal|"msgget"
block|,
literal|"msgctl"
block|,
literal|"msgsnd"
block|,
literal|"msgrcv"
block|,
literal|"semget"
block|,
literal|"semctl"
block|,
literal|"semop"
block|,
literal|"require"
block|,
literal|"do 'file'"
block|,
literal|"eval string"
block|,
literal|"eval exit"
block|,
literal|"eval block"
block|,
literal|"eval block exit"
block|,
literal|"gethostbyname"
block|,
literal|"gethostbyaddr"
block|,
literal|"gethostent"
block|,
literal|"getnetbyname"
block|,
literal|"getnetbyaddr"
block|,
literal|"getnetent"
block|,
literal|"getprotobyname"
block|,
literal|"getprotobynumber"
block|,
literal|"getprotoent"
block|,
literal|"getservbyname"
block|,
literal|"getservbyport"
block|,
literal|"getservent"
block|,
literal|"sethostent"
block|,
literal|"setnetent"
block|,
literal|"setprotoent"
block|,
literal|"setservent"
block|,
literal|"endhostent"
block|,
literal|"endnetent"
block|,
literal|"endprotoent"
block|,
literal|"endservent"
block|,
literal|"getpwnam"
block|,
literal|"getpwuid"
block|,
literal|"getpwent"
block|,
literal|"setpwent"
block|,
literal|"endpwent"
block|,
literal|"getgrnam"
block|,
literal|"getgrgid"
block|,
literal|"getgrent"
block|,
literal|"setgrent"
block|,
literal|"endgrent"
block|,
literal|"getlogin"
block|,
literal|"syscall"
block|,
literal|"lock"
block|,
literal|"per-thread variable"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_decl_stmt
name|START_EXTERN_C
name|OP
modifier|*
name|ck_anoncode
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_bitop
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_concat
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_delete
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_eof
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_eval
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_exec
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_exists
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_ftst
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_fun
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_fun_locale
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_glob
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_grep
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_index
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_lengthconst
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_lfun
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_listiob
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_match
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_null
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_repeat
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_require
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_rfun
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_rvconst
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_scmp
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_select
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_shift
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_sort
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_spair
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_split
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_subr
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_svconst
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|ck_trunc
name|_
argument_list|(
operator|(
name|OP
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_null
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_stub
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_scalar
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pushmark
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_wantarray
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_const
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gvsv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gelem
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_padsv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_padav
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_padhv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_padany
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pushre
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rv2gv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rv2sv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_av2arylen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rv2cv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_anoncode
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_prototype
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_refgen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_srefgen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ref
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_bless
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_backtick
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_glob
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_readline
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rcatline
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_regcmaybe
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_regcreset
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_regcomp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_match
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_qr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_subst
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_substcont
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_trans
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sassign
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_aassign
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_schop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chomp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_schomp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_defined
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_undef
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_study
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pos
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_preinc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_preinc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_predec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_predec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_postinc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_postinc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_postdec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_postdec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pow
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_multiply
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_multiply
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_divide
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_divide
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_modulo
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_modulo
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_repeat
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_add
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_add
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_subtract
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_subtract
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_concat
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_stringify
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_left_shift
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_right_shift
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_lt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_gt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_le
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_le
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ge
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_ge
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_eq
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_eq
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ne
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_ne
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ncmp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_ncmp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_slt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sgt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sle
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sge
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_seq
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sne
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_scmp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_bit_and
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_bit_xor
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_bit_or
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_negate
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_i_negate
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_not
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_complement
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_atan2
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sin
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_cos
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rand
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_srand
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_exp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_log
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sqrt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_int
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_hex
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_oct
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_abs
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_length
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_substr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_vec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_index
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rindex
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sprintf
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_formline
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ord
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_crypt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ucfirst
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lcfirst
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_uc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_quotemeta
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rv2av
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_aelemfast
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_aelem
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_aslice
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_each
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_values
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_keys
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_delete
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_exists
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rv2hv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_helem
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_hslice
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_unpack
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pack
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_split
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_join
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_list
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lslice
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_anonlist
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_anonhash
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_splice
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_push
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shift
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_unshift
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sort
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_reverse
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_grepstart
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_grepwhile
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_mapstart
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_mapwhile
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_range
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_flip
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_flop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_and
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_or
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_xor
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_cond_expr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_andassign
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_orassign
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_method
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_entersub
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leavesub
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_caller
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_warn
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_die
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_reset
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lineseq
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_nextstate
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_dbstate
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_unstack
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_enter
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leave
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_scope
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_enteriter
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_iter
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_enterloop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leaveloop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_return
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_last
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_next
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_redo
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_dump
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_goto
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_exit
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_open
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_close
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_pipe_op
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fileno
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_umask
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_binmode
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_tie
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_untie
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_tied
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_dbmopen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_dbmclose
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sselect
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_select
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getc
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_read
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_enterwrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leavewrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_prtf
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_print
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sysopen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sysseek
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sysread
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_syswrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_send
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_recv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_eof
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_tell
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_seek
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_truncate
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fcntl
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ioctl
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_flock
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_socket
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sockpair
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_bind
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_connect
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_listen
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_accept
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shutdown
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gsockopt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ssockopt
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getsockname
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getpeername
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lstat
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_stat
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftrread
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftrwrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftrexec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fteread
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftewrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fteexec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftis
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fteowned
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftrowned
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftzero
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftsize
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftmtime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftatime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftctime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftsock
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftchr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftblk
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftfile
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftpipe
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftlink
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftsuid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftsgid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftsvtx
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fttty
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fttext
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ftbinary
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chown
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chroot
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_unlink
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_chmod
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_utime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rename
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_link
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_symlink
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_readlink
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_mkdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rmdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_open_dir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_readdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_telldir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_seekdir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_rewinddir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_closedir
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_fork
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_wait
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_waitpid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_system
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_exec
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_kill
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getppid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getpgrp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_setpgrp
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getpriority
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_setpriority
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_time
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_tms
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_localtime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gmtime
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_alarm
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sleep
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shmget
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shmctl
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shmread
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shmwrite
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_msgget
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_msgctl
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_msgsnd
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_msgrcv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_semget
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_semctl
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_semop
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_require
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_dofile
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_entereval
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leaveeval
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_entertry
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_leavetry
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ghbyname
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ghbyaddr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ghostent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gnbyname
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gnbyaddr
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gnetent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gpbyname
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gpbynumber
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gprotoent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gsbyname
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gsbyport
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gservent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_shostent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_snetent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sprotoent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sservent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ehostent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_enetent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_eprotoent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_eservent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gpwnam
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gpwuid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_gpwent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_spwent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_epwent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ggrnam
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ggrgid
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_ggrent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_sgrent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_egrent
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_getlogin
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_syscall
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_lock
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OP
modifier|*
name|pp_threadsv
name|_
argument_list|(
operator|(
name|ARGSproto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|END_EXTERN_C
endif|#
directive|endif
comment|/* PERL_OBJECT */
ifndef|#
directive|ifndef
name|DOINIT
name|EXT
name|OP
modifier|*
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|ppaddr
argument_list|)
index|[]
argument_list|)
argument_list|(
name|ARGSproto
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_decl_stmt
name|EXT
name|OP
modifier|*
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|ppaddr
argument_list|)
index|[]
argument_list|)
argument_list|(
name|ARGSproto
argument_list|)
init|=
block|{
name|pp_null
block|,
name|pp_stub
block|,
name|pp_scalar
block|,
name|pp_pushmark
block|,
name|pp_wantarray
block|,
name|pp_const
block|,
name|pp_gvsv
block|,
name|pp_gv
block|,
name|pp_gelem
block|,
name|pp_padsv
block|,
name|pp_padav
block|,
name|pp_padhv
block|,
name|pp_padany
block|,
name|pp_pushre
block|,
name|pp_rv2gv
block|,
name|pp_rv2sv
block|,
name|pp_av2arylen
block|,
name|pp_rv2cv
block|,
name|pp_anoncode
block|,
name|pp_prototype
block|,
name|pp_refgen
block|,
name|pp_srefgen
block|,
name|pp_ref
block|,
name|pp_bless
block|,
name|pp_backtick
block|,
name|pp_glob
block|,
name|pp_readline
block|,
name|pp_rcatline
block|,
name|pp_regcmaybe
block|,
name|pp_regcreset
block|,
name|pp_regcomp
block|,
name|pp_match
block|,
name|pp_qr
block|,
name|pp_subst
block|,
name|pp_substcont
block|,
name|pp_trans
block|,
name|pp_sassign
block|,
name|pp_aassign
block|,
name|pp_chop
block|,
name|pp_schop
block|,
name|pp_chomp
block|,
name|pp_schomp
block|,
name|pp_defined
block|,
name|pp_undef
block|,
name|pp_study
block|,
name|pp_pos
block|,
name|pp_preinc
block|,
name|pp_i_preinc
block|,
name|pp_predec
block|,
name|pp_i_predec
block|,
name|pp_postinc
block|,
name|pp_i_postinc
block|,
name|pp_postdec
block|,
name|pp_i_postdec
block|,
name|pp_pow
block|,
name|pp_multiply
block|,
name|pp_i_multiply
block|,
name|pp_divide
block|,
name|pp_i_divide
block|,
name|pp_modulo
block|,
name|pp_i_modulo
block|,
name|pp_repeat
block|,
name|pp_add
block|,
name|pp_i_add
block|,
name|pp_subtract
block|,
name|pp_i_subtract
block|,
name|pp_concat
block|,
name|pp_stringify
block|,
name|pp_left_shift
block|,
name|pp_right_shift
block|,
name|pp_lt
block|,
name|pp_i_lt
block|,
name|pp_gt
block|,
name|pp_i_gt
block|,
name|pp_le
block|,
name|pp_i_le
block|,
name|pp_ge
block|,
name|pp_i_ge
block|,
name|pp_eq
block|,
name|pp_i_eq
block|,
name|pp_ne
block|,
name|pp_i_ne
block|,
name|pp_ncmp
block|,
name|pp_i_ncmp
block|,
name|pp_slt
block|,
name|pp_sgt
block|,
name|pp_sle
block|,
name|pp_sge
block|,
name|pp_seq
block|,
name|pp_sne
block|,
name|pp_scmp
block|,
name|pp_bit_and
block|,
name|pp_bit_xor
block|,
name|pp_bit_or
block|,
name|pp_negate
block|,
name|pp_i_negate
block|,
name|pp_not
block|,
name|pp_complement
block|,
name|pp_atan2
block|,
name|pp_sin
block|,
name|pp_cos
block|,
name|pp_rand
block|,
name|pp_srand
block|,
name|pp_exp
block|,
name|pp_log
block|,
name|pp_sqrt
block|,
name|pp_int
block|,
name|pp_hex
block|,
name|pp_oct
block|,
name|pp_abs
block|,
name|pp_length
block|,
name|pp_substr
block|,
name|pp_vec
block|,
name|pp_index
block|,
name|pp_rindex
block|,
name|pp_sprintf
block|,
name|pp_formline
block|,
name|pp_ord
block|,
name|pp_chr
block|,
name|pp_crypt
block|,
name|pp_ucfirst
block|,
name|pp_lcfirst
block|,
name|pp_uc
block|,
name|pp_lc
block|,
name|pp_quotemeta
block|,
name|pp_rv2av
block|,
name|pp_aelemfast
block|,
name|pp_aelem
block|,
name|pp_aslice
block|,
name|pp_each
block|,
name|pp_values
block|,
name|pp_keys
block|,
name|pp_delete
block|,
name|pp_exists
block|,
name|pp_rv2hv
block|,
name|pp_helem
block|,
name|pp_hslice
block|,
name|pp_unpack
block|,
name|pp_pack
block|,
name|pp_split
block|,
name|pp_join
block|,
name|pp_list
block|,
name|pp_lslice
block|,
name|pp_anonlist
block|,
name|pp_anonhash
block|,
name|pp_splice
block|,
name|pp_push
block|,
name|pp_pop
block|,
name|pp_shift
block|,
name|pp_unshift
block|,
name|pp_sort
block|,
name|pp_reverse
block|,
name|pp_grepstart
block|,
name|pp_grepwhile
block|,
name|pp_mapstart
block|,
name|pp_mapwhile
block|,
name|pp_range
block|,
name|pp_flip
block|,
name|pp_flop
block|,
name|pp_and
block|,
name|pp_or
block|,
name|pp_xor
block|,
name|pp_cond_expr
block|,
name|pp_andassign
block|,
name|pp_orassign
block|,
name|pp_method
block|,
name|pp_entersub
block|,
name|pp_leavesub
block|,
name|pp_caller
block|,
name|pp_warn
block|,
name|pp_die
block|,
name|pp_reset
block|,
name|pp_lineseq
block|,
name|pp_nextstate
block|,
name|pp_dbstate
block|,
name|pp_unstack
block|,
name|pp_enter
block|,
name|pp_leave
block|,
name|pp_scope
block|,
name|pp_enteriter
block|,
name|pp_iter
block|,
name|pp_enterloop
block|,
name|pp_leaveloop
block|,
name|pp_return
block|,
name|pp_last
block|,
name|pp_next
block|,
name|pp_redo
block|,
name|pp_dump
block|,
name|pp_goto
block|,
name|pp_exit
block|,
name|pp_open
block|,
name|pp_close
block|,
name|pp_pipe_op
block|,
name|pp_fileno
block|,
name|pp_umask
block|,
name|pp_binmode
block|,
name|pp_tie
block|,
name|pp_untie
block|,
name|pp_tied
block|,
name|pp_dbmopen
block|,
name|pp_dbmclose
block|,
name|pp_sselect
block|,
name|pp_select
block|,
name|pp_getc
block|,
name|pp_read
block|,
name|pp_enterwrite
block|,
name|pp_leavewrite
block|,
name|pp_prtf
block|,
name|pp_print
block|,
name|pp_sysopen
block|,
name|pp_sysseek
block|,
name|pp_sysread
block|,
name|pp_syswrite
block|,
name|pp_send
block|,
name|pp_recv
block|,
name|pp_eof
block|,
name|pp_tell
block|,
name|pp_seek
block|,
name|pp_truncate
block|,
name|pp_fcntl
block|,
name|pp_ioctl
block|,
name|pp_flock
block|,
name|pp_socket
block|,
name|pp_sockpair
block|,
name|pp_bind
block|,
name|pp_connect
block|,
name|pp_listen
block|,
name|pp_accept
block|,
name|pp_shutdown
block|,
name|pp_gsockopt
block|,
name|pp_ssockopt
block|,
name|pp_getsockname
block|,
name|pp_getpeername
block|,
name|pp_lstat
block|,
name|pp_stat
block|,
name|pp_ftrread
block|,
name|pp_ftrwrite
block|,
name|pp_ftrexec
block|,
name|pp_fteread
block|,
name|pp_ftewrite
block|,
name|pp_fteexec
block|,
name|pp_ftis
block|,
name|pp_fteowned
block|,
name|pp_ftrowned
block|,
name|pp_ftzero
block|,
name|pp_ftsize
block|,
name|pp_ftmtime
block|,
name|pp_ftatime
block|,
name|pp_ftctime
block|,
name|pp_ftsock
block|,
name|pp_ftchr
block|,
name|pp_ftblk
block|,
name|pp_ftfile
block|,
name|pp_ftdir
block|,
name|pp_ftpipe
block|,
name|pp_ftlink
block|,
name|pp_ftsuid
block|,
name|pp_ftsgid
block|,
name|pp_ftsvtx
block|,
name|pp_fttty
block|,
name|pp_fttext
block|,
name|pp_ftbinary
block|,
name|pp_chdir
block|,
name|pp_chown
block|,
name|pp_chroot
block|,
name|pp_unlink
block|,
name|pp_chmod
block|,
name|pp_utime
block|,
name|pp_rename
block|,
name|pp_link
block|,
name|pp_symlink
block|,
name|pp_readlink
block|,
name|pp_mkdir
block|,
name|pp_rmdir
block|,
name|pp_open_dir
block|,
name|pp_readdir
block|,
name|pp_telldir
block|,
name|pp_seekdir
block|,
name|pp_rewinddir
block|,
name|pp_closedir
block|,
name|pp_fork
block|,
name|pp_wait
block|,
name|pp_waitpid
block|,
name|pp_system
block|,
name|pp_exec
block|,
name|pp_kill
block|,
name|pp_getppid
block|,
name|pp_getpgrp
block|,
name|pp_setpgrp
block|,
name|pp_getpriority
block|,
name|pp_setpriority
block|,
name|pp_time
block|,
name|pp_tms
block|,
name|pp_localtime
block|,
name|pp_gmtime
block|,
name|pp_alarm
block|,
name|pp_sleep
block|,
name|pp_shmget
block|,
name|pp_shmctl
block|,
name|pp_shmread
block|,
name|pp_shmwrite
block|,
name|pp_msgget
block|,
name|pp_msgctl
block|,
name|pp_msgsnd
block|,
name|pp_msgrcv
block|,
name|pp_semget
block|,
name|pp_semctl
block|,
name|pp_semop
block|,
name|pp_require
block|,
name|pp_dofile
block|,
name|pp_entereval
block|,
name|pp_leaveeval
block|,
name|pp_entertry
block|,
name|pp_leavetry
block|,
name|pp_ghbyname
block|,
name|pp_ghbyaddr
block|,
name|pp_ghostent
block|,
name|pp_gnbyname
block|,
name|pp_gnbyaddr
block|,
name|pp_gnetent
block|,
name|pp_gpbyname
block|,
name|pp_gpbynumber
block|,
name|pp_gprotoent
block|,
name|pp_gsbyname
block|,
name|pp_gsbyport
block|,
name|pp_gservent
block|,
name|pp_shostent
block|,
name|pp_snetent
block|,
name|pp_sprotoent
block|,
name|pp_sservent
block|,
name|pp_ehostent
block|,
name|pp_enetent
block|,
name|pp_eprotoent
block|,
name|pp_eservent
block|,
name|pp_gpwnam
block|,
name|pp_gpwuid
block|,
name|pp_gpwent
block|,
name|pp_spwent
block|,
name|pp_epwent
block|,
name|pp_ggrnam
block|,
name|pp_ggrgid
block|,
name|pp_ggrent
block|,
name|pp_sgrent
block|,
name|pp_egrent
block|,
name|pp_getlogin
block|,
name|pp_syscall
block|,
name|pp_lock
block|,
name|pp_threadsv
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

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
name|EXT
name|OP
modifier|*
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|check
argument_list|)
index|[]
argument_list|)
name|_
argument_list|(
operator|(
name|OP
operator|*
name|op
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_decl_stmt
name|EXT
name|OP
modifier|*
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|check
argument_list|)
index|[]
argument_list|)
name|_
argument_list|(
operator|(
name|OP
operator|*
name|op
operator|)
argument_list|)
init|=
block|{
name|ck_null
block|,
comment|/* null */
name|ck_null
block|,
comment|/* stub */
name|ck_fun
block|,
comment|/* scalar */
name|ck_null
block|,
comment|/* pushmark */
name|ck_null
block|,
comment|/* wantarray */
name|ck_svconst
block|,
comment|/* const */
name|ck_null
block|,
comment|/* gvsv */
name|ck_null
block|,
comment|/* gv */
name|ck_null
block|,
comment|/* gelem */
name|ck_null
block|,
comment|/* padsv */
name|ck_null
block|,
comment|/* padav */
name|ck_null
block|,
comment|/* padhv */
name|ck_null
block|,
comment|/* padany */
name|ck_null
block|,
comment|/* pushre */
name|ck_rvconst
block|,
comment|/* rv2gv */
name|ck_rvconst
block|,
comment|/* rv2sv */
name|ck_null
block|,
comment|/* av2arylen */
name|ck_rvconst
block|,
comment|/* rv2cv */
name|ck_anoncode
block|,
comment|/* anoncode */
name|ck_null
block|,
comment|/* prototype */
name|ck_spair
block|,
comment|/* refgen */
name|ck_null
block|,
comment|/* srefgen */
name|ck_fun
block|,
comment|/* ref */
name|ck_fun
block|,
comment|/* bless */
name|ck_null
block|,
comment|/* backtick */
name|ck_glob
block|,
comment|/* glob */
name|ck_null
block|,
comment|/* readline */
name|ck_null
block|,
comment|/* rcatline */
name|ck_fun
block|,
comment|/* regcmaybe */
name|ck_fun
block|,
comment|/* regcreset */
name|ck_null
block|,
comment|/* regcomp */
name|ck_match
block|,
comment|/* match */
name|ck_match
block|,
comment|/* qr */
name|ck_null
block|,
comment|/* subst */
name|ck_null
block|,
comment|/* substcont */
name|ck_null
block|,
comment|/* trans */
name|ck_null
block|,
comment|/* sassign */
name|ck_null
block|,
comment|/* aassign */
name|ck_spair
block|,
comment|/* chop */
name|ck_null
block|,
comment|/* schop */
name|ck_spair
block|,
comment|/* chomp */
name|ck_null
block|,
comment|/* schomp */
name|ck_rfun
block|,
comment|/* defined */
name|ck_lfun
block|,
comment|/* undef */
name|ck_fun
block|,
comment|/* study */
name|ck_lfun
block|,
comment|/* pos */
name|ck_lfun
block|,
comment|/* preinc */
name|ck_lfun
block|,
comment|/* i_preinc */
name|ck_lfun
block|,
comment|/* predec */
name|ck_lfun
block|,
comment|/* i_predec */
name|ck_lfun
block|,
comment|/* postinc */
name|ck_lfun
block|,
comment|/* i_postinc */
name|ck_lfun
block|,
comment|/* postdec */
name|ck_lfun
block|,
comment|/* i_postdec */
name|ck_null
block|,
comment|/* pow */
name|ck_null
block|,
comment|/* multiply */
name|ck_null
block|,
comment|/* i_multiply */
name|ck_null
block|,
comment|/* divide */
name|ck_null
block|,
comment|/* i_divide */
name|ck_null
block|,
comment|/* modulo */
name|ck_null
block|,
comment|/* i_modulo */
name|ck_repeat
block|,
comment|/* repeat */
name|ck_null
block|,
comment|/* add */
name|ck_null
block|,
comment|/* i_add */
name|ck_null
block|,
comment|/* subtract */
name|ck_null
block|,
comment|/* i_subtract */
name|ck_concat
block|,
comment|/* concat */
name|ck_fun
block|,
comment|/* stringify */
name|ck_bitop
block|,
comment|/* left_shift */
name|ck_bitop
block|,
comment|/* right_shift */
name|ck_null
block|,
comment|/* lt */
name|ck_null
block|,
comment|/* i_lt */
name|ck_null
block|,
comment|/* gt */
name|ck_null
block|,
comment|/* i_gt */
name|ck_null
block|,
comment|/* le */
name|ck_null
block|,
comment|/* i_le */
name|ck_null
block|,
comment|/* ge */
name|ck_null
block|,
comment|/* i_ge */
name|ck_null
block|,
comment|/* eq */
name|ck_null
block|,
comment|/* i_eq */
name|ck_null
block|,
comment|/* ne */
name|ck_null
block|,
comment|/* i_ne */
name|ck_null
block|,
comment|/* ncmp */
name|ck_null
block|,
comment|/* i_ncmp */
name|ck_scmp
block|,
comment|/* slt */
name|ck_scmp
block|,
comment|/* sgt */
name|ck_scmp
block|,
comment|/* sle */
name|ck_scmp
block|,
comment|/* sge */
name|ck_null
block|,
comment|/* seq */
name|ck_null
block|,
comment|/* sne */
name|ck_scmp
block|,
comment|/* scmp */
name|ck_bitop
block|,
comment|/* bit_and */
name|ck_bitop
block|,
comment|/* bit_xor */
name|ck_bitop
block|,
comment|/* bit_or */
name|ck_null
block|,
comment|/* negate */
name|ck_null
block|,
comment|/* i_negate */
name|ck_null
block|,
comment|/* not */
name|ck_bitop
block|,
comment|/* complement */
name|ck_fun
block|,
comment|/* atan2 */
name|ck_fun
block|,
comment|/* sin */
name|ck_fun
block|,
comment|/* cos */
name|ck_fun
block|,
comment|/* rand */
name|ck_fun
block|,
comment|/* srand */
name|ck_fun
block|,
comment|/* exp */
name|ck_fun
block|,
comment|/* log */
name|ck_fun
block|,
comment|/* sqrt */
name|ck_fun
block|,
comment|/* int */
name|ck_fun
block|,
comment|/* hex */
name|ck_fun
block|,
comment|/* oct */
name|ck_fun
block|,
comment|/* abs */
name|ck_lengthconst
block|,
comment|/* length */
name|ck_fun
block|,
comment|/* substr */
name|ck_fun
block|,
comment|/* vec */
name|ck_index
block|,
comment|/* index */
name|ck_index
block|,
comment|/* rindex */
name|ck_fun_locale
block|,
comment|/* sprintf */
name|ck_fun
block|,
comment|/* formline */
name|ck_fun
block|,
comment|/* ord */
name|ck_fun
block|,
comment|/* chr */
name|ck_fun
block|,
comment|/* crypt */
name|ck_fun_locale
block|,
comment|/* ucfirst */
name|ck_fun_locale
block|,
comment|/* lcfirst */
name|ck_fun_locale
block|,
comment|/* uc */
name|ck_fun_locale
block|,
comment|/* lc */
name|ck_fun
block|,
comment|/* quotemeta */
name|ck_rvconst
block|,
comment|/* rv2av */
name|ck_null
block|,
comment|/* aelemfast */
name|ck_null
block|,
comment|/* aelem */
name|ck_null
block|,
comment|/* aslice */
name|ck_fun
block|,
comment|/* each */
name|ck_fun
block|,
comment|/* values */
name|ck_fun
block|,
comment|/* keys */
name|ck_delete
block|,
comment|/* delete */
name|ck_exists
block|,
comment|/* exists */
name|ck_rvconst
block|,
comment|/* rv2hv */
name|ck_null
block|,
comment|/* helem */
name|ck_null
block|,
comment|/* hslice */
name|ck_fun
block|,
comment|/* unpack */
name|ck_fun
block|,
comment|/* pack */
name|ck_split
block|,
comment|/* split */
name|ck_fun
block|,
comment|/* join */
name|ck_null
block|,
comment|/* list */
name|ck_null
block|,
comment|/* lslice */
name|ck_fun
block|,
comment|/* anonlist */
name|ck_fun
block|,
comment|/* anonhash */
name|ck_fun
block|,
comment|/* splice */
name|ck_fun
block|,
comment|/* push */
name|ck_shift
block|,
comment|/* pop */
name|ck_shift
block|,
comment|/* shift */
name|ck_fun
block|,
comment|/* unshift */
name|ck_sort
block|,
comment|/* sort */
name|ck_fun
block|,
comment|/* reverse */
name|ck_grep
block|,
comment|/* grepstart */
name|ck_null
block|,
comment|/* grepwhile */
name|ck_grep
block|,
comment|/* mapstart */
name|ck_null
block|,
comment|/* mapwhile */
name|ck_null
block|,
comment|/* range */
name|ck_null
block|,
comment|/* flip */
name|ck_null
block|,
comment|/* flop */
name|ck_null
block|,
comment|/* and */
name|ck_null
block|,
comment|/* or */
name|ck_null
block|,
comment|/* xor */
name|ck_null
block|,
comment|/* cond_expr */
name|ck_null
block|,
comment|/* andassign */
name|ck_null
block|,
comment|/* orassign */
name|ck_null
block|,
comment|/* method */
name|ck_subr
block|,
comment|/* entersub */
name|ck_null
block|,
comment|/* leavesub */
name|ck_fun
block|,
comment|/* caller */
name|ck_fun
block|,
comment|/* warn */
name|ck_fun
block|,
comment|/* die */
name|ck_fun
block|,
comment|/* reset */
name|ck_null
block|,
comment|/* lineseq */
name|ck_null
block|,
comment|/* nextstate */
name|ck_null
block|,
comment|/* dbstate */
name|ck_null
block|,
comment|/* unstack */
name|ck_null
block|,
comment|/* enter */
name|ck_null
block|,
comment|/* leave */
name|ck_null
block|,
comment|/* scope */
name|ck_null
block|,
comment|/* enteriter */
name|ck_null
block|,
comment|/* iter */
name|ck_null
block|,
comment|/* enterloop */
name|ck_null
block|,
comment|/* leaveloop */
name|ck_null
block|,
comment|/* return */
name|ck_null
block|,
comment|/* last */
name|ck_null
block|,
comment|/* next */
name|ck_null
block|,
comment|/* redo */
name|ck_null
block|,
comment|/* dump */
name|ck_null
block|,
comment|/* goto */
name|ck_fun
block|,
comment|/* exit */
name|ck_fun
block|,
comment|/* open */
name|ck_fun
block|,
comment|/* close */
name|ck_fun
block|,
comment|/* pipe_op */
name|ck_fun
block|,
comment|/* fileno */
name|ck_fun
block|,
comment|/* umask */
name|ck_fun
block|,
comment|/* binmode */
name|ck_fun
block|,
comment|/* tie */
name|ck_fun
block|,
comment|/* untie */
name|ck_fun
block|,
comment|/* tied */
name|ck_fun
block|,
comment|/* dbmopen */
name|ck_fun
block|,
comment|/* dbmclose */
name|ck_select
block|,
comment|/* sselect */
name|ck_select
block|,
comment|/* select */
name|ck_eof
block|,
comment|/* getc */
name|ck_fun
block|,
comment|/* read */
name|ck_fun
block|,
comment|/* enterwrite */
name|ck_null
block|,
comment|/* leavewrite */
name|ck_listiob
block|,
comment|/* prtf */
name|ck_listiob
block|,
comment|/* print */
name|ck_fun
block|,
comment|/* sysopen */
name|ck_fun
block|,
comment|/* sysseek */
name|ck_fun
block|,
comment|/* sysread */
name|ck_fun
block|,
comment|/* syswrite */
name|ck_fun
block|,
comment|/* send */
name|ck_fun
block|,
comment|/* recv */
name|ck_eof
block|,
comment|/* eof */
name|ck_fun
block|,
comment|/* tell */
name|ck_fun
block|,
comment|/* seek */
name|ck_trunc
block|,
comment|/* truncate */
name|ck_fun
block|,
comment|/* fcntl */
name|ck_fun
block|,
comment|/* ioctl */
name|ck_fun
block|,
comment|/* flock */
name|ck_fun
block|,
comment|/* socket */
name|ck_fun
block|,
comment|/* sockpair */
name|ck_fun
block|,
comment|/* bind */
name|ck_fun
block|,
comment|/* connect */
name|ck_fun
block|,
comment|/* listen */
name|ck_fun
block|,
comment|/* accept */
name|ck_fun
block|,
comment|/* shutdown */
name|ck_fun
block|,
comment|/* gsockopt */
name|ck_fun
block|,
comment|/* ssockopt */
name|ck_fun
block|,
comment|/* getsockname */
name|ck_fun
block|,
comment|/* getpeername */
name|ck_ftst
block|,
comment|/* lstat */
name|ck_ftst
block|,
comment|/* stat */
name|ck_ftst
block|,
comment|/* ftrread */
name|ck_ftst
block|,
comment|/* ftrwrite */
name|ck_ftst
block|,
comment|/* ftrexec */
name|ck_ftst
block|,
comment|/* fteread */
name|ck_ftst
block|,
comment|/* ftewrite */
name|ck_ftst
block|,
comment|/* fteexec */
name|ck_ftst
block|,
comment|/* ftis */
name|ck_ftst
block|,
comment|/* fteowned */
name|ck_ftst
block|,
comment|/* ftrowned */
name|ck_ftst
block|,
comment|/* ftzero */
name|ck_ftst
block|,
comment|/* ftsize */
name|ck_ftst
block|,
comment|/* ftmtime */
name|ck_ftst
block|,
comment|/* ftatime */
name|ck_ftst
block|,
comment|/* ftctime */
name|ck_ftst
block|,
comment|/* ftsock */
name|ck_ftst
block|,
comment|/* ftchr */
name|ck_ftst
block|,
comment|/* ftblk */
name|ck_ftst
block|,
comment|/* ftfile */
name|ck_ftst
block|,
comment|/* ftdir */
name|ck_ftst
block|,
comment|/* ftpipe */
name|ck_ftst
block|,
comment|/* ftlink */
name|ck_ftst
block|,
comment|/* ftsuid */
name|ck_ftst
block|,
comment|/* ftsgid */
name|ck_ftst
block|,
comment|/* ftsvtx */
name|ck_ftst
block|,
comment|/* fttty */
name|ck_ftst
block|,
comment|/* fttext */
name|ck_ftst
block|,
comment|/* ftbinary */
name|ck_fun
block|,
comment|/* chdir */
name|ck_fun
block|,
comment|/* chown */
name|ck_fun
block|,
comment|/* chroot */
name|ck_fun
block|,
comment|/* unlink */
name|ck_fun
block|,
comment|/* chmod */
name|ck_fun
block|,
comment|/* utime */
name|ck_fun
block|,
comment|/* rename */
name|ck_fun
block|,
comment|/* link */
name|ck_fun
block|,
comment|/* symlink */
name|ck_fun
block|,
comment|/* readlink */
name|ck_fun
block|,
comment|/* mkdir */
name|ck_fun
block|,
comment|/* rmdir */
name|ck_fun
block|,
comment|/* open_dir */
name|ck_fun
block|,
comment|/* readdir */
name|ck_fun
block|,
comment|/* telldir */
name|ck_fun
block|,
comment|/* seekdir */
name|ck_fun
block|,
comment|/* rewinddir */
name|ck_fun
block|,
comment|/* closedir */
name|ck_null
block|,
comment|/* fork */
name|ck_null
block|,
comment|/* wait */
name|ck_fun
block|,
comment|/* waitpid */
name|ck_exec
block|,
comment|/* system */
name|ck_exec
block|,
comment|/* exec */
name|ck_fun
block|,
comment|/* kill */
name|ck_null
block|,
comment|/* getppid */
name|ck_fun
block|,
comment|/* getpgrp */
name|ck_fun
block|,
comment|/* setpgrp */
name|ck_fun
block|,
comment|/* getpriority */
name|ck_fun
block|,
comment|/* setpriority */
name|ck_null
block|,
comment|/* time */
name|ck_null
block|,
comment|/* tms */
name|ck_fun
block|,
comment|/* localtime */
name|ck_fun
block|,
comment|/* gmtime */
name|ck_fun
block|,
comment|/* alarm */
name|ck_fun
block|,
comment|/* sleep */
name|ck_fun
block|,
comment|/* shmget */
name|ck_fun
block|,
comment|/* shmctl */
name|ck_fun
block|,
comment|/* shmread */
name|ck_fun
block|,
comment|/* shmwrite */
name|ck_fun
block|,
comment|/* msgget */
name|ck_fun
block|,
comment|/* msgctl */
name|ck_fun
block|,
comment|/* msgsnd */
name|ck_fun
block|,
comment|/* msgrcv */
name|ck_fun
block|,
comment|/* semget */
name|ck_fun
block|,
comment|/* semctl */
name|ck_fun
block|,
comment|/* semop */
name|ck_require
block|,
comment|/* require */
name|ck_fun
block|,
comment|/* dofile */
name|ck_eval
block|,
comment|/* entereval */
name|ck_null
block|,
comment|/* leaveeval */
name|ck_null
block|,
comment|/* entertry */
name|ck_null
block|,
comment|/* leavetry */
name|ck_fun
block|,
comment|/* ghbyname */
name|ck_fun
block|,
comment|/* ghbyaddr */
name|ck_null
block|,
comment|/* ghostent */
name|ck_fun
block|,
comment|/* gnbyname */
name|ck_fun
block|,
comment|/* gnbyaddr */
name|ck_null
block|,
comment|/* gnetent */
name|ck_fun
block|,
comment|/* gpbyname */
name|ck_fun
block|,
comment|/* gpbynumber */
name|ck_null
block|,
comment|/* gprotoent */
name|ck_fun
block|,
comment|/* gsbyname */
name|ck_fun
block|,
comment|/* gsbyport */
name|ck_null
block|,
comment|/* gservent */
name|ck_fun
block|,
comment|/* shostent */
name|ck_fun
block|,
comment|/* snetent */
name|ck_fun
block|,
comment|/* sprotoent */
name|ck_fun
block|,
comment|/* sservent */
name|ck_null
block|,
comment|/* ehostent */
name|ck_null
block|,
comment|/* enetent */
name|ck_null
block|,
comment|/* eprotoent */
name|ck_null
block|,
comment|/* eservent */
name|ck_fun
block|,
comment|/* gpwnam */
name|ck_fun
block|,
comment|/* gpwuid */
name|ck_null
block|,
comment|/* gpwent */
name|ck_null
block|,
comment|/* spwent */
name|ck_null
block|,
comment|/* epwent */
name|ck_fun
block|,
comment|/* ggrnam */
name|ck_fun
block|,
comment|/* ggrgid */
name|ck_null
block|,
comment|/* ggrent */
name|ck_null
block|,
comment|/* sgrent */
name|ck_null
block|,
comment|/* egrent */
name|ck_null
block|,
comment|/* getlogin */
name|ck_fun
block|,
comment|/* syscall */
name|ck_rfun
block|,
comment|/* lock */
name|ck_null
block|,
comment|/* threadsv */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

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
name|EXT
name|U32
name|opargs
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|U32
name|opargs
index|[]
init|=
block|{
literal|0x00000000
block|,
comment|/* null */
literal|0x00000000
block|,
comment|/* stub */
literal|0x00001c04
block|,
comment|/* scalar */
literal|0x00000004
block|,
comment|/* pushmark */
literal|0x00000014
block|,
comment|/* wantarray */
literal|0x00000704
block|,
comment|/* const */
literal|0x00000844
block|,
comment|/* gvsv */
literal|0x00000844
block|,
comment|/* gv */
literal|0x00011240
block|,
comment|/* gelem */
literal|0x00000044
block|,
comment|/* padsv */
literal|0x00000040
block|,
comment|/* padav */
literal|0x00000040
block|,
comment|/* padhv */
literal|0x00000040
block|,
comment|/* padany */
literal|0x00000640
block|,
comment|/* pushre */
literal|0x00000144
block|,
comment|/* rv2gv */
literal|0x00000144
block|,
comment|/* rv2sv */
literal|0x00000114
block|,
comment|/* av2arylen */
literal|0x00000140
block|,
comment|/* rv2cv */
literal|0x00000700
block|,
comment|/* anoncode */
literal|0x00001c04
block|,
comment|/* prototype */
literal|0x00002101
block|,
comment|/* refgen */
literal|0x00001106
block|,
comment|/* srefgen */
literal|0x00009c8c
block|,
comment|/* ref */
literal|0x00091504
block|,
comment|/* bless */
literal|0x00000c08
block|,
comment|/* backtick */
literal|0x00099508
block|,
comment|/* glob */
literal|0x00000c08
block|,
comment|/* readline */
literal|0x00000c08
block|,
comment|/* rcatline */
literal|0x00001104
block|,
comment|/* regcmaybe */
literal|0x00001104
block|,
comment|/* regcreset */
literal|0x00001304
block|,
comment|/* regcomp */
literal|0x00000640
block|,
comment|/* match */
literal|0x00000604
block|,
comment|/* qr */
literal|0x00001654
block|,
comment|/* subst */
literal|0x00000354
block|,
comment|/* substcont */
literal|0x00001914
block|,
comment|/* trans */
literal|0x00000004
block|,
comment|/* sassign */
literal|0x00022208
block|,
comment|/* aassign */
literal|0x00002c0d
block|,
comment|/* chop */
literal|0x00009c8c
block|,
comment|/* schop */
literal|0x00002c0d
block|,
comment|/* chomp */
literal|0x00009c8c
block|,
comment|/* schomp */
literal|0x00009c94
block|,
comment|/* defined */
literal|0x00009c04
block|,
comment|/* undef */
literal|0x00009c84
block|,
comment|/* study */
literal|0x00009c8c
block|,
comment|/* pos */
literal|0x00001164
block|,
comment|/* preinc */
literal|0x00001154
block|,
comment|/* i_preinc */
literal|0x00001164
block|,
comment|/* predec */
literal|0x00001154
block|,
comment|/* i_predec */
literal|0x0000116c
block|,
comment|/* postinc */
literal|0x0000115c
block|,
comment|/* i_postinc */
literal|0x0000116c
block|,
comment|/* postdec */
literal|0x0000115c
block|,
comment|/* i_postdec */
literal|0x0001120e
block|,
comment|/* pow */
literal|0x0001122e
block|,
comment|/* multiply */
literal|0x0001121e
block|,
comment|/* i_multiply */
literal|0x0001122e
block|,
comment|/* divide */
literal|0x0001121e
block|,
comment|/* i_divide */
literal|0x0001123e
block|,
comment|/* modulo */
literal|0x0001121e
block|,
comment|/* i_modulo */
literal|0x00012209
block|,
comment|/* repeat */
literal|0x0001122e
block|,
comment|/* add */
literal|0x0001121e
block|,
comment|/* i_add */
literal|0x0001122e
block|,
comment|/* subtract */
literal|0x0001121e
block|,
comment|/* i_subtract */
literal|0x0001120e
block|,
comment|/* concat */
literal|0x0000150e
block|,
comment|/* stringify */
literal|0x0001120e
block|,
comment|/* left_shift */
literal|0x0001120e
block|,
comment|/* right_shift */
literal|0x00011236
block|,
comment|/* lt */
literal|0x00011216
block|,
comment|/* i_lt */
literal|0x00011236
block|,
comment|/* gt */
literal|0x00011216
block|,
comment|/* i_gt */
literal|0x00011236
block|,
comment|/* le */
literal|0x00011216
block|,
comment|/* i_le */
literal|0x00011236
block|,
comment|/* ge */
literal|0x00011216
block|,
comment|/* i_ge */
literal|0x00011236
block|,
comment|/* eq */
literal|0x00011216
block|,
comment|/* i_eq */
literal|0x00011236
block|,
comment|/* ne */
literal|0x00011216
block|,
comment|/* i_ne */
literal|0x0001123e
block|,
comment|/* ncmp */
literal|0x0001121e
block|,
comment|/* i_ncmp */
literal|0x00011216
block|,
comment|/* slt */
literal|0x00011216
block|,
comment|/* sgt */
literal|0x00011216
block|,
comment|/* sle */
literal|0x00011216
block|,
comment|/* sge */
literal|0x00011216
block|,
comment|/* seq */
literal|0x00011216
block|,
comment|/* sne */
literal|0x0001121e
block|,
comment|/* scmp */
literal|0x0001120e
block|,
comment|/* bit_and */
literal|0x0001120e
block|,
comment|/* bit_xor */
literal|0x0001120e
block|,
comment|/* bit_or */
literal|0x0000112e
block|,
comment|/* negate */
literal|0x0000111e
block|,
comment|/* i_negate */
literal|0x00001116
block|,
comment|/* not */
literal|0x0000110e
block|,
comment|/* complement */
literal|0x0001150e
block|,
comment|/* atan2 */
literal|0x00009c8e
block|,
comment|/* sin */
literal|0x00009c8e
block|,
comment|/* cos */
literal|0x00009c0c
block|,
comment|/* rand */
literal|0x00009c04
block|,
comment|/* srand */
literal|0x00009c8e
block|,
comment|/* exp */
literal|0x00009c8e
block|,
comment|/* log */
literal|0x00009c8e
block|,
comment|/* sqrt */
literal|0x00009c8e
block|,
comment|/* int */
literal|0x00009c8e
block|,
comment|/* hex */
literal|0x00009c8e
block|,
comment|/* oct */
literal|0x00009c8e
block|,
comment|/* abs */
literal|0x00009c9c
block|,
comment|/* length */
literal|0x0991150c
block|,
comment|/* substr */
literal|0x0011151c
block|,
comment|/* vec */
literal|0x0091151c
block|,
comment|/* index */
literal|0x0091151c
block|,
comment|/* rindex */
literal|0x0002150f
block|,
comment|/* sprintf */
literal|0x00021505
block|,
comment|/* formline */
literal|0x00009c9e
block|,
comment|/* ord */
literal|0x00009c8e
block|,
comment|/* chr */
literal|0x0001150e
block|,
comment|/* crypt */
literal|0x00009c8e
block|,
comment|/* ucfirst */
literal|0x00009c8e
block|,
comment|/* lcfirst */
literal|0x00009c8e
block|,
comment|/* uc */
literal|0x00009c8e
block|,
comment|/* lc */
literal|0x00009c8e
block|,
comment|/* quotemeta */
literal|0x00000148
block|,
comment|/* rv2av */
literal|0x00013804
block|,
comment|/* aelemfast */
literal|0x00013204
block|,
comment|/* aelem */
literal|0x00023501
block|,
comment|/* aslice */
literal|0x00004c08
block|,
comment|/* each */
literal|0x00004c08
block|,
comment|/* values */
literal|0x00004c08
block|,
comment|/* keys */
literal|0x00001c00
block|,
comment|/* delete */
literal|0x00001c14
block|,
comment|/* exists */
literal|0x00000148
block|,
comment|/* rv2hv */
literal|0x00014204
block|,
comment|/* helem */
literal|0x00024501
block|,
comment|/* hslice */
literal|0x00011500
block|,
comment|/* unpack */
literal|0x0002150d
block|,
comment|/* pack */
literal|0x00111508
block|,
comment|/* split */
literal|0x0002150d
block|,
comment|/* join */
literal|0x00002501
block|,
comment|/* list */
literal|0x00224200
block|,
comment|/* lslice */
literal|0x00002505
block|,
comment|/* anonlist */
literal|0x00002505
block|,
comment|/* anonhash */
literal|0x02993501
block|,
comment|/* splice */
literal|0x0002351d
block|,
comment|/* push */
literal|0x00003c04
block|,
comment|/* pop */
literal|0x00003c04
block|,
comment|/* shift */
literal|0x0002351d
block|,
comment|/* unshift */
literal|0x0002d501
block|,
comment|/* sort */
literal|0x00002509
block|,
comment|/* reverse */
literal|0x00025541
block|,
comment|/* grepstart */
literal|0x00000348
block|,
comment|/* grepwhile */
literal|0x00025541
block|,
comment|/* mapstart */
literal|0x00000348
block|,
comment|/* mapwhile */
literal|0x00011400
block|,
comment|/* range */
literal|0x00011100
block|,
comment|/* flip */
literal|0x00000100
block|,
comment|/* flop */
literal|0x00000300
block|,
comment|/* and */
literal|0x00000300
block|,
comment|/* or */
literal|0x00011306
block|,
comment|/* xor */
literal|0x00000440
block|,
comment|/* cond_expr */
literal|0x00000304
block|,
comment|/* andassign */
literal|0x00000304
block|,
comment|/* orassign */
literal|0x00000140
block|,
comment|/* method */
literal|0x00002149
block|,
comment|/* entersub */
literal|0x00000100
block|,
comment|/* leavesub */
literal|0x00009c08
block|,
comment|/* caller */
literal|0x0000251d
block|,
comment|/* warn */
literal|0x0000255d
block|,
comment|/* die */
literal|0x00009c14
block|,
comment|/* reset */
literal|0x00000500
block|,
comment|/* lineseq */
literal|0x00000b04
block|,
comment|/* nextstate */
literal|0x00000b04
block|,
comment|/* dbstate */
literal|0x00000004
block|,
comment|/* unstack */
literal|0x00000000
block|,
comment|/* enter */
literal|0x00000500
block|,
comment|/* leave */
literal|0x00000500
block|,
comment|/* scope */
literal|0x00000a40
block|,
comment|/* enteriter */
literal|0x00000000
block|,
comment|/* iter */
literal|0x00000a40
block|,
comment|/* enterloop */
literal|0x00000200
block|,
comment|/* leaveloop */
literal|0x00002541
block|,
comment|/* return */
literal|0x00000e44
block|,
comment|/* last */
literal|0x00000e44
block|,
comment|/* next */
literal|0x00000e44
block|,
comment|/* redo */
literal|0x00000e44
block|,
comment|/* dump */
literal|0x00000e44
block|,
comment|/* goto */
literal|0x00009c44
block|,
comment|/* exit */
literal|0x0009651c
block|,
comment|/* open */
literal|0x0000ec14
block|,
comment|/* close */
literal|0x00066514
block|,
comment|/* pipe_op */
literal|0x00006c1c
block|,
comment|/* fileno */
literal|0x00009c1c
block|,
comment|/* umask */
literal|0x00006c04
block|,
comment|/* binmode */
literal|0x00217555
block|,
comment|/* tie */
literal|0x00007c14
block|,
comment|/* untie */
literal|0x00007c04
block|,
comment|/* tied */
literal|0x00114514
block|,
comment|/* dbmopen */
literal|0x00004c14
block|,
comment|/* dbmclose */
literal|0x01111508
block|,
comment|/* sselect */
literal|0x0000e50c
block|,
comment|/* select */
literal|0x0000ec0c
block|,
comment|/* getc */
literal|0x0917651d
block|,
comment|/* read */
literal|0x0000ec54
block|,
comment|/* enterwrite */
literal|0x00000100
block|,
comment|/* leavewrite */
literal|0x0002e515
block|,
comment|/* prtf */
literal|0x0002e515
block|,
comment|/* print */
literal|0x09116504
block|,
comment|/* sysopen */
literal|0x00116504
block|,
comment|/* sysseek */
literal|0x0917651d
block|,
comment|/* sysread */
literal|0x0991651d
block|,
comment|/* syswrite */
literal|0x0911651d
block|,
comment|/* send */
literal|0x0117651d
block|,
comment|/* recv */
literal|0x0000ec14
block|,
comment|/* eof */
literal|0x0000ec0c
block|,
comment|/* tell */
literal|0x00116504
block|,
comment|/* seek */
literal|0x00011514
block|,
comment|/* truncate */
literal|0x0011650c
block|,
comment|/* fcntl */
literal|0x0011650c
block|,
comment|/* ioctl */
literal|0x0001651c
block|,
comment|/* flock */
literal|0x01116514
block|,
comment|/* socket */
literal|0x11166514
block|,
comment|/* sockpair */
literal|0x00016514
block|,
comment|/* bind */
literal|0x00016514
block|,
comment|/* connect */
literal|0x00016514
block|,
comment|/* listen */
literal|0x0006651c
block|,
comment|/* accept */
literal|0x0001651c
block|,
comment|/* shutdown */
literal|0x00116514
block|,
comment|/* gsockopt */
literal|0x01116514
block|,
comment|/* ssockopt */
literal|0x00006c14
block|,
comment|/* getsockname */
literal|0x00006c14
block|,
comment|/* getpeername */
literal|0x00006d80
block|,
comment|/* lstat */
literal|0x00006d80
block|,
comment|/* stat */
literal|0x00006d94
block|,
comment|/* ftrread */
literal|0x00006d94
block|,
comment|/* ftrwrite */
literal|0x00006d94
block|,
comment|/* ftrexec */
literal|0x00006d94
block|,
comment|/* fteread */
literal|0x00006d94
block|,
comment|/* ftewrite */
literal|0x00006d94
block|,
comment|/* fteexec */
literal|0x00006d94
block|,
comment|/* ftis */
literal|0x00006d94
block|,
comment|/* fteowned */
literal|0x00006d94
block|,
comment|/* ftrowned */
literal|0x00006d94
block|,
comment|/* ftzero */
literal|0x00006d9c
block|,
comment|/* ftsize */
literal|0x00006d8c
block|,
comment|/* ftmtime */
literal|0x00006d8c
block|,
comment|/* ftatime */
literal|0x00006d8c
block|,
comment|/* ftctime */
literal|0x00006d94
block|,
comment|/* ftsock */
literal|0x00006d94
block|,
comment|/* ftchr */
literal|0x00006d94
block|,
comment|/* ftblk */
literal|0x00006d94
block|,
comment|/* ftfile */
literal|0x00006d94
block|,
comment|/* ftdir */
literal|0x00006d94
block|,
comment|/* ftpipe */
literal|0x00006d94
block|,
comment|/* ftlink */
literal|0x00006d94
block|,
comment|/* ftsuid */
literal|0x00006d94
block|,
comment|/* ftsgid */
literal|0x00006d94
block|,
comment|/* ftsvtx */
literal|0x00006d14
block|,
comment|/* fttty */
literal|0x00006d94
block|,
comment|/* fttext */
literal|0x00006d94
block|,
comment|/* ftbinary */
literal|0x00009c1c
block|,
comment|/* chdir */
literal|0x0000251d
block|,
comment|/* chown */
literal|0x00009c9c
block|,
comment|/* chroot */
literal|0x0000259d
block|,
comment|/* unlink */
literal|0x0000251d
block|,
comment|/* chmod */
literal|0x0000251d
block|,
comment|/* utime */
literal|0x0001151c
block|,
comment|/* rename */
literal|0x0001151c
block|,
comment|/* link */
literal|0x0001151c
block|,
comment|/* symlink */
literal|0x00009c8c
block|,
comment|/* readlink */
literal|0x0001151c
block|,
comment|/* mkdir */
literal|0x00009c9c
block|,
comment|/* rmdir */
literal|0x00016514
block|,
comment|/* open_dir */
literal|0x00006c00
block|,
comment|/* readdir */
literal|0x00006c0c
block|,
comment|/* telldir */
literal|0x00016504
block|,
comment|/* seekdir */
literal|0x00006c04
block|,
comment|/* rewinddir */
literal|0x00006c14
block|,
comment|/* closedir */
literal|0x0000001c
block|,
comment|/* fork */
literal|0x0000001c
block|,
comment|/* wait */
literal|0x0001151c
block|,
comment|/* waitpid */
literal|0x0002951d
block|,
comment|/* system */
literal|0x0002955d
block|,
comment|/* exec */
literal|0x0000255d
block|,
comment|/* kill */
literal|0x0000001c
block|,
comment|/* getppid */
literal|0x00009c1c
block|,
comment|/* getpgrp */
literal|0x0009951c
block|,
comment|/* setpgrp */
literal|0x0001151c
block|,
comment|/* getpriority */
literal|0x0011151c
block|,
comment|/* setpriority */
literal|0x0000001c
block|,
comment|/* time */
literal|0x00000000
block|,
comment|/* tms */
literal|0x00009c08
block|,
comment|/* localtime */
literal|0x00009c08
block|,
comment|/* gmtime */
literal|0x00009c9c
block|,
comment|/* alarm */
literal|0x00009c1c
block|,
comment|/* sleep */
literal|0x0011151d
block|,
comment|/* shmget */
literal|0x0011151d
block|,
comment|/* shmctl */
literal|0x0111151d
block|,
comment|/* shmread */
literal|0x0111151d
block|,
comment|/* shmwrite */
literal|0x0001151d
block|,
comment|/* msgget */
literal|0x0011151d
block|,
comment|/* msgctl */
literal|0x0011151d
block|,
comment|/* msgsnd */
literal|0x1111151d
block|,
comment|/* msgrcv */
literal|0x0011151d
block|,
comment|/* semget */
literal|0x0111151d
block|,
comment|/* semctl */
literal|0x0001151d
block|,
comment|/* semop */
literal|0x00009cc0
block|,
comment|/* require */
literal|0x00001140
block|,
comment|/* dofile */
literal|0x00001c40
block|,
comment|/* entereval */
literal|0x00001100
block|,
comment|/* leaveeval */
literal|0x00000300
block|,
comment|/* entertry */
literal|0x00000500
block|,
comment|/* leavetry */
literal|0x00001c00
block|,
comment|/* ghbyname */
literal|0x00011500
block|,
comment|/* ghbyaddr */
literal|0x00000000
block|,
comment|/* ghostent */
literal|0x00001c00
block|,
comment|/* gnbyname */
literal|0x00011500
block|,
comment|/* gnbyaddr */
literal|0x00000000
block|,
comment|/* gnetent */
literal|0x00001c00
block|,
comment|/* gpbyname */
literal|0x00001500
block|,
comment|/* gpbynumber */
literal|0x00000000
block|,
comment|/* gprotoent */
literal|0x00011500
block|,
comment|/* gsbyname */
literal|0x00011500
block|,
comment|/* gsbyport */
literal|0x00000000
block|,
comment|/* gservent */
literal|0x00001c14
block|,
comment|/* shostent */
literal|0x00001c14
block|,
comment|/* snetent */
literal|0x00001c14
block|,
comment|/* sprotoent */
literal|0x00001c14
block|,
comment|/* sservent */
literal|0x00000014
block|,
comment|/* ehostent */
literal|0x00000014
block|,
comment|/* enetent */
literal|0x00000014
block|,
comment|/* eprotoent */
literal|0x00000014
block|,
comment|/* eservent */
literal|0x00001c00
block|,
comment|/* gpwnam */
literal|0x00001c00
block|,
comment|/* gpwuid */
literal|0x00000000
block|,
comment|/* gpwent */
literal|0x00000014
block|,
comment|/* spwent */
literal|0x00000014
block|,
comment|/* epwent */
literal|0x00001c00
block|,
comment|/* ggrnam */
literal|0x00001c00
block|,
comment|/* ggrgid */
literal|0x00000000
block|,
comment|/* ggrent */
literal|0x00000014
block|,
comment|/* sgrent */
literal|0x00000014
block|,
comment|/* egrent */
literal|0x0000000c
block|,
comment|/* getlogin */
literal|0x0002151d
block|,
comment|/* syscall */
literal|0x00001c04
block|,
comment|/* lock */
literal|0x00000044
block|,
comment|/* threadsv */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

