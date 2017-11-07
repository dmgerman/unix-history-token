begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"part_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"string_ext.h"
end_include

begin_include
include|#
directive|include
file|"mem_ext.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"xx_ext.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PAD_ALIGNMENT
parameter_list|(
name|align
parameter_list|,
name|x
parameter_list|)
value|(((x)%(align)) ? ((align)-((x)%(align))) : 0)
end_define

begin_define
define|#
directive|define
name|ALIGN_BLOCK
parameter_list|(
name|p_Block
parameter_list|,
name|prefixSize
parameter_list|,
name|alignment
parameter_list|)
define|\
value|do {                                                            \         p_Block += (prefixSize);                                    \         p_Block += PAD_ALIGNMENT((alignment), (uintptr_t)(p_Block)); \     } while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_CALLER_ADDR
define|\
value|__asm__ ("mflr  %0" : "=r" (callerAddr))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
end_elif

begin_comment
comment|/* NOTE: This implementation is only valid for CodeWarrior for PowerPC */
end_comment

begin_define
define|#
directive|define
name|GET_CALLER_ADDR
define|\
value|__asm__("add  %0, 0, %0" : : "r" (callerAddr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
unit|static __inline__ void * MemGet(t_MemorySegment *p_Mem) {     uint8_t *p_Block;
comment|/* check if there is an available block */
end_comment

begin_comment
unit|if (p_Mem->current == p_Mem->num)     {         p_Mem->getFailures++;         return NULL;     }
comment|/* get the block */
end_comment

begin_ifdef
unit|p_Block = p_Mem->p_BlocksStack[p_Mem->current];
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_endif
unit|p_Mem->p_BlocksStack[p_Mem->current] = NULL;
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/* advance current index */
end_comment

begin_comment
unit|p_Mem->current++;      return (void *)p_Block; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|static __inline__ t_Error MemPut(t_MemorySegment *p_Mem, void *p_Block) {
comment|/* check if blocks stack is full */
end_comment

begin_comment
unit|if (p_Mem->current> 0)     {
comment|/* decrease current index */
end_comment

begin_comment
unit|p_Mem->current--;
comment|/* put the block */
end_comment

begin_ifdef
unit|p_Mem->p_BlocksStack[p_Mem->current] = (uint8_t *)p_Block;         return E_OK;     }      RETURN_ERROR(MAJOR, E_FULL, NO_MSG); }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
unit|static t_Error InitMemDebugDatabase(t_MemorySegment *p_Mem) {     p_Mem->p_MemDbg = (void *)XX_Malloc(sizeof(t_MemDbg) * p_Mem->num);     if (!p_Mem->p_MemDbg)     {         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory debug object"));     }      memset(p_Mem->p_MemDbg, ILLEGAL_BASE, sizeof(t_MemDbg) * p_Mem->num);      return E_OK; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|static t_Error DebugMemGet(t_Handle h_Mem, void *p_Block, uintptr_t ownerAddress) {     t_MemorySegment *p_Mem = (t_MemorySegment *)h_Mem;     t_MemDbg        *p_MemDbg = (t_MemDbg *)p_Mem->p_MemDbg;     uint32_t        blockIndex;      ASSERT_COND(ownerAddress != ILLEGAL_BASE);
comment|/* Find block num */
end_comment

begin_comment
unit|if (p_Mem->consecutiveMem)     {         blockIndex =             (((uint8_t *)p_Block - (p_Mem->p_Bases[0] + p_Mem->blockOffset)) / p_Mem->blockSize);     }     else     {         blockIndex = *(uint32_t *)((uint8_t *)p_Block - 4);     }      ASSERT_COND(blockIndex< p_Mem->num);     ASSERT_COND(p_MemDbg[blockIndex].ownerAddress == ILLEGAL_BASE);      p_MemDbg[blockIndex].ownerAddress = ownerAddress;      return E_OK; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|static t_Error DebugMemPut(t_Handle h_Mem, void *p_Block) {     t_MemorySegment *p_Mem = (t_MemorySegment *)h_Mem;     t_MemDbg        *p_MemDbg = (t_MemDbg *)p_Mem->p_MemDbg;     uint32_t        blockIndex;     uint8_t         *p_Temp;
comment|/* Find block num */
end_comment

begin_comment
unit|if (p_Mem->consecutiveMem)     {         blockIndex =             (((uint8_t *)p_Block - (p_Mem->p_Bases[0] + p_Mem->blockOffset)) / p_Mem->blockSize);          if (blockIndex>= p_Mem->num)         {             RETURN_ERROR(MAJOR, E_INVALID_ADDRESS,                          ("Freed address (0x%08x) does not belong to this pool", p_Block));         }     }     else     {         blockIndex = *(uint32_t *)((uint8_t *)p_Block - 4);          if (blockIndex>= p_Mem->num)         {             RETURN_ERROR(MAJOR, E_INVALID_ADDRESS,                          ("Freed address (0x%08x) does not belong to this pool", p_Block));         }
comment|/* Verify that the block matches the corresponding base */
end_comment

begin_endif
unit|p_Temp = p_Mem->p_Bases[blockIndex];          ALIGN_BLOCK(p_Temp, p_Mem->prefixSize, p_Mem->alignment);          if (p_Temp == p_Mem->p_Bases[blockIndex])             p_Temp += p_Mem->alignment;          if (p_Temp != p_Block)         {             RETURN_ERROR(MAJOR, E_INVALID_ADDRESS,                          ("Freed address (0x%08x) does not belong to this pool", p_Block));         }     }      if (p_MemDbg[blockIndex].ownerAddress == ILLEGAL_BASE)     {         RETURN_ERROR(MAJOR, E_ALREADY_FREE,                      ("Attempt to free unallocated address (0x%08x)", p_Block));     }      p_MemDbg[blockIndex].ownerAddress = (uintptr_t)ILLEGAL_BASE;      return E_OK; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
unit|uint32_t MEM_ComputePartitionSize(uint32_t num,                                   uint16_t dataSize,                                   uint16_t prefixSize,                                   uint16_t postfixSize,                                   uint16_t alignment) {     uint32_t  blockSize = 0, pad1 = 0, pad2 = 0;
comment|/* Make sure that the alignment is at least 4 */
end_comment

begin_comment
unit|if (alignment< 4)     {         alignment = 4;     }      pad1 = (uint32_t)PAD_ALIGNMENT(4, prefixSize);
comment|/* Block size not including 2nd padding */
end_comment

begin_comment
unit|blockSize = pad1 + prefixSize + dataSize + postfixSize;     pad2 = PAD_ALIGNMENT(alignment, blockSize);
comment|/* Block size including 2nd padding */
end_comment

begin_comment
unit|blockSize += pad2;      return ((num * blockSize) + alignment); }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|t_Error MEM_Init(char       name[],                  t_Handle   *p_Handle,                  uint32_t   num,                  uint16_t   dataSize,                  uint16_t   prefixSize,                  uint16_t   postfixSize,                  uint16_t   alignment) {     uint8_t     *p_Memory;     uint32_t    allocSize;     t_Error     errCode;      allocSize = MEM_ComputePartitionSize(num,                                          dataSize,                                          prefixSize,                                          postfixSize,                                          alignment);      p_Memory = (uint8_t *)XX_Malloc(allocSize);     if (!p_Memory)     {         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment"));     }      errCode = MEM_InitByAddress(name,                                 p_Handle,                                 num,                                 dataSize,                                 prefixSize,                                 postfixSize,                                 alignment,                                 p_Memory);     if (errCode != E_OK)     {         RETURN_ERROR(MAJOR, errCode, NO_MSG);     }      ((t_MemorySegment *)(*p_Handle))->allocOwner = e_MEM_ALLOC_OWNER_LOCAL;      return E_OK; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|t_Error MEM_InitByAddress(char      name[],                           t_Handle  *p_Handle,                           uint32_t  num,                           uint16_t  dataSize,                           uint16_t  prefixSize,                           uint16_t  postfixSize,                           uint16_t  alignment,                           uint8_t   *p_Memory) {     t_MemorySegment *p_Mem;     uint32_t        i, blockSize;     uint16_t        alignPad, endPad;     uint8_t         *p_Blocks;
comment|/* prepare in case of error */
end_comment

begin_comment
unit|*p_Handle = NULL;      if (!p_Memory)     {         RETURN_ERROR(MAJOR, E_NULL_POINTER, ("Memory blocks"));     }      p_Blocks = p_Memory;
comment|/* make sure that the alignment is at least 4 and power of 2 */
end_comment

begin_comment
unit|if (alignment< 4)     {         alignment = 4;     }     else if (!POWER_OF_2(alignment))     {         RETURN_ERROR(MAJOR, E_INVALID_VALUE, ("Alignment (should be power of 2)"));     }
comment|/* first allocate the segment descriptor */
end_comment

begin_comment
unit|p_Mem = (t_MemorySegment *)XX_Malloc(sizeof(t_MemorySegment));     if (!p_Mem)     {         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment structure"));     }
comment|/* allocate the blocks stack */
end_comment

begin_comment
unit|p_Mem->p_BlocksStack = (uint8_t **)XX_Malloc(num * sizeof(uint8_t*));     if (!p_Mem->p_BlocksStack)     {         XX_Free(p_Mem);         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment block pointers stack"));     }
comment|/* allocate the blocks bases array */
end_comment

begin_comment
unit|p_Mem->p_Bases = (uint8_t **)XX_Malloc(sizeof(uint8_t*));     if (!p_Mem->p_Bases)     {         MEM_Free(p_Mem);         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment base pointers array"));     }     memset(p_Mem->p_Bases, 0, sizeof(uint8_t*));
comment|/* store info about this segment */
end_comment

begin_comment
unit|p_Mem->num = num;     p_Mem->current = 0;     p_Mem->dataSize = dataSize;     p_Mem->p_Bases[0] = p_Blocks;     p_Mem->getFailures = 0;     p_Mem->allocOwner = e_MEM_ALLOC_OWNER_EXTERNAL;     p_Mem->consecutiveMem = TRUE;     p_Mem->prefixSize = prefixSize;     p_Mem->postfixSize = postfixSize;     p_Mem->alignment = alignment;
comment|/* store name */
end_comment

begin_comment
unit|strncpy(p_Mem->name, name, MEM_MAX_NAME_LENGTH-1);      p_Mem->h_Spinlock = XX_InitSpinlock();     if (!p_Mem->h_Spinlock)     {         MEM_Free(p_Mem);         RETURN_ERROR(MAJOR, E_INVALID_STATE, ("Can't create spinlock!"));     }      alignPad = (uint16_t)PAD_ALIGNMENT(4, prefixSize);
comment|/* Make sure the entire size is a multiple of alignment */
end_comment

begin_comment
unit|endPad = (uint16_t)PAD_ALIGNMENT(alignment, (alignPad + prefixSize + dataSize + postfixSize));
comment|/* The following manipulation places the data of block[0] in an aligned address,        since block size is aligned the following block datas will all be aligned */
end_comment

begin_comment
unit|ALIGN_BLOCK(p_Blocks, prefixSize, alignment);      blockSize = (uint32_t)(alignPad + prefixSize + dataSize + postfixSize + endPad);
comment|/* initialize the blocks */
end_comment

begin_comment
unit|for (i=0; i< num; i++)     {         p_Mem->p_BlocksStack[i] = p_Blocks;         p_Blocks += blockSize;     }
comment|/* return handle to caller */
end_comment

begin_ifdef
unit|*p_Handle = (t_Handle)p_Mem;
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|{         t_Error errCode = InitMemDebugDatabase(p_Mem);          if (errCode != E_OK)             RETURN_ERROR(MAJOR, errCode, NO_MSG);          p_Mem->blockOffset = (uint32_t)(p_Mem->p_BlocksStack[0] - p_Mem->p_Bases[0]);         p_Mem->blockSize = blockSize;     }
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|return E_OK; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|t_Error MEM_InitSmart(char      name[],                       t_Handle  *p_Handle,                       uint32_t  num,                       uint16_t  dataSize,                       uint16_t  prefixSize,                       uint16_t  postfixSize,                       uint16_t  alignment,                       uint8_t   memPartitionId,                       bool      consecutiveMem) {     t_MemorySegment *p_Mem;     uint32_t        i, blockSize;     uint16_t        alignPad, endPad;
comment|/* prepare in case of error */
end_comment

begin_comment
unit|*p_Handle = NULL;
comment|/* make sure that size is always a multiple of 4 */
end_comment

begin_comment
unit|if (dataSize& 3)     {         dataSize&= ~3;         dataSize += 4;     }
comment|/* make sure that the alignment is at least 4 and power of 2 */
end_comment

begin_comment
unit|if (alignment< 4)     {         alignment = 4;     }     else if (!POWER_OF_2(alignment))     {         RETURN_ERROR(MAJOR, E_INVALID_VALUE, ("Alignment (should be power of 2)"));     }
comment|/* first allocate the segment descriptor */
end_comment

begin_comment
unit|p_Mem = (t_MemorySegment *)XX_Malloc(sizeof(t_MemorySegment));     if (!p_Mem)     {         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment structure"));     }
comment|/* allocate the blocks stack */
end_comment

begin_comment
unit|p_Mem->p_BlocksStack = (uint8_t **)XX_Malloc(num * sizeof(uint8_t*));     if (!p_Mem->p_BlocksStack)     {         MEM_Free(p_Mem);         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment block pointers stack"));     }
comment|/* allocate the blocks bases array */
end_comment

begin_comment
unit|p_Mem->p_Bases = (uint8_t **)XX_Malloc((consecutiveMem ? 1 : num) * sizeof(uint8_t*));     if (!p_Mem->p_Bases)     {         MEM_Free(p_Mem);         RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment base pointers array"));     }     memset(p_Mem->p_Bases, 0, (consecutiveMem ? 1 : num) * sizeof(uint8_t*));
comment|/* store info about this segment */
end_comment

begin_comment
unit|p_Mem->num = num;     p_Mem->current = 0;     p_Mem->dataSize = dataSize;     p_Mem->getFailures = 0;     p_Mem->allocOwner = e_MEM_ALLOC_OWNER_LOCAL_SMART;     p_Mem->consecutiveMem = consecutiveMem;     p_Mem->prefixSize = prefixSize;     p_Mem->postfixSize = postfixSize;     p_Mem->alignment = alignment;      p_Mem->h_Spinlock = XX_InitSpinlock();     if (!p_Mem->h_Spinlock)     {         MEM_Free(p_Mem);         RETURN_ERROR(MAJOR, E_INVALID_STATE, ("Can't create spinlock!"));     }      alignPad = (uint16_t)PAD_ALIGNMENT(4, prefixSize);
comment|/* Make sure the entire size is a multiple of alignment */
end_comment

begin_comment
unit|endPad = (uint16_t)PAD_ALIGNMENT(alignment, alignPad + prefixSize + dataSize + postfixSize);
comment|/* Calculate blockSize */
end_comment

begin_comment
unit|blockSize = (uint32_t)(alignPad + prefixSize + dataSize + postfixSize + endPad);
comment|/* Now allocate the blocks */
end_comment

begin_comment
unit|if (p_Mem->consecutiveMem)     {
comment|/* |alignment - 1| bytes at most will be discarded in the beginning of the            received segment for alignment reasons, therefore the allocation is of:            (alignment + (num * block size)). */
end_comment

begin_comment
unit|uint8_t *p_Blocks = (uint8_t *)             XX_MallocSmart((uint32_t)((num * blockSize) + alignment), memPartitionId, 1);         if (!p_Blocks)         {             MEM_Free(p_Mem);             RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment blocks"));         }
comment|/* Store the memory segment address */
end_comment

begin_comment
unit|p_Mem->p_Bases[0] = p_Blocks;
comment|/* The following manipulation places the data of block[0] in an aligned address,            since block size is aligned the following block datas will all be aligned.*/
end_comment

begin_comment
unit|ALIGN_BLOCK(p_Blocks, prefixSize, alignment);
comment|/* initialize the blocks */
end_comment

begin_ifdef
unit|for (i = 0; i< num; i++)         {             p_Mem->p_BlocksStack[i] = p_Blocks;             p_Blocks += blockSize;         }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|p_Mem->blockOffset = (uint32_t)(p_Mem->p_BlocksStack[0] - p_Mem->p_Bases[0]);         p_Mem->blockSize = blockSize;
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|}     else     {
comment|/* |alignment - 1| bytes at most will be discarded in the beginning of the            received segment for alignment reasons, therefore the allocation is of:            (alignment + block size). */
end_comment

begin_comment
unit|for (i = 0; i< num; i++)         {             uint8_t *p_Block = (uint8_t *)                 XX_MallocSmart((uint32_t)(blockSize + alignment), memPartitionId, 1);             if (!p_Block)             {                 MEM_Free(p_Mem);                 RETURN_ERROR(MAJOR, E_NO_MEMORY, ("Memory segment blocks"));             }
comment|/* Store the memory segment address */
end_comment

begin_comment
unit|p_Mem->p_Bases[i] = p_Block;
comment|/* The following places the data of each block in an aligned address */
end_comment

begin_ifdef
unit|ALIGN_BLOCK(p_Block, prefixSize, alignment);
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_comment
comment|/* Need 4 bytes before the meaningful bytes to store the block index.                We know we have them because alignment is at least 4 bytes. */
end_comment

begin_endif
unit|if (p_Block == p_Mem->p_Bases[i])                 p_Block += alignment;              *(uint32_t *)(p_Block - 4) = i;
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|p_Mem->p_BlocksStack[i] = p_Block;         }     }
comment|/* store name */
end_comment

begin_comment
unit|strncpy(p_Mem->name, name, MEM_MAX_NAME_LENGTH-1);
comment|/* return handle to caller */
end_comment

begin_ifdef
unit|*p_Handle = (t_Handle)p_Mem;
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|{         t_Error errCode = InitMemDebugDatabase(p_Mem);          if (errCode != E_OK)             RETURN_ERROR(MAJOR, errCode, NO_MSG);     }
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|return E_OK; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|void MEM_Free(t_Handle h_Mem) {     t_MemorySegment *p_Mem = (t_MemorySegment*)h_Mem;     uint32_t        num, i;
comment|/* Check MEM leaks */
end_comment

begin_ifdef
unit|MEM_CheckLeaks(h_Mem);      if (p_Mem)     {         num = p_Mem->consecutiveMem ? 1 : p_Mem->num;          if (p_Mem->allocOwner == e_MEM_ALLOC_OWNER_LOCAL_SMART)         {             for (i=0; i< num; i++)             {                 if (p_Mem->p_Bases[i])                 {                     XX_FreeSmart(p_Mem->p_Bases[i]);                 }             }         }         else if (p_Mem->allocOwner == e_MEM_ALLOC_OWNER_LOCAL)         {             for (i=0; i< num; i++)             {                 if (p_Mem->p_Bases[i])                 {                     XX_Free(p_Mem->p_Bases[i]);                 }             }         }          if (p_Mem->h_Spinlock)             XX_FreeSpinlock(p_Mem->h_Spinlock);          if (p_Mem->p_Bases)             XX_Free(p_Mem->p_Bases);          if (p_Mem->p_BlocksStack)             XX_Free(p_Mem->p_BlocksStack);
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|if (p_Mem->p_MemDbg)             XX_Free(p_Mem->p_MemDbg);
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|XX_Free(p_Mem);     } }
comment|/*****************************************************************************/
end_comment

begin_ifdef
unit|void * MEM_Get(t_Handle h_Mem) {     t_MemorySegment *p_Mem = (t_MemorySegment *)h_Mem;     uint8_t         *p_Block;     uint32_t        intFlags;
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|uintptr_t       callerAddr = 0;      GET_CALLER_ADDR;
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|ASSERT_COND(h_Mem);      intFlags = XX_LockIntrSpinlock(p_Mem->h_Spinlock);
comment|/* check if there is an available block */
end_comment

begin_ifdef
unit|if ((p_Block = (uint8_t *)MemGet(p_Mem)) == NULL)     {         XX_UnlockIntrSpinlock(p_Mem->h_Spinlock, intFlags);         return NULL;     }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|DebugMemGet(p_Mem, p_Block, callerAddr);
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|XX_UnlockIntrSpinlock(p_Mem->h_Spinlock, intFlags);      return (void *)p_Block; }
comment|/*****************************************************************************/
end_comment

begin_ifdef
unit|uint16_t MEM_GetN(t_Handle h_Mem, uint32_t num, void *array[]) {     t_MemorySegment     *p_Mem = (t_MemorySegment *)h_Mem;     uint32_t            availableBlocks;     register uint32_t   i;     uint32_t            intFlags;
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|uintptr_t           callerAddr = 0;      GET_CALLER_ADDR;
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|ASSERT_COND(h_Mem);      intFlags = XX_LockIntrSpinlock(p_Mem->h_Spinlock);
comment|/* check how many blocks are available */
end_comment

begin_comment
unit|availableBlocks = (uint32_t)(p_Mem->num - p_Mem->current);     if (num> availableBlocks)     {         num = availableBlocks;     }      for (i=0; i< num; i++)     {
comment|/* get pointer to block */
end_comment

begin_ifdef
unit|if ((array[i] = MemGet(p_Mem)) == NULL)         {             break;         }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|DebugMemGet(p_Mem, array[i], callerAddr);
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_comment
unit|}     XX_UnlockIntrSpinlock(p_Mem->h_Spinlock, intFlags);      return (uint16_t)i; }
comment|/*****************************************************************************/
end_comment

begin_comment
unit|t_Error MEM_Put(t_Handle h_Mem, void *p_Block) {     t_MemorySegment *p_Mem = (t_MemorySegment *)h_Mem;     t_Error         rc;     uint32_t        intFlags;      ASSERT_COND(h_Mem);      intFlags = XX_LockIntrSpinlock(p_Mem->h_Spinlock);
comment|/* check if blocks stack is full */
end_comment

begin_ifdef
unit|if ((rc = MemPut(p_Mem, p_Block)) != E_OK)     {         XX_UnlockIntrSpinlock(p_Mem->h_Spinlock, intFlags);         RETURN_ERROR(MAJOR, rc, NO_MSG);     }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_endif
unit|DebugMemPut(p_Mem, p_Block);
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_ifdef
unit|XX_UnlockIntrSpinlock(p_Mem->h_Spinlock, intFlags);      return E_OK; }
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
unit|void MEM_CheckLeaks(t_Handle h_Mem) {     t_MemorySegment *p_Mem = (t_MemorySegment *)h_Mem;     t_MemDbg        *p_MemDbg = (t_MemDbg *)p_Mem->p_MemDbg;     uint8_t         *p_Block;     int             i;      ASSERT_COND(h_Mem);      if (p_Mem->consecutiveMem)     {         for (i=0; i< p_Mem->num; i++)         {             if (p_MemDbg[i].ownerAddress != ILLEGAL_BASE)             {
comment|/* Find the block address */
end_comment

begin_comment
unit|p_Block = ((p_Mem->p_Bases[0] + p_Mem->blockOffset) +                            (i * p_Mem->blockSize));                  XX_Print("MEM leak: 0x%08x, Caller address: 0x%08x\n",                          p_Block, p_MemDbg[i].ownerAddress);             }         }     }     else     {         for (i=0; i< p_Mem->num; i++)         {             if (p_MemDbg[i].ownerAddress != ILLEGAL_BASE)             {
comment|/* Find the block address */
end_comment

begin_endif
unit|p_Block = p_Mem->p_Bases[i];                  ALIGN_BLOCK(p_Block, p_Mem->prefixSize, p_Mem->alignment);                  if (p_Block == p_Mem->p_Bases[i])                     p_Block += p_Mem->alignment;                  XX_Print("MEM leak: 0x%08x, Caller address: 0x%08x\n",                          p_Block, p_MemDbg[i].ownerAddress);             }         }     } }
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM_LEAKS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

