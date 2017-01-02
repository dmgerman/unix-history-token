begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_allocator_size_class_map.h --------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part of the Sanitizer Allocator.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_ALLOCATOR_H
end_ifndef

begin_error
error|#
directive|error
error|This file must be included inside sanitizer_allocator.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SizeClassMap maps allocation sizes into size classes and back.
end_comment

begin_comment
comment|// Class 0 always corresponds to size 0.
end_comment

begin_comment
comment|// The other sizes are controlled by the template parameters:
end_comment

begin_comment
comment|//   kMinSizeLog: defines the class 1    as 2^kMinSizeLog.
end_comment

begin_comment
comment|//   kMaxSizeLog: defines the last class as 2^kMaxSizeLog.
end_comment

begin_comment
comment|//   kMidSizeLog: the classes starting from 1 increase with step
end_comment

begin_comment
comment|//                2^kMinSizeLog until 2^kMidSizeLog.
end_comment

begin_comment
comment|//   kNumBits: the number of non-zero bits in sizes after 2^kMidSizeLog.
end_comment

begin_comment
comment|//             E.g. with kNumBits==3 all size classes after 2^kMidSizeLog
end_comment

begin_comment
comment|//             look like 0b1xx0..0, where x is either 0 or 1.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Example: kNumBits=3, kMidSizeLog=4, kMidSizeLog=8, kMaxSizeLog=17:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Classes 1 - 16 correspond to sizes 16 to 256 (size = class_id * 16).
end_comment

begin_comment
comment|// Next 4 classes: 256 + i * 64  (i = 1 to 4).
end_comment

begin_comment
comment|// Next 4 classes: 512 + i * 128 (i = 1 to 4).
end_comment

begin_comment
comment|// ...
end_comment

begin_comment
comment|// Next 4 classes: 2^k + i * 2^(k-2) (i = 1 to 4).
end_comment

begin_comment
comment|// Last class corresponds to kMaxSize = 1<< kMaxSizeLog.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This structure of the size class map gives us:
end_comment

begin_comment
comment|//   - Efficient table-free class-to-size and size-to-class functions.
end_comment

begin_comment
comment|//   - Difference between two consequent size classes is between 14% and 25%
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class also gives a hint to a thread-caching allocator about the amount
end_comment

begin_comment
comment|// of chunks that need to be cached per-thread:
end_comment

begin_comment
comment|//  - kMaxNumCachedHint is a hint for maximal number of chunks per size class.
end_comment

begin_comment
comment|//    The actual number is computed in TransferBatch.
end_comment

begin_comment
comment|//  - (1<< kMaxBytesCachedLog) is the maximal number of bytes per size class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Part of output of SizeClassMap::Print():
end_comment

begin_comment
comment|// c00 => s: 0 diff: +0 00% l 0 cached: 0 0; id 0
end_comment

begin_comment
comment|// c01 => s: 16 diff: +16 00% l 4 cached: 256 4096; id 1
end_comment

begin_comment
comment|// c02 => s: 32 diff: +16 100% l 5 cached: 256 8192; id 2
end_comment

begin_comment
comment|// c03 => s: 48 diff: +16 50% l 5 cached: 256 12288; id 3
end_comment

begin_comment
comment|// c04 => s: 64 diff: +16 33% l 6 cached: 256 16384; id 4
end_comment

begin_comment
comment|// c05 => s: 80 diff: +16 25% l 6 cached: 256 20480; id 5
end_comment

begin_comment
comment|// c06 => s: 96 diff: +16 20% l 6 cached: 256 24576; id 6
end_comment

begin_comment
comment|// c07 => s: 112 diff: +16 16% l 6 cached: 256 28672; id 7
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c08 => s: 128 diff: +16 14% l 7 cached: 256 32768; id 8
end_comment

begin_comment
comment|// c09 => s: 144 diff: +16 12% l 7 cached: 256 36864; id 9
end_comment

begin_comment
comment|// c10 => s: 160 diff: +16 11% l 7 cached: 256 40960; id 10
end_comment

