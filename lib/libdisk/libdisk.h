begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * ---------------------------------------------------------------------------- * "THE BEER-WARE LICENSE" (Revision 42): *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you * can do whatever you want with this stuff. If we meet some day, and you think * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp * ---------------------------------------------------------------------------- * * $FreeBSD$ * */
end_comment

begin_define
define|#
directive|define
name|MAX_NO_DISKS
value|32
end_define

begin_comment
comment|/* Max # of disks Disk_Names() will return */
end_comment

begin_define
define|#
directive|define
name|MAX_SEC_SIZE
value|2048
end_define

begin_comment
comment|/* maximum sector size that is supported */
end_comment

begin_define
define|#
directive|define
name|MIN_SEC_SIZE
value|512
end_define

begin_comment
comment|/* the sector size to end sensing at */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|whole
block|,
name|unknown
block|,
name|fat
block|,
name|freebsd
block|,
name|extended
block|,
name|part
block|,
name|unused
block|}
name|chunk_e
typedef|;
end_typedef

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct
struct|struct
name|disk
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|u_long
name|flags
decl_stmt|;
define|#
directive|define
name|DISK_ON_TRACK
value|1
name|u_long
name|bios_cyl
decl_stmt|;
name|u_long
name|bios_hd
decl_stmt|;
name|u_long
name|bios_sect
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|u_char
modifier|*
name|bootipl
decl_stmt|;
name|size_t
name|bootipl_size
decl_stmt|;
name|u_char
modifier|*
name|bootmenu
decl_stmt|;
name|size_t
name|bootmenu_size
decl_stmt|;
else|#
directive|else
name|u_char
modifier|*
name|bootmgr
decl_stmt|;
name|size_t
name|bootmgr_size
decl_stmt|;
endif|#
directive|endif
name|u_char
modifier|*
name|boot1
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
comment|/* the i386 needs extra help... */
name|u_char
modifier|*
name|boot2
decl_stmt|;
endif|#
directive|endif
name|struct
name|chunk
modifier|*
name|chunks
decl_stmt|;
name|u_long
name|sector_size
decl_stmt|;
comment|/* media sector size, a power of 2 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chunk
block|{
name|struct
name|chunk
modifier|*
name|next
decl_stmt|;
name|struct
name|chunk
modifier|*
name|part
decl_stmt|;
name|struct
name|disk
modifier|*
name|disk
decl_stmt|;
name|long
name|offset
decl_stmt|;
name|u_long
name|size
decl_stmt|;
name|u_long
name|end
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|char
modifier|*
name|sname
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|oname
decl_stmt|;
comment|/* Used during Fixup_Names() to avoid renaming more than 	 * absolutely needed. 	 */
name|chunk_e
name|type
decl_stmt|;
name|int
name|subtype
decl_stmt|;
name|u_long
name|flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|private_free
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|private_clone
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|private_data
decl_stmt|;
comment|/* For data private to the application, and the management 	 * thereof.  If the functions are not provided, no storage 	 * management is done, Cloning will just copy the pointer 	 * and freeing will just forget it. 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags:  *  * BSD_COMPAT	-	This chunk is in the BSD-compatibility, and has  *			a short name too, ie wd0s4f -> wd0f  * ALIGN	-	This chunk should be aligned  * IS_ROOT	-	This 'part' is a rootfs, allocate 'a'  * ACTIVE	-	This is the active slice in the MBR  * FORCE_ALL	-	Force a dedicated disk for FreeBSD, bypassing  *			all BIOS geometry considerations  * AUTO_SIZE	-	This chunk was auto-sized and can fill-out a  *			following chunk if the following chunk is deleted.  * NEWFS	-	newfs pending, used to enable auto-resizing on  *			delete (along with AUTO_SIZE).  */
end_comment

begin_define
define|#
directive|define
name|CHUNK_BSD_COMPAT
value|0x0002
end_define

begin_define
define|#
directive|define
name|CHUNK_ALIGN
value|0x0008
end_define

begin_define
define|#
directive|define
name|CHUNK_IS_ROOT
value|0x0010
end_define

begin_define
define|#
directive|define
name|CHUNK_ACTIVE
value|0x0020
end_define

begin_define
define|#
directive|define
name|CHUNK_FORCE_ALL
value|0x0040
end_define

begin_define
define|#
directive|define
name|CHUNK_AUTO_SIZE
value|0x0080
end_define

begin_define
define|#
directive|define
name|CHUNK_NEWFS
value|0x0100
end_define

