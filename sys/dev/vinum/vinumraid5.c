begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Cybernet Corporation and Nan Yang Computer Services Limited.  *      All rights reserved.  *  *  This software was developed as part of the NetMAX project.  *  *  Written by Greg Lehey  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Cybernet Corporation  *      and Nan Yang Computer Services Limited  * 4. Neither the name of the Companies nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumraid5.c,v 1.21 2001/01/09 04:21:27 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/vinum/vinumhdr.h>
end_include

begin_include
include|#
directive|include
file|<dev/vinum/request.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_comment
comment|/*  * Parameters which describe the current transfer.  * These are only used for calculation, but they  * need to be passed to other functions, so it's  * tidier to put them in a struct  */
end_comment

begin_struct
struct|struct
name|metrics
block|{
name|daddr_t
name|stripebase
decl_stmt|;
comment|/* base address of stripe (1st subdisk) */
name|int
name|stripeoffset
decl_stmt|;
comment|/* offset in stripe */
name|int
name|stripesectors
decl_stmt|;
comment|/* total sectors to transfer in this stripe */
name|daddr_t
name|sdbase
decl_stmt|;
comment|/* offset in subdisk of stripe base */
name|int
name|sdcount
decl_stmt|;
comment|/* number of disks involved in this transfer */
name|daddr_t
name|diskstart
decl_stmt|;
comment|/* remember where this transfer starts */
name|int
name|psdno
decl_stmt|;
comment|/* number of parity subdisk */
name|int
name|badsdno
decl_stmt|;
comment|/* number of down subdisk, if there is one */
name|int
name|firstsdno
decl_stmt|;
comment|/* first data subdisk number */
comment|/* These correspond to the fields in rqelement, sort of */
name|int
name|useroffset
decl_stmt|;
comment|/*      * Initial offset and length values for the first      * data block      */
name|int
name|initoffset
decl_stmt|;
comment|/* start address of block to transfer */
name|short
name|initlen
decl_stmt|;
comment|/* length in sectors of data transfer */
comment|/* Define a normal operation */
name|int
name|dataoffset
decl_stmt|;
comment|/* start address of block to transfer */
name|int
name|datalen
decl_stmt|;
comment|/* length in sectors of data transfer */
comment|/* Define a group operation */
name|int
name|groupoffset
decl_stmt|;
comment|/* subdisk offset of group operation */
name|int
name|grouplen
decl_stmt|;
comment|/* length in sectors of group operation */
comment|/* Define a normal write operation */
name|int
name|writeoffset
decl_stmt|;
comment|/* subdisk offset of normal write */
name|int
name|writelen
decl_stmt|;
comment|/* length in sectors of write operation */
name|enum
name|xferinfo
name|flags
decl_stmt|;
comment|/* to check what we're doing */
name|int
name|rqcount
decl_stmt|;
comment|/* number of elements in request */
block|}
struct|;
end_struct