begin_comment
comment|// c11 => s: 176 diff: +16 10% l 7 cached: 256 45056; id 11
end_comment

begin_comment
comment|// c12 => s: 192 diff: +16 09% l 7 cached: 256 49152; id 12
end_comment

begin_comment
comment|// c13 => s: 208 diff: +16 08% l 7 cached: 256 53248; id 13
end_comment

begin_comment
comment|// c14 => s: 224 diff: +16 07% l 7 cached: 256 57344; id 14
end_comment

begin_comment
comment|// c15 => s: 240 diff: +16 07% l 7 cached: 256 61440; id 15
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c16 => s: 256 diff: +16 06% l 8 cached: 256 65536; id 16
end_comment

begin_comment
comment|// c17 => s: 320 diff: +64 25% l 8 cached: 204 65280; id 17
end_comment

begin_comment
comment|// c18 => s: 384 diff: +64 20% l 8 cached: 170 65280; id 18
end_comment

begin_comment
comment|// c19 => s: 448 diff: +64 16% l 8 cached: 146 65408; id 19
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c20 => s: 512 diff: +64 14% l 9 cached: 128 65536; id 20
end_comment

begin_comment
comment|// c21 => s: 640 diff: +128 25% l 9 cached: 102 65280; id 21
end_comment

begin_comment
comment|// c22 => s: 768 diff: +128 20% l 9 cached: 85 65280; id 22
end_comment

begin_comment
comment|// c23 => s: 896 diff: +128 16% l 9 cached: 73 65408; id 23
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c24 => s: 1024 diff: +128 14% l 10 cached: 64 65536; id 24
end_comment

begin_comment
comment|// c25 => s: 1280 diff: +256 25% l 10 cached: 51 65280; id 25
end_comment

begin_comment
comment|// c26 => s: 1536 diff: +256 20% l 10 cached: 42 64512; id 26
end_comment

begin_comment
comment|// c27 => s: 1792 diff: +256 16% l 10 cached: 36 64512; id 27
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c48 => s: 65536 diff: +8192 14% l 16 cached: 1 65536; id 48
end_comment

begin_comment
comment|// c49 => s: 81920 diff: +16384 25% l 16 cached: 1 81920; id 49
end_comment

begin_comment
comment|// c50 => s: 98304 diff: +16384 20% l 16 cached: 1 98304; id 50
end_comment

begin_comment
comment|// c51 => s: 114688 diff: +16384 16% l 16 cached: 1 114688; id 51
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c52 => s: 131072 diff: +16384 14% l 17 cached: 1 131072; id 52
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Another example (kNumBits=2):
end_comment

begin_comment
comment|// c00 => s: 0 diff: +0 00% l 0 cached: 0 0; id 0
end_comment

begin_comment
comment|// c01 => s: 32 diff: +32 00% l 5 cached: 64 2048; id 1
end_comment

begin_comment
comment|// c02 => s: 64 diff: +32 100% l 6 cached: 64 4096; id 2
end_comment

begin_comment
comment|// c03 => s: 96 diff: +32 50% l 6 cached: 64 6144; id 3
end_comment

begin_comment
comment|// c04 => s: 128 diff: +32 33% l 7 cached: 64 8192; id 4
end_comment

begin_comment
comment|// c05 => s: 160 diff: +32 25% l 7 cached: 64 10240; id 5
end_comment

begin_comment
comment|// c06 => s: 192 diff: +32 20% l 7 cached: 64 12288; id 6
end_comment

begin_comment
comment|// c07 => s: 224 diff: +32 16% l 7 cached: 64 14336; id 7
end_comment

begin_comment
comment|// c08 => s: 256 diff: +32 14% l 8 cached: 64 16384; id 8
end_comment

begin_comment
comment|// c09 => s: 384 diff: +128 50% l 8 cached: 42 16128; id 9
end_comment

begin_comment
comment|// c10 => s: 512 diff: +128 33% l 9 cached: 32 16384; id 10
end_comment

