begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_enum
enum|enum
name|clnt_stat
block|{
name|___fake1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|auth_stat
block|{
name|___fake2
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|netconfig
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|address
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ldfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|syment
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tms
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dma_cb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uarg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statfs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statvfs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|itimerval
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mnttab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|strbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfstab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ldfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|syment
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scnhdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|exception
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nd_hostservlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nd_hostserv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utsname
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pollfd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|passwd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|spwd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|flock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|seg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sembuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sigaction
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utimbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|map
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|filehdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lineno
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nd_addrlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|FTW
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ustat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|qelem
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prpsinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|user
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|qelem
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|execenv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utmpx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|direct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rlimit
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|timeval
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|exportent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fstab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hostent
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|in_addr
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ldfile
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mallinfo
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|mint
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nmtent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pmaplist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|protoent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rpcent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|servent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|authdes_cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rpc_err
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ypall_callback
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|wait
union_decl|;
end_union_decl

begin_comment
comment|/* Get size_t and wchar_t.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* #include "sys/types.h" */
end_comment

begin_define
define|#
directive|define
name|ssize_t
value|int
end_define

begin_comment
comment|/* The actual types used here are mostly wrong,    but it is not supposed to matter what types we use here.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|proc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|div_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ldiv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|dl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|major_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|minor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|emcp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fpclass_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ecb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|aioop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evver_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evcntlcmds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|idtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|procset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|hostid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evpollcmds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|hrtime_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evqcntlcmds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evsiginfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evcontext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|evta_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|rlim_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cred_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|file_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vnode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fpos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|exhda_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ucontext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sess_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|hrtcmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|interval_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|stack_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|siginfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mblk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|paddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|qband_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|queue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|rf_resource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sr_mount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|timer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fpregset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|prstatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfssw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|eucwidth_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|page_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ulong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__gnuc_va_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|archdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|AUTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|CLIENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|DIR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf32_Ehdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf32_Phdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf32_Shdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Arhdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Arsym
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Cmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Scn
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Elf_Kind
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FIELD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FIELDTYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|PTF_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|PTF_void
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|PTF_charP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FILE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FORM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ITEM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MENU
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|OPTIONS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|PANEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|FTP_void
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|RPCBLIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|SCREEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|SVCXPRT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|TERMINAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|WINDOW
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|nl_catd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|nl_item
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|chtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|datum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fp_rnd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|spraycumul
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|WORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|VISIT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ACTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|jmp_buf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|sigjmp_buf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|xdrproc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|CALL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bool_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|DBM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|des_block
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|resultproc_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|mode_t
value|int
end_define

begin_define
define|#
directive|define
name|uid_t
value|int
end_define

begin_define
define|#
directive|define
name|gid_t
value|int
end_define

begin_define
define|#
directive|define
name|time_t
value|long
end_define

begin_define
define|#
directive|define
name|pid_t
value|int
end_define

begin_define
define|#
directive|define
name|signal_ret_t
value|int
end_define

begin_define
define|#
directive|define
name|wait_arg_t
value|union wait
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|signal_ret_t
value|void
end_define

begin_define
define|#
directive|define
name|wait_arg_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