begin_define
define|#
directive|define
name|DELCHUNK_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|DELCHUNK_RECOVER
value|0x0001
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|chunk_n
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|slice_type_name
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|subtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "chunk_n" for subtypes too  */
end_comment

begin_function_decl
name|struct
name|disk
modifier|*
name|Open_Disk
parameter_list|(
specifier|const
name|char
modifier|*
name|devname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Will open the named disk, and return populated tree.  */
end_comment

begin_function_decl
name|struct
name|disk
modifier|*
name|Clone_Disk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clone a copy of a tree.  Useful for "Undo" functionality  */
end_comment

begin_function_decl
name|void
name|Free_Disk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a tree made with Open_Disk() or Clone_Disk()  */
end_comment

begin_function_decl
name|void
name|Debug_Disk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print the content of the tree to stdout  */
end_comment

begin_function_decl
name|void
name|Set_Bios_Geom
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|u_long
name|cyl
parameter_list|,
name|u_long
name|heads
parameter_list|,
name|u_long
name|sects
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the geometry the bios uses.  */
end_comment

begin_function_decl
name|void
name|Sanitize_Bios_Geom
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bios geometry to something sane  */
end_comment

begin_function_decl
name|int
name|Delete_Chunk2
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|struct
name|chunk
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a chunk of disk_space modified by the passed  * flags.  */
end_comment

begin_function_decl
name|int
name|Delete_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|struct
name|chunk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a chunk of disk_space  */
end_comment

begin_function_decl
name|void
name|Collapse_Disk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Experimental, do not use.  */
end_comment

begin_function_decl
name|int
name|Collapse_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|struct
name|chunk
modifier|*
name|chunk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Experimental, do not use.  */
end_comment

begin_function_decl
name|int
ifdef|#
directive|ifdef
name|PC98
name|Create_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_long
name|size
parameter_list|,
name|chunk_e
name|type
parameter_list|,
name|int
name|subtype
parameter_list|,
name|u_long
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_macro
name|Create_Chunk
argument_list|(
argument|struct disk *disk
argument_list|,
argument|u_long offset
argument_list|,
argument|u_long size
argument_list|,
argument|chunk_e type
argument_list|,
argument|int subtype
argument_list|,
argument|u_long flags
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Create a chunk with the specified paramters  */
end_comment

begin_function_decl
name|void
name|All_FreeBSD
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|int
name|force_all
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make one FreeBSD chunk covering the entire disk;  * if force_all is set, bypass all BIOS geometry  * considerations.  */
end_comment

begin_function_decl
name|char
modifier|*
name|CheckRules
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return char* to warnings about broken design rules in this disklayout  */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|Disk_Names
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return char** with all disk's names (wd0, wd1 ...).  You must free  * each pointer, as well as the array by hand  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_function_decl
name|void
name|Set_Boot_Mgr
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bootipl
parameter_list|,
specifier|const
name|size_t
name|bootipl_size
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bootmenu
parameter_list|,
specifier|const
name|size_t
name|bootmenu_size
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|Set_Boot_Mgr
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bootmgr
parameter_list|,
specifier|const
name|size_t
name|bootmgr_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use this boot-manager on this disk.  Gets written when Write_Disk()  * is called  */
end_comment

begin_function_decl
name|int
name|Set_Boot_Blocks
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
specifier|const
name|u_char
modifier|*
name|_boot1
parameter_list|,
specifier|const
name|u_char
modifier|*
name|_boot2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use these boot-blocks on this disk.  Gets written when Write_Disk()  * is called. Returns nonzero upon failure.  */
end_comment

begin_function_decl
name|int
name|Write_Disk
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write all the MBRs, disklabels, bootblocks and boot managers  */
end_comment

begin_function_decl
name|int
name|Cyl_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if offset is aligned on a cylinder according to the  * bios geometry  */
end_comment

begin_function_decl
name|u_long
name|Next_Cyl_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Round offset up to next cylinder according to the bios-geometry  */
end_comment

begin_function_decl
name|u_long
name|Prev_Cyl_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Round offset down to previous cylinder according to the bios-  * geometry  */
end_comment

begin_function_decl
name|int
name|Track_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if offset is aligned on a track according to the  * bios geometry  */
end_comment

begin_function_decl
name|u_long
name|Next_Track_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Round offset up to next track according to the bios-geometry  */
end_comment

begin_function_decl
name|u_long
name|Prev_Track_Aligned
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if offset is aligned on a track according to the  * bios geometry  */
end_comment

begin_function_decl
name|struct
name|chunk
modifier|*
name|Create_Chunk_DWIM
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|struct
name|chunk
modifier|*
name|parent
parameter_list|,
name|u_long
name|size
parameter_list|,
name|chunk_e
name|type
parameter_list|,
name|int
name|subtype
parameter_list|,
name|u_long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This one creates a partition inside the given parent of the given  * size, and returns a pointer to it.  The first unused chunk big  * enough is used.  */
end_comment

begin_function_decl
name|int
name|MakeDev
parameter_list|(
name|struct
name|chunk
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MakeDevDisk
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make device nodes for all chunks on this disk */
end_comment

begin_function_decl
name|char
modifier|*
name|ShowChunkFlags
parameter_list|(
name|struct
name|chunk
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return string to show flags. */
end_comment

begin_function_decl
name|char
modifier|*
name|ChunkCanBeRoot
parameter_list|(
name|struct
name|chunk
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return NULL if chunk can be /, explanation otherwise */
end_comment

begin_comment
comment|/*  * Implementation details>>> DO NOT USE<<<  */
end_comment

begin_function_decl
name|void
name|Debug_Chunk
parameter_list|(
name|struct
name|chunk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Free_Chunk
parameter_list|(
name|struct
name|chunk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|chunk
modifier|*
name|Clone_Chunk
parameter_list|(
name|struct
name|chunk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_function_decl
name|int
name|Add_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|,
name|long
parameter_list|,
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|chunk_e
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|Add_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|,
name|long
parameter_list|,
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|chunk_e
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|read_block
parameter_list|(
name|int
parameter_list|,
name|daddr_t
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_block
parameter_list|(
name|int
parameter_list|,
name|daddr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|disklabel
modifier|*
name|read_disklabel
parameter_list|(
name|int
parameter_list|,
name|daddr_t
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|chunk
modifier|*
name|Find_Mother_Chunk
parameter_list|(
name|struct
name|chunk
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|chunk_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|disk
modifier|*
name|Int_Open_Disk
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Fixup_Names
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|dprintf
value|printf
end_define

begin_comment
comment|/* TODO  *  * Need a error string mechanism from the functions instead of warn()  *  * Make sure only FreeBSD start at offset==0  *  * Collapse must align.  *  * Make Write_Disk(struct disk*)  *  * Consider booting from OnTrack'ed disks.  *  * Get Bios-geom, ST506& OnTrack from driver (or otherwise)  *  * Make Create_DWIM().  *  * Make Is_Unchanged(struct disk *d1, struct chunk *c1)  *  * don't rename slices unless we have to  *  *Sample output from tst01:  *  * Debug_Disk(wd0)  flags=0  bios_geom=0/0/0  *>>        0x3d040          0    1411200    1411199 wd0      0 whole    0 0  *>>>>      0x3d080          0     960120     960119 wd0s1    3 freebsd  0 8  *>>>>>>    0x3d100          0      40960      40959 wd0s1a   5 part     0 0  *>>>>>>    0x3d180      40960     131072     172031 wd0s1b   5 part     0 0  *>>>>>>    0x3d1c0     172032     409600     581631 wd0s1e   5 part     0 0  *>>>>>>    0x3d200     581632     378488     960119 wd0s1f   5 part     0 0  *>>>>      0x3d140     960120       5670     965789 wd0s2    4 extended 0 8  *>>>>>>    0x3d2c0     960120         63     960182 -        6 unused   0 0  *>>>>>>    0x3d0c0     960183       5607     965789 wd0s5    2 fat      0 8  *>>>>      0x3d280     965790       1890     967679 wd0s3    1 foo      -2 8  *>>>>      0x3d300     967680     443520    1411199 wd0s4    3 freebsd  0 8  *>>>>>>    0x3d340     967680     443520    1411199 wd0s4a   5 part     0 0  *  * ^            ^           ^          ^          ^     ^      ^ ^        ^ ^  * level    chunkptr      start      size        end  name    type  subtype flags  *  * Underlying data structure:  *  *	Legend:  *<struct chunk> --> part  *			|  *			v next  *  *<wd0> --><wd0s1> --><wd0s1a>  *		     |           |  *		     |           v  *		     |<wd0s1b>  *		     |           |  *		     |           v  *		     |<wd0s1e>  *		     |           |  *		     |           v  *		     |<wd0s1f>  *		     |  *		     v  *<wd0s2> --><unused>  *		     |           |  *		     |           v  *		     |<wd0s5>  *		     |  *		     v  *<wd0s3>  *		     |  *		     v  *<wd0s4> --><wd0s4a>  *  *  */
end_comment

end_unit