begin_function_decl
name|enum
name|requeststatus
name|bre5
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|,
name|int
name|plexno
parameter_list|,
name|daddr_t
modifier|*
name|diskstart
parameter_list|,
name|daddr_t
name|diskend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|complete_raid5_write
parameter_list|(
name|struct
name|rqelement
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|requeststatus
name|build_rq_buffer
parameter_list|(
name|struct
name|rqelement
modifier|*
name|rqe
parameter_list|,
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setrqebounds
parameter_list|(
name|struct
name|rqelement
modifier|*
name|rqe
parameter_list|,
name|struct
name|metrics
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * define the low-level requests needed to perform  * a high-level I/O operation for a specific plex  * 'plexno'.  *  * Return 0 if all subdisks involved in the  * request are up, 1 if some subdisks are not up,  * and -1 if the request is at least partially  * outside the bounds of the subdisks.  *  * Modify the pointer *diskstart to point to the  * end address.  On read, return on the first bad  * subdisk, so that the caller  * (build_read_request) can try alternatives.  *  * On entry to this routine, the prq structures  * are not assigned.  The assignment is performed  * by expandrq().  Strictly speaking, the elements  * rqe->sdno of all entries should be set to -1,  * since 0 (from bzero) is a valid subdisk number.  * We avoid this problem by initializing the ones  * we use, and not looking at the others (index>=  * prq->requests).  */
end_comment

begin_function
name|enum
name|requeststatus
name|bre5
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|,
name|int
name|plexno
parameter_list|,
name|daddr_t
modifier|*
name|diskaddr
parameter_list|,
name|daddr_t
name|diskend
parameter_list|)
block|{
name|struct
name|metrics
name|m
decl_stmt|;
comment|/* most of the information */
name|struct
name|sd
modifier|*
name|sd
decl_stmt|;
name|struct
name|plex
modifier|*
name|plex
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* user's bp */
name|struct
name|rqgroup
modifier|*
name|rqg
decl_stmt|;
comment|/* the request group that we will create */
name|struct
name|rqelement
modifier|*
name|rqe
decl_stmt|;
comment|/* point to this request information */
name|int
name|rsectors
decl_stmt|;
comment|/* sectors remaining in this stripe */
name|int
name|mysdno
decl_stmt|;
comment|/* another sd index in loops */
name|int
name|rqno
decl_stmt|;
comment|/* request number */
name|rqg
operator|=
name|NULL
expr_stmt|;
comment|/* shut up, damn compiler */
name|m
operator|.
name|diskstart
operator|=
operator|*
name|diskaddr
expr_stmt|;
comment|/* start of transfer */
name|bp
operator|=
name|rq
operator|->
name|bp
expr_stmt|;
comment|/* buffer pointer */
name|plex
operator|=
operator|&
name|PLEX
index|[
name|plexno
index|]
expr_stmt|;
comment|/* point to the plex */
while|while
condition|(
operator|*
name|diskaddr
operator|<
name|diskend
condition|)
block|{
comment|/* until we get it all sorted out */
if|if
condition|(
operator|*
name|diskaddr
operator|>=
name|plex
operator|->
name|length
condition|)
comment|/* beyond the end of the plex */
return|return
name|REQUEST_EOF
return|;
comment|/* can't continue */
name|m
operator|.
name|badsdno
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* no bad subdisk yet */
comment|/* Part A: Define the request */
comment|/* 	 * First, calculate some sizes: 	 * The offset of the start address from 	 * the start of the stripe. 	 */
name|m
operator|.
name|stripeoffset
operator|=
operator|*
name|diskaddr
operator|%
operator|(
name|plex
operator|->
name|stripesize
operator|*
operator|(
name|plex
operator|->
name|subdisks
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
comment|/* 	 * The plex-relative address of the 	 * start of the stripe. 	 */
name|m
operator|.
name|stripebase
operator|=
operator|*
name|diskaddr
operator|-
name|m
operator|.
name|stripeoffset
expr_stmt|;
comment|/* subdisk containing the parity stripe */
if|if
condition|(
name|plex
operator|->
name|organization
operator|==
name|plex_raid5
condition|)
name|m
operator|.
name|psdno
operator|=
name|plex
operator|->
name|subdisks
operator|-
literal|1
operator|-
operator|(
operator|*
name|diskaddr
operator|/
operator|(
name|plex
operator|->
name|stripesize
operator|*
operator|(
name|plex
operator|->
name|subdisks
operator|-
literal|1
operator|)
operator|)
operator|)
operator|%
name|plex
operator|->
name|subdisks
expr_stmt|;
else|else
comment|/* RAID-4 */
name|m
operator|.
name|psdno
operator|=
name|plex
operator|->
name|subdisks
operator|-
literal|1
expr_stmt|;
comment|/* 	 * The number of the subdisk in which 	 * the start is located. 	 */
name|m
operator|.
name|firstsdno
operator|=
name|m
operator|.
name|stripeoffset
operator|/
name|plex
operator|->
name|stripesize
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|firstsdno
operator|>=
name|m
operator|.
name|psdno
condition|)
comment|/* at or past parity sd */
name|m
operator|.
name|firstsdno
operator|++
expr_stmt|;
comment|/* increment it */
comment|/* 	 * The offset from the beginning of 	 * the stripe on this subdisk. 	 */
name|m
operator|.
name|initoffset
operator|=
name|m
operator|.
name|stripeoffset
operator|%
name|plex
operator|->
name|stripesize
expr_stmt|;
comment|/* The offset of the stripe start relative to this subdisk */
name|m
operator|.
name|sdbase
operator|=
name|m
operator|.
name|stripebase
operator|/
operator|(
name|plex
operator|->
name|subdisks
operator|-
literal|1
operator|)
expr_stmt|;
name|m
operator|.
name|useroffset
operator|=
operator|*
name|diskaddr
operator|-
name|m
operator|.
name|diskstart
expr_stmt|;
comment|/* The offset of the start in the user buffer */
comment|/* 	 * The number of sectors to transfer in the 	 * current (first) subdisk. 	 */
name|m
operator|.
name|initlen
operator|=
name|min
argument_list|(
name|diskend
operator|-
operator|*
name|diskaddr
argument_list|,
comment|/* the amount remaining to transfer */
name|plex
operator|->
name|stripesize
operator|-
name|m
operator|.
name|initoffset
argument_list|)
expr_stmt|;
comment|/* and the amount left in this block */
comment|/* 	 * The number of sectors to transfer in this stripe 	 * is the minumum of the amount remaining to transfer 	 * and the amount left in this stripe. 	 */
name|m
operator|.
name|stripesectors
operator|=
name|min
argument_list|(
name|diskend
operator|-
operator|*
name|diskaddr
argument_list|,
name|plex
operator|->
name|stripesize
operator|*
operator|(
name|plex
operator|->
name|subdisks
operator|-
literal|1
operator|)
operator|-
name|m
operator|.
name|stripeoffset
argument_list|)
expr_stmt|;
comment|/* The number of data subdisks involved in this request */
name|m
operator|.
name|sdcount
operator|=
operator|(
name|m
operator|.
name|stripesectors
operator|+
name|m
operator|.
name|initoffset
operator|+
name|plex
operator|->
name|stripesize
operator|-
literal|1
operator|)
operator|/
name|plex
operator|->
name|stripesize
expr_stmt|;
comment|/* Part B: decide what kind of transfer this will be.  	 * start and end addresses of the transfer in 	 * the current block. 	 * 	 * There are a number of different kinds of 	 * transfer, each of which relates to a 	 * specific subdisk: 	 * 	 * 1. Normal read.  All participating subdisks 	 *    are up, and the transfer can be made 	 *    directly to the user buffer.  The bounds 	 *    of the transfer are described by 	 *    m.dataoffset and m.datalen.  We have 	 *    already calculated m.initoffset and 	 *    m.initlen, which define the parameters 	 *    for the first data block. 	 * 	 * 2. Recovery read.  One participating 	 *    subdisk is down.  To recover data, all 	 *    the other subdisks, including the parity 	 *    subdisk, must be read.  The data is 	 *    recovered by exclusive-oring all the 	 *    other blocks.  The bounds of the 	 *    transfer are described by m.groupoffset 	 *    and m.grouplen. 	 * 	 * 3. A read request may request reading both 	 *    available data (normal read) and 	 *    non-available data (recovery read). 	 *    This can be a problem if the address 	 *    ranges of the two reads do not coincide: 	 *    in this case, the normal read needs to 	 *    be extended to cover the address range 	 *    of the recovery read, and must thus be 	 *    performed out of malloced memory. 	 * 	 * 4. Normal write.  All the participating 	 *    subdisks are up.  The bounds of the 	 *    transfer are described by m.dataoffset 	 *    and m.datalen.  Since these values 	 *    differ for each block, we calculate the 	 *    bounds for the parity block 	 *    independently as the maximum of the 	 *    individual blocks and store these values 	 *    in m.writeoffset and m.writelen.  This 	 *    write proceeds in four phases: 	 * 	 *    i.  Read the old contents of each block 	 *        and the parity block. 	 *    ii.  ``Remove'' the old contents from 	 *         the parity block with exclusive or. 	 *    iii. ``Insert'' the new contents of the 	 *          block in the parity block, again 	 *          with exclusive or. 	 * 	 *    iv.  Write the new contents of the data 	 *         blocks and the parity block.  The data 	 *         block transfers can be made directly from 	 *         the user buffer. 	 * 	 * 5. Degraded write where the data block is 	 *    not available.  The bounds of the 	 *    transfer are described by m.groupoffset 	 *    and m.grouplen. This requires the 	 *    following steps: 	 * 	 *    i.  Read in all the other data blocks, 	 *        excluding the parity block. 	 * 	 *    ii.  Recreate the parity block from the 	 *         other data blocks and the data to be 	 *         written. 	 * 	 *    iii. Write the parity block. 	 * 	 * 6. Parityless write, a write where the 	 *    parity block is not available.  This is 	 *    in fact the simplest: just write the 	 *    data blocks.  This can proceed directly 	 *    from the user buffer.  The bounds of the 	 *    transfer are described by m.dataoffset 	 *    and m.datalen. 	 * 	 * 7. Combination of degraded data block write 	 *    and normal write.  In this case the 	 *    address ranges of the reads may also 	 *    need to be extended to cover all 	 *    participating blocks. 	 * 	 * All requests in a group transfer transfer 	 * the same address range relative to their 	 * subdisk.  The individual transfers may 	 * vary, but since our group of requests is 	 * all in a single slice, we can define a 	 * range in which they all fall. 	 * 	 * In the following code section, we determine 	 * which kind of transfer we will perform.  If 	 * there is a group transfer, we also decide 	 * its bounds relative to the subdisks.  At 	 * the end, we have the following values: 	 * 	 *  m.flags indicates the kinds of transfers 	 *    we will perform. 	 *  m.initoffset indicates the offset of the 	 *    beginning of any data operation relative 	 *    to the beginning of the stripe base. 	 *  m.initlen specifies the length of any data 	 *    operation. 	 *  m.dataoffset contains the same value as 	 *    m.initoffset. 	 *  m.datalen contains the same value as 	 *    m.initlen.  Initially dataoffset and 	 *    datalen describe the parameters for the 	 *    first data block; while building the data 	 *    block requests, they are updated for each 	 *    block. 	 *  m.groupoffset indicates the offset of any 	 *    group operation relative to the beginning 	 *    of the stripe base. 	 *  m.grouplen specifies the length of any 	 *    group operation. 	 *  m.writeoffset indicates the offset of a 	 *    normal write relative to the beginning of 	 *    the stripe base.  This value differs from 	 *    m.dataoffset in that it applies to the 	 *    entire operation, and not just the first 	 *    block. 	 *  m.writelen specifies the total span of a 	 *    normal write operation.  writeoffset and 	 *    writelen are used to define the parity 	 *    block. 	 */
name|m
operator|.
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* assume no group... */
name|m
operator|.
name|grouplen
operator|=
literal|0
expr_stmt|;
comment|/* until we know we have one */
name|m
operator|.
name|writeoffset
operator|=
name|m
operator|.
name|initoffset
expr_stmt|;
comment|/* start offset of transfer */
name|m
operator|.
name|writelen
operator|=
literal|0
expr_stmt|;
comment|/* nothing to write yet */
name|m
operator|.
name|flags
operator|=
literal|0
expr_stmt|;
comment|/* no flags yet */
name|rsectors
operator|=
name|m
operator|.
name|stripesectors
expr_stmt|;
comment|/* remaining sectors to examine */
name|m
operator|.
name|dataoffset
operator|=
name|m
operator|.
name|initoffset
expr_stmt|;
comment|/* start at the beginning of the transfer */
name|m
operator|.
name|datalen
operator|=
name|m
operator|.
name|initlen
expr_stmt|;
if|if
condition|(
name|m
operator|.
name|sdcount
operator|>
literal|1
condition|)
block|{
name|plex
operator|->
name|multiblock
operator|++
expr_stmt|;
comment|/* more than one block for the request */
comment|/* 	     * If we have two transfers that don't overlap, 	     * (one at the end of the first block, the other 	     * at the beginning of the second block), 	     * it's cheaper to split them. 	     */
if|if
condition|(
name|rsectors
operator|<
name|plex
operator|->
name|stripesize
condition|)
block|{
name|m
operator|.
name|sdcount
operator|=
literal|1
expr_stmt|;
comment|/* just one subdisk */
name|m
operator|.
name|stripesectors
operator|=
name|m
operator|.
name|initlen
expr_stmt|;
comment|/* and just this many sectors */
name|rsectors
operator|=
name|m
operator|.
name|initlen
expr_stmt|;
comment|/* and in the loop counter */
block|}
block|}
if|if
condition|(
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|m
operator|.
name|psdno
index|]
index|]
operator|.
name|state
operator|<
name|sd_reborn
condition|)
comment|/* is our parity subdisk down? */
name|m
operator|.
name|badsdno
operator|=
name|m
operator|.
name|psdno
expr_stmt|;
comment|/* note that it's down */
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|)
block|{
comment|/* read operation */
for|for
control|(
name|mysdno
operator|=
name|m
operator|.
name|firstsdno
init|;
name|rsectors
operator|>
literal|0
condition|;
name|mysdno
operator|++
control|)
block|{
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* ignore parity on read */
name|mysdno
operator|++
expr_stmt|;
if|if
condition|(
name|mysdno
operator|==
name|plex
operator|->
name|subdisks
condition|)
comment|/* wraparound */
name|mysdno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
if|if
condition|(
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|mysdno
index|]
index|]
operator|.
name|state
operator|<
name|sd_reborn
condition|)
block|{
comment|/* got a bad subdisk, */
if|if
condition|(
name|m
operator|.
name|badsdno
operator|>=
literal|0
condition|)
comment|/* we had one already, */
return|return
name|REQUEST_DOWN
return|;
comment|/* we can't take a second */
name|m
operator|.
name|badsdno
operator|=
name|mysdno
expr_stmt|;
comment|/* got the first */
name|m
operator|.
name|groupoffset
operator|=
name|m
operator|.
name|dataoffset
expr_stmt|;
comment|/* define the bounds */
name|m
operator|.
name|grouplen
operator|=
name|m
operator|.
name|datalen
expr_stmt|;
name|m
operator|.
name|flags
operator||=
name|XFR_RECOVERY_READ
expr_stmt|;
comment|/* we need recovery */
name|plex
operator|->
name|recovered_reads
operator|++
expr_stmt|;
comment|/* count another one */
block|}
else|else
name|m
operator|.
name|flags
operator||=
name|XFR_NORMAL_READ
expr_stmt|;
comment|/* normal read */
comment|/* Update the pointers for the next block */
name|m
operator|.
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* back to the start of the stripe */
name|rsectors
operator|-=
name|m
operator|.
name|datalen
expr_stmt|;
comment|/* remaining sectors to examine */
name|m
operator|.
name|datalen
operator|=
name|min
argument_list|(
name|rsectors
argument_list|,
name|plex
operator|->
name|stripesize
argument_list|)
expr_stmt|;
comment|/* amount that will fit in this block */
block|}
block|}
else|else
block|{
comment|/* write operation */
for|for
control|(
name|mysdno
operator|=
name|m
operator|.
name|firstsdno
init|;
name|rsectors
operator|>
literal|0
condition|;
name|mysdno
operator|++
control|)
block|{
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity stripe, we've dealt with that */
name|mysdno
operator|++
expr_stmt|;
if|if
condition|(
name|mysdno
operator|==
name|plex
operator|->
name|subdisks
condition|)
comment|/* wraparound */
name|mysdno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
name|sd
operator|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|mysdno
index|]
index|]
expr_stmt|;
if|if
condition|(
name|sd
operator|->
name|state
operator|!=
name|sd_up
condition|)
block|{
name|enum
name|requeststatus
name|s
decl_stmt|;
name|s
operator|=
name|checksdstate
argument_list|(
name|sd
argument_list|,
name|rq
argument_list|,
operator|*
name|diskaddr
argument_list|,
name|diskend
argument_list|)
expr_stmt|;
comment|/* do we need to change state? */
if|if
condition|(
name|s
operator|&&
operator|(
name|m
operator|.
name|badsdno
operator|>=
literal|0
operator|)
condition|)
block|{
comment|/* second bad disk, */
name|int
name|sdno
decl_stmt|;
comment|/* 			 * If the parity disk is down, there's 			 * no recovery.  We make all involved 			 * subdisks stale.  Otherwise, we 			 * should be able to recover, but it's 			 * like pulling teeth.  Fix it later. 			 */
for|for
control|(
name|sdno
operator|=
literal|0
init|;
name|sdno
operator|<
name|m
operator|.
name|sdcount
condition|;
name|sdno
operator|++
control|)
block|{
name|struct
name|sd
modifier|*
name|sd
init|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|sdno
index|]
index|]
decl_stmt|;
if|if
condition|(
name|sd
operator|->
name|state
operator|>=
name|sd_reborn
condition|)
comment|/* sort of up, */
name|set_sd_state
argument_list|(
name|sd
operator|->
name|sdno
argument_list|,
name|sd_stale
argument_list|,
name|setstate_force
argument_list|)
expr_stmt|;
comment|/* make it stale */
block|}
return|return
name|s
return|;
comment|/* and crap out */
block|}
name|m
operator|.
name|badsdno
operator|=
name|mysdno
expr_stmt|;
comment|/* note which one is bad */
name|m
operator|.
name|flags
operator||=
name|XFR_DEGRADED_WRITE
expr_stmt|;
comment|/* we need recovery */
name|plex
operator|->
name|degraded_writes
operator|++
expr_stmt|;
comment|/* count another one */
name|m
operator|.
name|groupoffset
operator|=
name|m
operator|.
name|dataoffset
expr_stmt|;
comment|/* define the bounds */
name|m
operator|.
name|grouplen
operator|=
name|m
operator|.
name|datalen
expr_stmt|;
block|}
else|else
block|{
name|m
operator|.
name|flags
operator||=
name|XFR_NORMAL_WRITE
expr_stmt|;
comment|/* normal write operation */
if|if
condition|(
name|m
operator|.
name|writeoffset
operator|>
name|m
operator|.
name|dataoffset
condition|)
block|{
comment|/* move write operation lower */
name|m
operator|.
name|writelen
operator|=
name|max
argument_list|(
name|m
operator|.
name|writeoffset
operator|+
name|m
operator|.
name|writelen
argument_list|,
name|m
operator|.
name|dataoffset
operator|+
name|m
operator|.
name|datalen
argument_list|)
operator|-
name|m
operator|.
name|dataoffset
expr_stmt|;
name|m
operator|.
name|writeoffset
operator|=
name|m
operator|.
name|dataoffset
expr_stmt|;
block|}
else|else
name|m
operator|.
name|writelen
operator|=
name|max
argument_list|(
name|m
operator|.
name|writeoffset
operator|+
name|m
operator|.
name|writelen
argument_list|,
name|m
operator|.
name|dataoffset
operator|+
name|m
operator|.
name|datalen
argument_list|)
operator|-
name|m
operator|.
name|writeoffset
expr_stmt|;
block|}
comment|/* Update the pointers for the next block */
name|m
operator|.
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* back to the start of the stripe */
name|rsectors
operator|-=
name|m
operator|.
name|datalen
expr_stmt|;
comment|/* remaining sectors to examine */
name|m
operator|.
name|datalen
operator|=
name|min
argument_list|(
name|rsectors
argument_list|,
name|plex
operator|->
name|stripesize
argument_list|)
expr_stmt|;
comment|/* amount that will fit in this block */
block|}
if|if
condition|(
name|m
operator|.
name|badsdno
operator|==
name|m
operator|.
name|psdno
condition|)
block|{
comment|/* got a bad parity block, */
name|struct
name|sd
modifier|*
name|psd
init|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|m
operator|.
name|psdno
index|]
index|]
decl_stmt|;
if|if
condition|(
name|psd
operator|->
name|state
operator|==
name|sd_down
condition|)
name|set_sd_state
argument_list|(
name|psd
operator|->
name|sdno
argument_list|,
name|sd_obsolete
argument_list|,
name|setstate_force
argument_list|)
expr_stmt|;
comment|/* it's obsolete now */
elseif|else
if|if
condition|(
name|psd
operator|->
name|state
operator|==
name|sd_crashed
condition|)
name|set_sd_state
argument_list|(
name|psd
operator|->
name|sdno
argument_list|,
name|sd_stale
argument_list|,
name|setstate_force
argument_list|)
expr_stmt|;
comment|/* it's stale now */
name|m
operator|.
name|flags
operator|&=
operator|~
name|XFR_NORMAL_WRITE
expr_stmt|;
comment|/* this write isn't normal, */
name|m
operator|.
name|flags
operator||=
name|XFR_PARITYLESS_WRITE
expr_stmt|;
comment|/* it's parityless */
name|plex
operator|->
name|parityless_writes
operator|++
expr_stmt|;
comment|/* count another one */
block|}
block|}
comment|/* reset the initial transfer values */
name|m
operator|.
name|dataoffset
operator|=
name|m
operator|.
name|initoffset
expr_stmt|;
comment|/* start at the beginning of the transfer */
name|m
operator|.
name|datalen
operator|=
name|m
operator|.
name|initlen
expr_stmt|;
comment|/* decide how many requests we need */
if|if
condition|(
name|m
operator|.
name|flags
operator|&
operator|(
name|XFR_RECOVERY_READ
operator||
name|XFR_DEGRADED_WRITE
operator|)
condition|)
comment|/* doing a recovery read or degraded write, */
name|m
operator|.
name|rqcount
operator|=
name|plex
operator|->
name|subdisks
expr_stmt|;
comment|/* all subdisks */
elseif|else
if|if
condition|(
name|m
operator|.
name|flags
operator|&
name|XFR_NORMAL_WRITE
condition|)
comment|/* normal write, */
name|m
operator|.
name|rqcount
operator|=
name|m
operator|.
name|sdcount
operator|+
literal|1
expr_stmt|;
comment|/* all data blocks and the parity block */
else|else
comment|/* parityless write or normal read */
name|m
operator|.
name|rqcount
operator|=
name|m
operator|.
name|sdcount
expr_stmt|;
comment|/* just the data blocks */
comment|/* Part C: build the requests */
name|rqg
operator|=
name|allocrqg
argument_list|(
name|rq
argument_list|,
name|m
operator|.
name|rqcount
argument_list|)
expr_stmt|;
comment|/* get a request group */
if|if
condition|(
name|rqg
operator|==
name|NULL
condition|)
block|{
comment|/* malloc failed */
name|bp
operator|->
name|b_error
operator|=
name|ENOMEM
expr_stmt|;
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
return|return
name|REQUEST_ENOMEM
return|;
block|}
name|rqg
operator|->
name|plexno
operator|=
name|plexno
expr_stmt|;
name|rqg
operator|->
name|flags
operator|=
name|m
operator|.
name|flags
expr_stmt|;
name|rqno
operator|=
literal|0
expr_stmt|;
comment|/* index in the request group */
comment|/* 1: PARITY BLOCK */
comment|/* 	 * Are we performing an operation which requires parity?  In that case, 	 * work out the parameters and define the parity block. 	 * XFR_PARITYOP is XFR_NORMAL_WRITE | XFR_RECOVERY_READ | XFR_DEGRADED_WRITE 	 */
if|if
condition|(
name|m
operator|.
name|flags
operator|&
name|XFR_PARITYOP
condition|)
block|{
comment|/* need parity */
name|rqe
operator|=
operator|&
name|rqg
operator|->
name|rqe
index|[
name|rqno
index|]
expr_stmt|;
comment|/* point to element */
name|sd
operator|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|m
operator|.
name|psdno
index|]
index|]
expr_stmt|;
comment|/* the subdisk in question */
name|rqe
operator|->
name|rqg
operator|=
name|rqg
expr_stmt|;
comment|/* point back to group */
name|rqe
operator|->
name|flags
operator|=
operator|(
name|m
operator|.
name|flags
operator||
name|XFR_PARITY_BLOCK
operator||
name|XFR_MALLOCED
operator|)
comment|/* always malloc parity block */
operator|&
operator|~
operator|(
name|XFR_NORMAL_READ
operator||
name|XFR_PARITYLESS_WRITE
operator|)
expr_stmt|;
comment|/* transfer flags without data op stuf */
name|setrqebounds
argument_list|(
name|rqe
argument_list|,
operator|&
name|m
argument_list|)
expr_stmt|;
comment|/* set up the bounds of the transfer */
name|rqe
operator|->
name|sdno
operator|=
name|sd
operator|->
name|sdno
expr_stmt|;
comment|/* subdisk number */
name|rqe
operator|->
name|driveno
operator|=
name|sd
operator|->
name|driveno
expr_stmt|;
if|if
condition|(
name|build_rq_buffer
argument_list|(
name|rqe
argument_list|,
name|plex
argument_list|)
condition|)
comment|/* build the buffer */
return|return
name|REQUEST_ENOMEM
return|;
comment|/* can't do it */
name|rqe
operator|->
name|b
operator|.
name|b_flags
operator||=
name|B_READ
expr_stmt|;
comment|/* we must read first */
name|m
operator|.
name|sdcount
operator|++
expr_stmt|;
comment|/* adjust the subdisk count */
name|rqno
operator|++
expr_stmt|;
comment|/* and point to the next request */
block|}
comment|/* 	 * 2: DATA BLOCKS 	 * Now build up requests for the blocks required 	 * for individual transfers 	 */
for|for
control|(
name|mysdno
operator|=
name|m
operator|.
name|firstsdno
init|;
name|rqno
operator|<
name|m
operator|.
name|sdcount
condition|;
name|mysdno
operator|++
operator|,
name|rqno
operator|++
control|)
block|{
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
if|if
condition|(
name|mysdno
operator|==
name|plex
operator|->
name|subdisks
condition|)
comment|/* got to the end, */
name|mysdno
operator|=
literal|0
expr_stmt|;
comment|/* wrap around */
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
name|rqe
operator|=
operator|&
name|rqg
operator|->
name|rqe
index|[
name|rqno
index|]
expr_stmt|;
comment|/* point to element */
name|sd
operator|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|mysdno
index|]
index|]
expr_stmt|;
comment|/* the subdisk in question */
name|rqe
operator|->
name|rqg
operator|=
name|rqg
expr_stmt|;
comment|/* point to group */
if|if
condition|(
name|m
operator|.
name|flags
operator|&
name|XFR_NEEDS_MALLOC
condition|)
comment|/* we need a malloced buffer first */
name|rqe
operator|->
name|flags
operator|=
name|m
operator|.
name|flags
operator||
name|XFR_DATA_BLOCK
operator||
name|XFR_MALLOCED
expr_stmt|;
comment|/* transfer flags */
else|else
name|rqe
operator|->
name|flags
operator|=
name|m
operator|.
name|flags
operator||
name|XFR_DATA_BLOCK
expr_stmt|;
comment|/* transfer flags */
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|badsdno
condition|)
block|{
comment|/* this is the bad subdisk */
name|rqg
operator|->
name|badsdno
operator|=
name|rqno
expr_stmt|;
comment|/* note which one */
name|rqe
operator|->
name|flags
operator||=
name|XFR_BAD_SUBDISK
expr_stmt|;
comment|/* note that it's dead */
comment|/* 		 * we can't read or write from/to it, 		 * but we don't need to malloc 		 */
name|rqe
operator|->
name|flags
operator|&=
operator|~
operator|(
name|XFR_MALLOCED
operator||
name|XFR_NORMAL_READ
operator||
name|XFR_NORMAL_WRITE
operator|)
expr_stmt|;
block|}
name|setrqebounds
argument_list|(
name|rqe
argument_list|,
operator|&
name|m
argument_list|)
expr_stmt|;
comment|/* set up the bounds of the transfer */
name|rqe
operator|->
name|useroffset
operator|=
name|m
operator|.
name|useroffset
expr_stmt|;
comment|/* offset in user buffer */
name|rqe
operator|->
name|sdno
operator|=
name|sd
operator|->
name|sdno
expr_stmt|;
comment|/* subdisk number */
name|rqe
operator|->
name|driveno
operator|=
name|sd
operator|->
name|driveno
expr_stmt|;
if|if
condition|(
name|build_rq_buffer
argument_list|(
name|rqe
argument_list|,
name|plex
argument_list|)
condition|)
comment|/* build the buffer */
return|return
name|REQUEST_ENOMEM
return|;
comment|/* can't do it */
if|if
condition|(
operator|(
name|m
operator|.
name|flags
operator|&
name|XFR_PARITYOP
operator|)
comment|/* parity operation, */
operator|&&
operator|(
operator|(
name|m
operator|.
name|flags
operator|&
name|XFR_BAD_SUBDISK
operator|)
operator|==
literal|0
operator|)
condition|)
comment|/* and not the bad subdisk, */
name|rqe
operator|->
name|b
operator|.
name|b_flags
operator||=
name|B_READ
expr_stmt|;
comment|/* we must read first */
comment|/* Now update pointers for the next block */
operator|*
name|diskaddr
operator|+=
name|m
operator|.
name|datalen
expr_stmt|;
comment|/* skip past what we've done */
name|m
operator|.
name|stripesectors
operator|-=
name|m
operator|.
name|datalen
expr_stmt|;
comment|/* deduct from what's left */
name|m
operator|.
name|useroffset
operator|+=
name|m
operator|.
name|datalen
expr_stmt|;
comment|/* and move on in the user buffer */
name|m
operator|.
name|datalen
operator|=
name|min
argument_list|(
name|m
operator|.
name|stripesectors
argument_list|,
name|plex
operator|->
name|stripesize
argument_list|)
expr_stmt|;
comment|/* and recalculate */
name|m
operator|.
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* start at the beginning of next block */
block|}
comment|/* 	 * 3: REMAINING BLOCKS FOR RECOVERY 	 * Finally, if we have a recovery operation, build 	 * up transfers for the other subdisks.  Follow the 	 * subdisks around until we get to where we started. 	 * These requests use only the group parameters. 	 */
if|if
condition|(
operator|(
name|rqno
operator|<
name|m
operator|.
name|rqcount
operator|)
comment|/* haven't done them all already */
operator|&&
operator|(
name|m
operator|.
name|flags
operator|&
operator|(
name|XFR_RECOVERY_READ
operator||
name|XFR_DEGRADED_WRITE
operator|)
operator|)
condition|)
block|{
for|for
control|(
init|;
name|rqno
operator|<
name|m
operator|.
name|rqcount
condition|;
name|rqno
operator|++
operator|,
name|mysdno
operator|++
control|)
block|{
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
if|if
condition|(
name|mysdno
operator|==
name|plex
operator|->
name|subdisks
condition|)
comment|/* got to the end, */
name|mysdno
operator|=
literal|0
expr_stmt|;
comment|/* wrap around */
if|if
condition|(
name|mysdno
operator|==
name|m
operator|.
name|psdno
condition|)
comment|/* parity, */
name|mysdno
operator|++
expr_stmt|;
comment|/* we've given already */
name|rqe
operator|=
operator|&
name|rqg
operator|->
name|rqe
index|[
name|rqno
index|]
expr_stmt|;
comment|/* point to element */
name|sd
operator|=
operator|&
name|SD
index|[
name|plex
operator|->
name|sdnos
index|[
name|mysdno
index|]
index|]
expr_stmt|;
comment|/* the subdisk in question */
name|rqe
operator|->
name|rqg
operator|=
name|rqg
expr_stmt|;
comment|/* point to group */
name|rqe
operator|->
name|sdoffset
operator|=
name|m
operator|.
name|sdbase
operator|+
name|m
operator|.
name|groupoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* for tidiness' sake */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* group starts at the beginining */
name|rqe
operator|->
name|datalen
operator|=
literal|0
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
name|m
operator|.
name|grouplen
expr_stmt|;
name|rqe
operator|->
name|buflen
operator|=
name|m
operator|.
name|grouplen
expr_stmt|;
name|rqe
operator|->
name|flags
operator|=
operator|(
name|m
operator|.
name|flags
operator||
name|XFR_MALLOCED
operator|)
comment|/* transfer flags without data op stuf */
operator|&
operator|~
name|XFR_DATAOP
expr_stmt|;
name|rqe
operator|->
name|sdno
operator|=
name|sd
operator|->
name|sdno
expr_stmt|;
comment|/* subdisk number */
name|rqe
operator|->
name|driveno
operator|=
name|sd
operator|->
name|driveno
expr_stmt|;
if|if
condition|(
name|build_rq_buffer
argument_list|(
name|rqe
argument_list|,
name|plex
argument_list|)
condition|)
comment|/* build the buffer */
return|return
name|REQUEST_ENOMEM
return|;
comment|/* can't do it */
name|rqe
operator|->
name|b
operator|.
name|b_flags
operator||=
name|B_READ
expr_stmt|;
comment|/* we must read first */
block|}
block|}
comment|/* 	 * We need to lock the address range before 	 * doing anything.  We don't have to be 	 * performing a recovery operation: somebody 	 * else could be doing so, and the results could 	 * influence us.  Note the fact here, we'll perform 	 * the lock in launch_requests. 	 */
name|rqg
operator|->
name|lockbase
operator|=
name|m
operator|.
name|stripebase
expr_stmt|;
if|if
condition|(
operator|*
name|diskaddr
operator|<
name|diskend
condition|)
comment|/* didn't finish the request on this stripe */
name|plex
operator|->
name|multistripe
operator|++
expr_stmt|;
comment|/* count another one */
block|}
return|return
name|REQUEST_OK
return|;
block|}
end_function

