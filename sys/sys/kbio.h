begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KBIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KBIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* get/set keyboard I/O mode */
end_comment

begin_define
define|#
directive|define
name|K_RAW
value|0
end_define

begin_comment
comment|/* keyboard returns scancodes	*/
end_comment

begin_define
define|#
directive|define
name|K_XLATE
value|1
end_define

begin_comment
comment|/* keyboard returns ascii 	*/
end_comment

begin_define
define|#
directive|define
name|K_CODE
value|2
end_define

begin_comment
comment|/* keyboard returns keycodes 	*/
end_comment

begin_define
define|#
directive|define
name|KDGKBMODE
value|_IOR('K', 6, int)
end_define

begin_define
define|#
directive|define
name|KDSKBMODE
value|_IO('K', 7
comment|/*, int */
value|)
end_define

begin_comment
comment|/* make tone */
end_comment

begin_define
define|#
directive|define
name|KDMKTONE
value|_IO('K', 8
comment|/*, int */
value|)
end_define

begin_comment
comment|/* see console.h for the definitions of the following ioctls */
end_comment

begin_if
if|#
directive|if
name|notdef
end_if

begin_define
define|#
directive|define
name|KDGETMODE
value|_IOR('K', 9, int)
end_define

begin_define
define|#
directive|define
name|KDSETMODE
value|_IO('K', 10
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|KDSBORDER
value|_IO('K', 13
comment|/*, int */
value|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* get/set keyboard lock state */
end_comment

begin_define
define|#
directive|define
name|CLKED
value|1
end_define

begin_comment
comment|/* Caps locked			*/
end_comment

begin_define
define|#
directive|define
name|NLKED
value|2
end_define

begin_comment
comment|/* Num locked			*/
end_comment

begin_define
define|#
directive|define
name|SLKED
value|4
end_define

begin_comment
comment|/* Scroll locked		*/
end_comment

begin_define
define|#
directive|define
name|ALKED
value|8
end_define

begin_comment
comment|/* AltGr locked			*/
end_comment

begin_define
define|#
directive|define
name|LOCK_MASK
value|(CLKED | NLKED | SLKED | ALKED)
end_define

begin_define
define|#
directive|define
name|KDGKBSTATE
value|_IOR('K', 19, int)
end_define

begin_define
define|#
directive|define
name|KDSKBSTATE
value|_IO('K', 20
comment|/*, int */
value|)
end_define

begin_comment
comment|/* enable/disable I/O access */
end_comment

begin_define
define|#
directive|define
name|KDENABIO
value|_IO('K', 60)
end_define

begin_define
define|#
directive|define
name|KDDISABIO
value|_IO('K', 61)
end_define

begin_comment
comment|/* make sound */
end_comment

begin_define
define|#
directive|define
name|KIOCSOUND
value|_IO('K', 63
comment|/*, int */
value|)
end_define

begin_comment
comment|/* get keyboard model */
end_comment

begin_define
define|#
directive|define
name|KB_OTHER
value|0
end_define

begin_comment
comment|/* keyboard not known 		*/
end_comment

begin_define
define|#
directive|define
name|KB_84
value|1
end_define

begin_comment
comment|/* 'old' 84 key AT-keyboard	*/
end_comment

begin_define
define|#
directive|define
name|KB_101
value|2
end_define

begin_comment
comment|/* MF-101 or MF-102 keyboard	*/
end_comment

begin_define
define|#
directive|define
name|KDGKBTYPE
value|_IOR('K', 64, int)
end_define

begin_comment
comment|/* get/set keyboard LED state */
end_comment

begin_define
define|#
directive|define
name|LED_CAP
value|1
end_define

begin_comment
comment|/* Caps lock LED 		*/
end_comment

begin_define
define|#
directive|define
name|LED_NUM
value|2
end_define

begin_comment
comment|/* Num lock LED 		*/
end_comment

begin_define
define|#
directive|define
name|LED_SCR
value|4
end_define

begin_comment
comment|/* Scroll lock LED 		*/
end_comment

begin_define
define|#
directive|define
name|LED_MASK
value|(LED_CAP | LED_NUM | LED_SCR)
end_define

begin_define
define|#
directive|define
name|KDGETLED
value|_IOR('K', 65, int)
end_define

begin_define
define|#
directive|define
name|KDSETLED
value|_IO('K', 66
comment|/*, int */
value|)
end_define

begin_comment
comment|/* set keyboard repeat rate (obsolete, use KDSETREPEAT below) */
end_comment

begin_define
define|#
directive|define
name|KDSETRAD
value|_IO('K', 67
comment|/*, int */
value|)
end_define

begin_comment
comment|/* see console.h for the definition of the following ioctl */
end_comment

begin_if
if|#
directive|if
name|notdef
end_if

begin_define
define|#
directive|define
name|KDRASTER
value|_IOW('K', 100, scr_size_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* get keyboard information */
end_comment

begin_struct
struct|struct
name|keyboard_info
block|{
name|int
name|kb_index
decl_stmt|;
comment|/* kbdio index#			*/
name|char
name|kb_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* driver name			*/
name|int
name|kb_unit
decl_stmt|;
comment|/* unit#			*/
name|int
name|kb_type
decl_stmt|;
comment|/* KB_84, KB_101, KB_OTHER,...	*/
name|int
name|kb_config
decl_stmt|;
comment|/* device configuration flags	*/
name|int
name|kb_flags
decl_stmt|;
comment|/* internal flags		*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keyboard_info
name|keyboard_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KDGKBINFO
value|_IOR('K', 101, keyboard_info_t)
end_define

begin_comment
comment|/* set/get keyboard repeat rate (new interface) */
end_comment

begin_struct
struct|struct
name|keyboard_repeat
block|{
name|int
name|kb_repeat
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keyboard_repeat
name|keyboard_repeat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KDSETREPEAT
value|_IOW('K', 102, keyboard_repeat_t)
end_define

begin_define
define|#
directive|define
name|KDGETREPEAT
value|_IOR('K', 103, keyboard_repeat_t)
end_define

begin_comment
comment|/* get/set key map/accent map/function key strings */
end_comment

begin_define
define|#
directive|define
name|NUM_KEYS
value|256
end_define

begin_comment
comment|/* number of keys in table	*/
end_comment

begin_define
define|#
directive|define
name|NUM_STATES
value|8
end_define

begin_comment
comment|/* states per key		*/
end_comment

begin_define
define|#
directive|define
name|ALTGR_OFFSET
value|128
end_define

begin_comment
comment|/* offset for altlock keys	*/
end_comment

begin_define
define|#
directive|define
name|NUM_DEADKEYS
value|15
end_define

begin_comment
comment|/* number of accent keys	*/
end_comment

begin_define
define|#
directive|define
name|NUM_ACCENTCHARS
value|52
end_define

begin_comment
comment|/* max number of accent chars	*/
end_comment

begin_define
define|#
directive|define
name|NUM_FKEYS
value|96
end_define

begin_comment
comment|/* max number of function keys	*/
end_comment

begin_define
define|#
directive|define
name|MAXFK
value|16
end_define

begin_comment
comment|/* max length of a function key str */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KEYMAP_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_KEYMAP_DECLARED
end_define

begin_struct
struct|struct
name|keyent_t
block|{
name|u_char
name|map
index|[
name|NUM_STATES
index|]
decl_stmt|;
name|u_char
name|spcl
decl_stmt|;
name|u_char
name|flgs
decl_stmt|;
define|#
directive|define
name|FLAG_LOCK_O
value|0
define|#
directive|define
name|FLAG_LOCK_C
value|1
define|#
directive|define
name|FLAG_LOCK_N
value|2
block|}
struct|;
end_struct

begin_struct
struct|struct
name|keymap
block|{
name|u_short
name|n_keys
decl_stmt|;
name|struct
name|keyent_t
name|key
index|[
name|NUM_KEYS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keymap
name|keymap_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KEYMAP_DECLARED */
end_comment

begin_comment
comment|/* defines for "special" keys (spcl bit set in keymap) */
end_comment

begin_define
define|#
directive|define
name|NOP
value|0x00
end_define

begin_comment
comment|/* nothing (dead key)		*/
end_comment

begin_define
define|#
directive|define
name|LSH
value|0x02
end_define

begin_comment
comment|/* left shift key		*/
end_comment

begin_define
define|#
directive|define
name|RSH
value|0x03
end_define

begin_comment
comment|/* right shift key		*/
end_comment

begin_define
define|#
directive|define
name|CLK
value|0x04
end_define

begin_comment
comment|/* caps lock key		*/
end_comment

begin_define
define|#
directive|define
name|NLK
value|0x05
end_define

begin_comment
comment|/* num lock key			*/
end_comment

begin_define
define|#
directive|define
name|SLK
value|0x06
end_define

begin_comment
comment|/* scroll lock key		*/
end_comment

begin_define
define|#
directive|define
name|LALT
value|0x07
end_define

begin_comment
comment|/* left alt key			*/
end_comment

begin_define
define|#
directive|define
name|BTAB
value|0x08
end_define

begin_comment
comment|/* backwards tab		*/
end_comment

begin_define
define|#
directive|define
name|LCTR
value|0x09
end_define

begin_comment
comment|/* left control key		*/
end_comment

begin_define
define|#
directive|define
name|NEXT
value|0x0a
end_define

begin_comment
comment|/* switch to next screen 	*/
end_comment

begin_define
define|#
directive|define
name|F_SCR
value|0x0b
end_define

begin_comment
comment|/* switch to first screen 	*/
end_comment

begin_define
define|#
directive|define
name|L_SCR
value|0x1a
end_define

begin_comment
comment|/* switch to last screen 	*/
end_comment

begin_define
define|#
directive|define
name|F_FN
value|0x1b
end_define

begin_comment
comment|/* first function key 		*/
end_comment

begin_define
define|#
directive|define
name|L_FN
value|0x7a
end_define

begin_comment
comment|/* last function key 		*/
end_comment

begin_comment
comment|/*			0x7b-0x7f	   reserved do not use !	*/
end_comment

begin_define
define|#
directive|define
name|RCTR
value|0x80
end_define

begin_comment
comment|/* right control key		*/
end_comment

begin_define
define|#
directive|define
name|RALT
value|0x81
end_define

begin_comment
comment|/* right alt (altgr) key	*/
end_comment

begin_define
define|#
directive|define
name|ALK
value|0x82
end_define

begin_comment
comment|/* alt lock key			*/
end_comment

begin_define
define|#
directive|define
name|ASH
value|0x83
end_define

begin_comment
comment|/* alt shift key		*/
end_comment

begin_define
define|#
directive|define
name|META
value|0x84
end_define

begin_comment
comment|/* meta key			*/
end_comment

begin_define
define|#
directive|define
name|RBT
value|0x85
end_define

begin_comment
comment|/* boot machine			*/
end_comment

begin_define
define|#
directive|define
name|DBG
value|0x86
end_define

begin_comment
comment|/* call debugger		*/
end_comment

begin_define
define|#
directive|define
name|SUSP
value|0x87
end_define

begin_comment
comment|/* suspend power (APM)		*/
end_comment

begin_define
define|#
directive|define
name|SPSC
value|0x88
end_define

begin_comment
comment|/* toggle splash/text screen	*/
end_comment

begin_define
define|#
directive|define
name|F_ACC
value|DGRA
end_define

begin_comment
comment|/* first accent key		*/
end_comment

begin_define
define|#
directive|define
name|DGRA
value|0x89
end_define

begin_comment
comment|/* grave			*/
end_comment

begin_define
define|#
directive|define
name|DACU
value|0x8a
end_define

begin_comment
comment|/* acute			*/
end_comment

begin_define
define|#
directive|define
name|DCIR
value|0x8b
end_define

begin_comment
comment|/* circumflex			*/
end_comment

begin_define
define|#
directive|define
name|DTIL
value|0x8c
end_define

begin_comment
comment|/* tilde			*/
end_comment

begin_define
define|#
directive|define
name|DMAC
value|0x8d
end_define

begin_comment
comment|/* macron			*/
end_comment

begin_define
define|#
directive|define
name|DBRE
value|0x8e
end_define

begin_comment
comment|/* breve			*/
end_comment

begin_define
define|#
directive|define
name|DDOT
value|0x8f
end_define

begin_comment
comment|/* dot				*/
end_comment

begin_define
define|#
directive|define
name|DUML
value|0x90
end_define

begin_comment
comment|/* umlaut/diaresis		*/
end_comment

begin_define
define|#
directive|define
name|DDIA
value|0x90
end_define

begin_comment
comment|/* diaresis			*/
end_comment

begin_define
define|#
directive|define
name|DSLA
value|0x91
end_define

begin_comment
comment|/* slash			*/
end_comment

begin_define
define|#
directive|define
name|DRIN
value|0x92
end_define

begin_comment
comment|/* ring				*/
end_comment

begin_define
define|#
directive|define
name|DCED
value|0x93
end_define

begin_comment
comment|/* cedilla			*/
end_comment

begin_define
define|#
directive|define
name|DAPO
value|0x94
end_define

begin_comment
comment|/* apostrophe			*/
end_comment

begin_define
define|#
directive|define
name|DDAC
value|0x95
end_define

begin_comment
comment|/* double acute			*/
end_comment

begin_define
define|#
directive|define
name|DOGO
value|0x96
end_define

begin_comment
comment|/* ogonek			*/
end_comment

begin_define
define|#
directive|define
name|DCAR
value|0x97
end_define

begin_comment
comment|/* caron			*/
end_comment

begin_define
define|#
directive|define
name|L_ACC
value|DCAR
end_define

begin_comment
comment|/* last accent key		*/
end_comment

begin_define
define|#
directive|define
name|STBY
value|0x98
end_define

begin_comment
comment|/* Go into standby mode (apm)   */
end_comment

begin_define
define|#
directive|define
name|PREV
value|0x99
end_define

begin_comment
comment|/* switch to previous screen 	*/
end_comment

begin_define
define|#
directive|define
name|PNC
value|0x9a
end_define

begin_comment
comment|/* force system panic */
end_comment

begin_define
define|#
directive|define
name|LSHA
value|0x9b
end_define

begin_comment
comment|/* left shift key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|RSHA
value|0x9c
end_define

begin_comment
comment|/* right shift key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|LCTRA
value|0x9d
end_define

begin_comment
comment|/* left ctrl key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|RCTRA
value|0x9e
end_define

begin_comment
comment|/* right ctrl key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|LALTA
value|0x9f
end_define

begin_comment
comment|/* left alt key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|RALTA
value|0xa0
end_define

begin_comment
comment|/* right alt key / alt lock	*/
end_comment

begin_define
define|#
directive|define
name|HALT
value|0xa1
end_define

begin_comment
comment|/* halt machine */
end_comment

begin_define
define|#
directive|define
name|PDWN
value|0xa2
end_define

begin_comment
comment|/* halt machine and power down */
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|x
parameter_list|)
value|((x)+F_FN-1)
end_define

begin_define
define|#
directive|define
name|S
parameter_list|(
name|x
parameter_list|)
value|((x)+F_SCR-1)
end_define

begin_define
define|#
directive|define
name|ACC
parameter_list|(
name|x
parameter_list|)
value|((x)+F_ACC)
end_define

begin_struct
struct|struct
name|acc_t
block|{
name|u_char
name|accchar
decl_stmt|;
name|u_char
name|map
index|[
name|NUM_ACCENTCHARS
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|accentmap
block|{
name|u_short
name|n_accs
decl_stmt|;
name|struct
name|acc_t
name|acc
index|[
name|NUM_DEADKEYS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|accentmap
name|accentmap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|keyarg
block|{
name|u_short
name|keynum
decl_stmt|;
name|struct
name|keyent_t
name|key
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keyarg
name|keyarg_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fkeytab
block|{
name|u_char
name|str
index|[
name|MAXFK
index|]
decl_stmt|;
name|u_char
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fkeytab
name|fkeytab_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fkeyarg
block|{
name|u_short
name|keynum
decl_stmt|;
name|char
name|keydef
index|[
name|MAXFK
index|]
decl_stmt|;
name|char
name|flen
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fkeyarg
name|fkeyarg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GETFKEY
value|_IOWR('k', 0, fkeyarg_t)
end_define

begin_define
define|#
directive|define
name|SETFKEY
value|_IOWR('k', 1, fkeyarg_t)
end_define

begin_if
if|#
directive|if
name|notdef
end_if

begin_comment
comment|/* see console.h */
end_comment

begin_define
define|#
directive|define
name|GIO_SCRNMAP
value|_IOR('k', 2, scrmap_t)
end_define

begin_define
define|#
directive|define
name|PIO_SCRNMAP
value|_IOW('k', 3, scrmap_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GIO_KEYMAP
value|_IOR('k', 6, keymap_t)
end_define

begin_define
define|#
directive|define
name|PIO_KEYMAP
value|_IOW('k', 7, keymap_t)
end_define

begin_define
define|#
directive|define
name|GIO_DEADKEYMAP
value|_IOR('k', 8, accentmap_t)
end_define

begin_define
define|#
directive|define
name|PIO_DEADKEYMAP
value|_IOW('k', 9, accentmap_t)
end_define

begin_define
define|#
directive|define
name|GIO_KEYMAPENT
value|_IOWR('k', 10, keyarg_t)
end_define

begin_define
define|#
directive|define
name|PIO_KEYMAPENT
value|_IOW('k', 11, keyarg_t)
end_define

begin_comment
comment|/* flags set to the return value in the KD_XLATE mode */
end_comment

begin_define
define|#
directive|define
name|NOKEY
value|0x100
end_define

begin_comment
comment|/* no key pressed marker 	*/
end_comment

begin_define
define|#
directive|define
name|FKEY
value|0x200
end_define

begin_comment
comment|/* function key marker 		*/
end_comment

begin_define
define|#
directive|define
name|MKEY
value|0x400
end_define

begin_comment
comment|/* meta key marker (prepend ESC)*/
end_comment

begin_define
define|#
directive|define
name|BKEY
value|0x800
end_define

begin_comment
comment|/* backtab (ESC [ Z)		*/
end_comment

begin_define
define|#
directive|define
name|SPCLKEY
value|0x8000
end_define

begin_comment
comment|/* special key			*/
end_comment

begin_define
define|#
directive|define
name|RELKEY
value|0x4000
end_define

begin_comment
comment|/* key released			*/
end_comment

begin_define
define|#
directive|define
name|ERRKEY
value|0x2000
end_define

begin_comment
comment|/* error			*/
end_comment

begin_define
define|#
directive|define
name|KEYCHAR
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x00ff)
end_define

begin_define
define|#
directive|define
name|KEYFLAGS
parameter_list|(
name|c
parameter_list|)
value|((c)& ~0x00ff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KBIO_H_ */
end_comment

end_unit

