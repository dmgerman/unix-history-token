begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Written by Paul Popelka (paulp@uts.amdahl.com)  *  *  You can do anything you want with this software,  *    just don't say you wrote it,  *    and don't remove this notice.  *  *  This software is provided "as is".  *  *  The author supplies this software to be publicly  *  redistributed on the understanding that the author  *  is not responsible for the correct functioning of  *  this software in any circumstances and is not liable  *  for any damages caused by this software.  *  *  October 1992  *  *	$Id: fat.h,v 1.2 1993/10/16 19:29:29 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCFS_FAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCFS_FAT_H_
value|1
end_define

begin_comment
comment|/*  *  Some useful cluster numbers.  */
end_comment

begin_define
define|#
directive|define
name|PCFSROOT
value|0
end_define

begin_comment
comment|/* cluster 0 means the root dir		*/
end_comment

begin_define
define|#
directive|define
name|CLUST_FREE
value|0
end_define

begin_comment
comment|/* cluster 0 also means a free cluster	*/
end_comment

begin_define
define|#
directive|define
name|PCFSFREE
value|CLUST_FREE
end_define

begin_define
define|#
directive|define
name|CLUST_FIRST
value|2
end_define

begin_comment
comment|/* first legal cluster number		*/
end_comment

begin_define
define|#
directive|define
name|CLUST_RSRVS
value|0xfff0
end_define

begin_comment
comment|/* start of reserved cluster range	*/
end_comment

begin_define
define|#
directive|define
name|CLUST_RSRVE
value|0xfff6
end_define

begin_comment
comment|/* end of reserved cluster range	*/
end_comment

begin_define
define|#
directive|define
name|CLUST_BAD
value|0xfff7
end_define

begin_comment
comment|/* a cluster with a defect		*/
end_comment

begin_define
define|#
directive|define
name|CLUST_EOFS
value|0xfff8
end_define

begin_comment
comment|/* start of eof cluster range		*/
end_comment

begin_define
define|#
directive|define
name|CLUST_EOFE
value|0xffff
end_define

begin_comment
comment|/* end of eof cluster range		*/
end_comment

begin_define
define|#
directive|define
name|FAT12_MASK
value|0x0fff
end_define

begin_comment
comment|/* mask for 12 bit cluster numbers	*/
end_comment

begin_define
define|#
directive|define
name|FAT16_MASK
value|0xffff
end_define

begin_comment
comment|/* mask for 16 bit cluster numbers	*/
end_comment

begin_comment
comment|/*  *  Return true if filesystem uses 12 bit fats.  *  Microsoft Programmer's Reference says if the  *  maximum cluster number in a filesystem is greater  *  than 4086 then we've got a 16 bit fat filesystem.  */
end_comment

begin_define
define|#
directive|define
name|FAT12
parameter_list|(
name|pmp
parameter_list|)
value|(pmp->pm_maxcluster<= 4086)
end_define

begin_define
define|#
directive|define
name|FAT16
parameter_list|(
name|pmp
parameter_list|)
value|(pmp->pm_maxcluster>  4086)
end_define

begin_define
define|#
directive|define
name|PCFSEOF
parameter_list|(
name|cn
parameter_list|)
value|(((cn)& 0xfff8) == 0xfff8)
end_define

begin_comment
comment|/*  *  These are the values for the function argument to  *  the function fatentry().  */
end_comment

begin_define
define|#
directive|define
name|FAT_GET
value|0x0001
end_define

begin_comment
comment|/* get a fat entry		*/
end_comment

begin_define
define|#
directive|define
name|FAT_SET
value|0x0002
end_define

begin_comment
comment|/* set a fat entry		*/
end_comment

begin_define
define|#
directive|define
name|FAT_GET_AND_SET
value|(FAT_GET | FAT_SET)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_decl_stmt
name|int
name|pcbmap
name|__P
argument_list|(
operator|(
expr|struct
name|denode
operator|*
name|dep
operator|,
name|u_long
name|findcn
operator|,
name|daddr_t
operator|*
name|bnp
operator|,
name|u_long
operator|*
name|cnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clusterfree
name|__P
argument_list|(
operator|(
expr|struct
name|pcfsmount
operator|*
name|pmp
operator|,
name|u_long
name|cn
operator|,
name|u_long
operator|*
name|oldcnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clusteralloc
name|__P
argument_list|(
operator|(
expr|struct
name|pcfsmount
operator|*
name|pmp
operator|,
name|u_long
operator|*
name|retcluster
operator|,
name|u_long
name|fillwith
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fatentry
name|__P
argument_list|(
operator|(
name|int
name|function
operator|,
expr|struct
name|pcfsmount
operator|*
name|pmp
operator|,
name|u_long
name|cluster
operator|,
name|u_long
operator|*
name|oldcontents
operator|,
name|u_long
name|newcontents
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|freeclusterchain
name|__P
argument_list|(
operator|(
expr|struct
name|pcfsmount
operator|*
name|pmp
operator|,
name|u_long
name|startchain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCFS_FAT_H_ */
end_comment

end_unit