begin_comment
comment|/*  * Helper function for rqe5: adjust the bounds of  * the transfers to minimize the buffer  * allocation.  *  * Each request can handle two of three different  * data ranges:  *  * 1.  The range described by the parameters  *     dataoffset and datalen, for normal read or  *     parityless write.  * 2.  The range described by the parameters  *     groupoffset and grouplen, for recovery read  *     and degraded write.  * 3.  For normal write, the range depends on the  *     kind of block.  For data blocks, the range  *     is defined by dataoffset and datalen.  For  *     parity blocks, it is defined by writeoffset  *     and writelen.  *  * In order not to allocate more memory than  * necessary, this function adjusts the bounds  * parameter for each request to cover just the  * minimum necessary for the function it performs.  * This will normally vary from one request to the  * next.  *  * Things are slightly different for the parity  * block.  In this case, the bounds defined by  * mp->writeoffset and mp->writelen also play a  * rôle.  Select this case by setting the  * parameter forparity != 0  */
end_comment

begin_function
name|void
name|setrqebounds
parameter_list|(
name|struct
name|rqelement
modifier|*
name|rqe
parameter_list|,
name|struct
name|metrics
modifier|*
name|mp
parameter_list|)
block|{
comment|/* parity block of a normal write */
if|if
condition|(
operator|(
name|rqe
operator|->
name|flags
operator|&
operator|(
name|XFR_NORMAL_WRITE
operator||
name|XFR_PARITY_BLOCK
operator|)
operator|)
operator|==
operator|(
name|XFR_NORMAL_WRITE
operator||
name|XFR_PARITY_BLOCK
operator|)
condition|)
block|{
comment|/* case 3 */
if|if
condition|(
name|rqe
operator|->
name|flags
operator|&
name|XFR_DEGRADED_WRITE
condition|)
block|{
comment|/* also degraded write */
comment|/* 	     * With a combined normal and degraded write, we 	     * will zero out the area of the degraded write 	     * in the second phase, so we don't need to read 	     * it in.  Unfortunately, we need a way to tell 	     * build_request_buffer the size of the buffer, 	     * and currently that's the length of the read. 	     * As a result, we read everything, even the stuff 	     * that we're going to nuke. 	     * FIXME XXX 	     */
if|if
condition|(
name|mp
operator|->
name|groupoffset
operator|<
name|mp
operator|->
name|writeoffset
condition|)
block|{
comment|/* group operation starts lower */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|groupoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
name|mp
operator|->
name|writeoffset
operator|-
name|mp
operator|->
name|groupoffset
expr_stmt|;
comment|/* data starts here */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* and the group at the beginning */
block|}
else|else
block|{
comment|/* individual data starts first */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|writeoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* individual data starts at the beginning */
name|rqe
operator|->
name|groupoffset
operator|=
name|mp
operator|->
name|groupoffset
operator|-
name|mp
operator|->
name|writeoffset
expr_stmt|;
comment|/* group starts here */
block|}
name|rqe
operator|->
name|datalen
operator|=
name|mp
operator|->
name|writelen
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
name|mp
operator|->
name|grouplen
expr_stmt|;
block|}
else|else
block|{
comment|/* just normal write (case 3) */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|writeoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* degradation starts at the beginning */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* for tidiness' sake */
name|rqe
operator|->
name|datalen
operator|=
name|mp
operator|->
name|writelen
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|rqe
operator|->
name|flags
operator|&
name|XFR_DATAOP
condition|)
block|{
comment|/* data operation (case 1 or 3) */
if|if
condition|(
name|rqe
operator|->
name|flags
operator|&
name|XFR_GROUPOP
condition|)
block|{
comment|/* also a group operation (case 2) */
if|if
condition|(
name|mp
operator|->
name|groupoffset
operator|<
name|mp
operator|->
name|dataoffset
condition|)
block|{
comment|/* group operation starts lower */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|groupoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
name|mp
operator|->
name|dataoffset
operator|-
name|mp
operator|->
name|groupoffset
expr_stmt|;
comment|/* data starts here */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* and the group at the beginning */
block|}
else|else
block|{
comment|/* individual data starts first */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|dataoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* individual data starts at the beginning */
name|rqe
operator|->
name|groupoffset
operator|=
name|mp
operator|->
name|groupoffset
operator|-
name|mp
operator|->
name|dataoffset
expr_stmt|;
comment|/* group starts here */
block|}
name|rqe
operator|->
name|datalen
operator|=
name|mp
operator|->
name|datalen
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
name|mp
operator|->
name|grouplen
expr_stmt|;
block|}
else|else
block|{
comment|/* just data operation (case 1) */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|dataoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* degradation starts at the beginning */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* for tidiness' sake */
name|rqe
operator|->
name|datalen
operator|=
name|mp
operator|->
name|datalen
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* just group operations (case 2) */
name|rqe
operator|->
name|sdoffset
operator|=
name|mp
operator|->
name|sdbase
operator|+
name|mp
operator|->
name|groupoffset
expr_stmt|;
comment|/* start of transfer */
name|rqe
operator|->
name|dataoffset
operator|=
literal|0
expr_stmt|;
comment|/* for tidiness' sake */
name|rqe
operator|->
name|groupoffset
operator|=
literal|0
expr_stmt|;
comment|/* group starts at the beginining */
name|rqe
operator|->
name|datalen
operator|=
literal|0
expr_stmt|;
name|rqe
operator|->
name|grouplen
operator|=
name|mp
operator|->
name|grouplen
expr_stmt|;
block|}
name|rqe
operator|->
name|buflen
operator|=
name|max
argument_list|(
name|rqe
operator|->
name|dataoffset
operator|+
name|rqe
operator|->
name|datalen
argument_list|,
comment|/* total buffer length */
name|rqe
operator|->
name|groupoffset
operator|+
name|rqe
operator|->
name|grouplen
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Local Variables: */
end_comment

begin_comment
comment|/* fill-column: 50 */
end_comment

begin_comment
comment|/* End: */
end_comment

end_unit