begin_comment
comment|// c11 => s: 768 diff: +256 50% l 9 cached: 21 16128; id 11
end_comment

begin_comment
comment|// c12 => s: 1024 diff: +256 33% l 10 cached: 16 16384; id 12
end_comment

begin_comment
comment|// c13 => s: 1536 diff: +512 50% l 10 cached: 10 15360; id 13
end_comment

begin_comment
comment|// c14 => s: 2048 diff: +512 33% l 11 cached: 8 16384; id 14
end_comment

begin_comment
comment|// c15 => s: 3072 diff: +1024 50% l 11 cached: 5 15360; id 15
end_comment

begin_comment
comment|// c16 => s: 4096 diff: +1024 33% l 12 cached: 4 16384; id 16
end_comment

begin_comment
comment|// c17 => s: 6144 diff: +2048 50% l 12 cached: 2 12288; id 17
end_comment

begin_comment
comment|// c18 => s: 8192 diff: +2048 33% l 13 cached: 2 16384; id 18
end_comment

begin_comment
comment|// c19 => s: 12288 diff: +4096 50% l 13 cached: 1 12288; id 19
end_comment

begin_comment
comment|// c20 => s: 16384 diff: +4096 33% l 14 cached: 1 16384; id 20
end_comment

begin_comment
comment|// c21 => s: 24576 diff: +8192 50% l 14 cached: 1 24576; id 21
end_comment

begin_comment
comment|// c22 => s: 32768 diff: +8192 33% l 15 cached: 1 32768; id 22
end_comment

begin_comment
comment|// c23 => s: 49152 diff: +16384 50% l 15 cached: 1 49152; id 23
end_comment

begin_comment
comment|// c24 => s: 65536 diff: +16384 33% l 16 cached: 1 65536; id 24
end_comment

begin_comment
comment|// c25 => s: 98304 diff: +32768 50% l 16 cached: 1 98304; id 25
end_comment

begin_comment
comment|// c26 => s: 131072 diff: +32768 33% l 17 cached: 1 131072; id 26
end_comment

