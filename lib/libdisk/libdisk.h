begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id$  *  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|whole
block|,
name|foo
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
block|,
name|reserved
block|}
name|chunk_e
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CHAR_N
value|static char *chunk_n[] = { \ 	"whole","foo","fat","freebsd","extended","part","unused","reserved"};
end_define

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
define|#
directive|define
name|DISK_REAL_GEOM
value|2
name|u_long
name|real_cyl
decl_stmt|;
name|u_long
name|real_hd
decl_stmt|;
name|u_long
name|real_sect
decl_stmt|;
name|u_long
name|bios_cyl
decl_stmt|;
name|u_long
name|bios_hd
decl_stmt|;
name|u_long
name|bios_sect
decl_stmt|;
name|struct
name|chunk
modifier|*
name|chunks
decl_stmt|;
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
name|u_long
name|offset
decl_stmt|;
name|u_long
name|size
decl_stmt|;
name|u_long
name|end
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|chunk_e
name|type
decl_stmt|;
name|int
name|subtype
decl_stmt|;
define|#
directive|define
name|SUBTYPE_BSD_FS
value|1
define|#
directive|define
name|SUBTYPE_BSD_SWAP
value|2
define|#
directive|define
name|SUBTYPE_BSD_UNUSED
value|3
name|u_long
name|flags
decl_stmt|;
define|#
directive|define
name|CHUNK_PAST_1024
value|1
comment|/* this chunk cannot be booted from */
define|#
directive|define
name|CHUNK_BSD_COMPAT
value|2
comment|/* this chunk is in the BSD-compatibility, and has a  			 * short name too, ie wd0s4f -> wd0f          		*/
define|#
directive|define
name|CHUNK_BAD144
value|4
comment|/* this chunk has bad144 mapping */
define|#
directive|define
name|CHUNK_ALIGN
value|8
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|disk
modifier|*
name|Open_Disk
parameter_list|(
name|char
modifier|*
name|devname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Will open the named disk, and return populated tree. 	 */
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
comment|/* Clone a copy of a tree.  Useful for "Undo" functionality 	 */
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
comment|/* Free a tree made with Open_Disk() or Clone_Disk() 	 */
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
comment|/* Print the content of the tree to stdout 	 */
end_comment

begin_function_decl
name|struct
name|disk
modifier|*
name|Set_Phys_Geom
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
comment|/* Use a different physical geometry.  Makes sense for ST506 disks only. 	 * The tree returned is read from the disk, using this geometry. 	 */
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
comment|/* Set the geometry the bios uses. 	 */
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
comment|/* Free a chunk of disk_space  	 */
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
comment|/* Experimental, do not use. 	 */
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
comment|/* Experimental, do not use. 	 */
end_comment

begin_function_decl
name|int
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a chunk with the specified paramters 	 */
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
comment|/* Return char* to warnings about broken design rules in this disklayout 	 */
end_comment

begin_comment
comment|/*   * Implementation details>>> DO NOT USE<<<  */
end_comment

begin_function_decl
name|struct
name|disk
modifier|*
name|Int_Open_Disk
parameter_list|(
name|char
modifier|*
name|devname
parameter_list|,
name|u_long
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|Add_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
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

begin_function_decl
name|void
name|Bios_Limit_Chunk
parameter_list|(
name|struct
name|chunk
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|read_block
parameter_list|(
name|int
parameter_list|,
name|daddr_t
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Aligned
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

begin_function_decl
name|u_long
name|Next_Aligned
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

begin_function_decl
name|u_long
name|Prev_Aligned
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

begin_define
define|#
directive|define
name|dprintf
value|printf
end_define

end_unit