begin_expr_stmt
name|template
operator|<
name|uptr
name|kNumBits
operator|,
name|uptr
name|kMinSizeLog
operator|,
name|uptr
name|kMidSizeLog
operator|,
name|uptr
name|kMaxSizeLog
operator|,
name|uptr
name|kMaxNumCachedHintT
operator|,
name|uptr
name|kMaxBytesCachedLog
operator|>
name|class
name|SizeClassMap
block|{
specifier|static
specifier|const
name|uptr
name|kMinSize
operator|=
literal|1
operator|<<
name|kMinSizeLog
block|;
specifier|static
specifier|const
name|uptr
name|kMidSize
operator|=
literal|1
operator|<<
name|kMidSizeLog
block|;
specifier|static
specifier|const
name|uptr
name|kMidClass
operator|=
name|kMidSize
operator|/
name|kMinSize
block|;
specifier|static
specifier|const
name|uptr
name|S
operator|=
name|kNumBits
operator|-
literal|1
block|;
specifier|static
specifier|const
name|uptr
name|M
operator|=
operator|(
literal|1
operator|<<
name|S
operator|)
operator|-
literal|1
block|;
name|public
operator|:
comment|// kMaxNumCachedHintT is a power of two. It serves as a hint
comment|// for the size of TransferBatch, the actual size could be a bit smaller.
specifier|static
specifier|const
name|uptr
name|kMaxNumCachedHint
operator|=
name|kMaxNumCachedHintT
block|;
name|COMPILER_CHECK
argument_list|(
operator|(
name|kMaxNumCachedHint
operator|&
operator|(
name|kMaxNumCachedHint
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
argument_list|)
block|;
specifier|static
specifier|const
name|uptr
name|kMaxSize
operator|=
literal|1UL
operator|<<
name|kMaxSizeLog
block|;
specifier|static
specifier|const
name|uptr
name|kNumClasses
operator|=
name|kMidClass
operator|+
operator|(
operator|(
name|kMaxSizeLog
operator|-
name|kMidSizeLog
operator|)
operator|<<
name|S
operator|)
operator|+
literal|1
block|;
specifier|static
specifier|const
name|uptr
name|kLargestClassID
operator|=
name|kNumClasses
operator|-
literal|2
block|;
name|COMPILER_CHECK
argument_list|(
name|kNumClasses
operator|>=
literal|16
operator|&&
name|kNumClasses
operator|<=
literal|256
argument_list|)
block|;
specifier|static
specifier|const
name|uptr
name|kNumClassesRounded
operator|=
name|kNumClasses
operator|<=
literal|32
condition|?
literal|32
else|:
name|kNumClasses
operator|<=
literal|64
condition|?
literal|64
else|:
name|kNumClasses
operator|<=
literal|128
condition|?
literal|128
else|:
literal|256
block|;
specifier|static
name|uptr
name|Size
argument_list|(
argument|uptr class_id
argument_list|)
block|{
if|if
condition|(
name|class_id
operator|<=
name|kMidClass
condition|)
return|return
name|kMinSize
operator|*
name|class_id
return|;
name|class_id
operator|-=
name|kMidClass
block|;
name|uptr
name|t
operator|=
name|kMidSize
operator|<<
operator|(
name|class_id
operator|>>
name|S
operator|)
block|;
return|return
name|t
operator|+
operator|(
name|t
operator|>>
name|S
operator|)
operator|*
operator|(
name|class_id
operator|&
name|M
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|uptr
name|ClassID
parameter_list|(
name|uptr
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|<=
name|kMidSize
condition|)
return|return
operator|(
name|size
operator|+
name|kMinSize
operator|-
literal|1
operator|)
operator|>>
name|kMinSizeLog
return|;
if|if
condition|(
name|size
operator|>
name|kMaxSize
condition|)
return|return
literal|0
return|;
name|uptr
name|l
init|=
name|MostSignificantSetBitIndex
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|uptr
name|hbits
init|=
operator|(
name|size
operator|>>
operator|(
name|l
operator|-
name|S
operator|)
operator|)
operator|&
name|M
decl_stmt|;
name|uptr
name|lbits
init|=
name|size
operator|&
operator|(
operator|(
literal|1
operator|<<
operator|(
name|l
operator|-
name|S
operator|)
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
name|uptr
name|l1
init|=
name|l
operator|-
name|kMidSizeLog
decl_stmt|;
return|return
name|kMidClass
operator|+
operator|(
name|l1
operator|<<
name|S
operator|)
operator|+
name|hbits
operator|+
operator|(
name|lbits
operator|>
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|uptr
name|MaxCachedHint
parameter_list|(
name|uptr
name|class_id
parameter_list|)
block|{
if|if
condition|(
name|class_id
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|uptr
name|n
init|=
operator|(
literal|1UL
operator|<<
name|kMaxBytesCachedLog
operator|)
operator|/
name|Size
argument_list|(
name|class_id
argument_list|)
decl_stmt|;
return|return
name|Max
operator|<
name|uptr
operator|>
operator|(
literal|1
operator|,
name|Min
argument_list|(
name|kMaxNumCachedHint
argument_list|,
name|n
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|Print
parameter_list|()
block|{
name|uptr
name|prev_s
init|=
literal|0
decl_stmt|;
name|uptr
name|total_cached
init|=
literal|0
decl_stmt|;
for|for
control|(
name|uptr
name|i
init|=
literal|0
init|;
name|i
operator|<
name|kNumClasses
condition|;
name|i
operator|++
control|)
block|{
name|uptr
name|s
init|=
name|Size
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|>=
name|kMidSize
operator|/
literal|2
operator|&&
operator|(
name|s
operator|&
operator|(
name|s
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
condition|)
name|Printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|uptr
name|d
init|=
name|s
operator|-
name|prev_s
decl_stmt|;
name|uptr
name|p
init|=
name|prev_s
condition|?
operator|(
name|d
operator|*
literal|100
operator|/
name|prev_s
operator|)
else|:
literal|0
decl_stmt|;
name|uptr
name|l
init|=
name|s
condition|?
name|MostSignificantSetBitIndex
argument_list|(
name|s
argument_list|)
else|:
literal|0
decl_stmt|;
name|uptr
name|cached
init|=
name|MaxCachedHint
argument_list|(
name|i
argument_list|)
operator|*
name|s
decl_stmt|;
name|Printf
argument_list|(
literal|"c%02zd => s: %zd diff: +%zd %02zd%% l %zd "
literal|"cached: %zd %zd; id %zd\n"
argument_list|,
name|i
argument_list|,
name|Size
argument_list|(
name|i
argument_list|)
argument_list|,
name|d
argument_list|,
name|p
argument_list|,
name|l
argument_list|,
name|MaxCachedHint
argument_list|(
name|i
argument_list|)
argument_list|,
name|cached
argument_list|,
name|ClassID
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|total_cached
operator|+=
name|cached
expr_stmt|;
name|prev_s
operator|=
name|s
expr_stmt|;
block|}
name|Printf
argument_list|(
literal|"Total cached: %zd\n"
argument_list|,
name|total_cached
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|Validate
parameter_list|()
block|{
for|for
control|(
name|uptr
name|c
init|=
literal|1
init|;
name|c
operator|<
name|kNumClasses
condition|;
name|c
operator|++
control|)
block|{
comment|// Printf("Validate: c%zd\n", c);
name|uptr
name|s
init|=
name|Size
argument_list|(
name|c
argument_list|)
decl_stmt|;
name|CHECK_NE
argument_list|(
name|s
argument_list|,
literal|0U
argument_list|)
expr_stmt|;
name|CHECK_EQ
argument_list|(
name|ClassID
argument_list|(
name|s
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|!=
name|kNumClasses
operator|-
literal|1
condition|)
name|CHECK_EQ
argument_list|(
name|ClassID
argument_list|(
name|s
operator|+
literal|1
argument_list|)
argument_list|,
name|c
operator|+
literal|1
argument_list|)
expr_stmt|;
name|CHECK_EQ
argument_list|(
name|ClassID
argument_list|(
name|s
operator|-
literal|1
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
condition|)
name|CHECK_GT
argument_list|(
name|Size
argument_list|(
name|c
argument_list|)
argument_list|,
name|Size
argument_list|(
name|c
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|CHECK_EQ
argument_list|(
name|ClassID
argument_list|(
name|kMaxSize
operator|+
literal|1
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|uptr
name|s
init|=
literal|1
init|;
name|s
operator|<=
name|kMaxSize
condition|;
name|s
operator|++
control|)
block|{
name|uptr
name|c
init|=
name|ClassID
argument_list|(
name|s
argument_list|)
decl_stmt|;
comment|// Printf("s%zd => c%zd\n", s, c);
name|CHECK_LT
argument_list|(
name|c
argument_list|,
name|kNumClasses
argument_list|)
expr_stmt|;
name|CHECK_GE
argument_list|(
name|Size
argument_list|(
name|c
argument_list|)
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|>
literal|0
condition|)
name|CHECK_LT
argument_list|(
name|Size
argument_list|(
name|c
operator|-
literal|1
argument_list|)
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_typedef
unit|};
typedef|typedef
name|SizeClassMap
operator|<
literal|3
operator|,
literal|4
operator|,
literal|8
operator|,
literal|17
operator|,
literal|128
operator|,
literal|16
operator|>
name|DefaultSizeClassMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SizeClassMap
operator|<
literal|3
operator|,
literal|4
operator|,
literal|8
operator|,
literal|17
operator|,
literal|64
operator|,
literal|14
operator|>
name|CompactSizeClassMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SizeClassMap
operator|<
literal|2
operator|,
literal|5
operator|,
literal|9
operator|,
literal|16
operator|,
literal|64
operator|,
literal|14
operator|>
name|VeryCompactSizeClassMap
expr_stmt|;
end_typedef

end_unit

