/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef BLIS_KERNEL_3M_MACRO_DEFS_H
#define BLIS_KERNEL_3M_MACRO_DEFS_H


// -- Define datatype-agnostic base 3m kernel names ----------------------------

// If any datatype-agnostic base name for a given micro-kernel does not
// exist, default to the reference kernel base name.

#ifndef GEMM3M_UKERNEL
#define GEMM3M_UKERNEL        gemm3m_ref_mxn
#endif

#ifndef GEMMTRSM3M_L_UKERNEL
#define GEMMTRSM3M_L_UKERNEL  gemmtrsm3m_l_ref_mxn
#endif

#ifndef GEMMTRSM3M_U_UKERNEL
#define GEMMTRSM3M_U_UKERNEL  gemmtrsm3m_u_ref_mxn
#endif

#ifndef TRSM3M_L_UKERNEL
#define TRSM3M_L_UKERNEL      trsm3m_l_ref_mxn
#endif

#ifndef TRSM3M_U_UKERNEL
#define TRSM3M_U_UKERNEL      trsm3m_u_ref_mxn
#endif


// -- Construct 3m kernel function names ---------------------------------------

// For each datatype-specific micro-kernel base name, construct the full
// function name of the corresponding micro-kernel.

#define BLIS_CGEMM3M_UKERNEL       PASTEMAC(c,GEMM3M_UKERNEL)
#define BLIS_ZGEMM3M_UKERNEL       PASTEMAC(z,GEMM3M_UKERNEL)

#define BLIS_CGEMMTRSM3M_L_UKERNEL PASTEMAC(c,GEMMTRSM3M_L_UKERNEL)
#define BLIS_ZGEMMTRSM3M_L_UKERNEL PASTEMAC(z,GEMMTRSM3M_L_UKERNEL)

#define BLIS_CGEMMTRSM3M_U_UKERNEL PASTEMAC(c,GEMMTRSM3M_U_UKERNEL)
#define BLIS_ZGEMMTRSM3M_U_UKERNEL PASTEMAC(z,GEMMTRSM3M_U_UKERNEL)

#define BLIS_CTRSM3M_L_UKERNEL     PASTEMAC(c,TRSM3M_L_UKERNEL)
#define BLIS_ZTRSM3M_L_UKERNEL     PASTEMAC(z,TRSM3M_L_UKERNEL)

#define BLIS_CTRSM3M_U_UKERNEL     PASTEMAC(c,TRSM3M_U_UKERNEL)
#define BLIS_ZTRSM3M_U_UKERNEL     PASTEMAC(z,TRSM3M_U_UKERNEL)


// -- Define 3m-specific blocksize macros --------------------------------------

// Define complex 3m register blocksizes in terms of blocksizes used for
// real kernels.

// 3m register blocksizes
#define BLIS_DEFAULT_3M_MR_C     BLIS_DEFAULT_MR_S
#define BLIS_DEFAULT_3M_KR_C     BLIS_DEFAULT_KR_S
#define BLIS_DEFAULT_3M_NR_C     BLIS_DEFAULT_NR_S

#define BLIS_DEFAULT_3M_MR_Z     BLIS_DEFAULT_MR_D
#define BLIS_DEFAULT_3M_KR_Z     BLIS_DEFAULT_KR_D
#define BLIS_DEFAULT_3M_NR_Z     BLIS_DEFAULT_NR_D

// 3m register blocksize extensions
#define BLIS_EXTEND_3M_MR_C      BLIS_EXTEND_MR_S
#define BLIS_EXTEND_3M_KR_C      BLIS_EXTEND_KR_S
#define BLIS_EXTEND_3M_NR_C      BLIS_EXTEND_NR_S

#define BLIS_EXTEND_3M_MR_Z      BLIS_EXTEND_MR_D
#define BLIS_EXTEND_3M_KR_Z      BLIS_EXTEND_KR_D
#define BLIS_EXTEND_3M_NR_Z      BLIS_EXTEND_NR_D

// Define complex 3m cache blocksizes in terms of blocksizes used for
// real operations (if they have not yet already been defined).

// 3m cache blocksizes
#ifndef BLIS_DEFAULT_3M_MC_C
#define BLIS_DEFAULT_3M_MC_C     ((BLIS_DEFAULT_MC_S)/1)
#endif
#ifndef BLIS_DEFAULT_3M_KC_C
#define BLIS_DEFAULT_3M_KC_C     ((BLIS_DEFAULT_KC_S)/2)
#endif
#ifndef BLIS_DEFAULT_3M_NC_C
#define BLIS_DEFAULT_3M_NC_C     ((BLIS_DEFAULT_NC_S)/1)
#endif

#ifndef BLIS_DEFAULT_3M_MC_Z
#define BLIS_DEFAULT_3M_MC_Z     ((BLIS_DEFAULT_MC_D)/1)
#endif
#ifndef BLIS_DEFAULT_3M_KC_Z
#define BLIS_DEFAULT_3M_KC_Z     ((BLIS_DEFAULT_KC_D)/2)
#endif
#ifndef BLIS_DEFAULT_3M_NC_Z
#define BLIS_DEFAULT_3M_NC_Z     ((BLIS_DEFAULT_NC_D)/1)
#endif

// 3m cache blocksize extensions
#ifndef BLIS_EXTEND_3M_MC_C
#define BLIS_EXTEND_3M_MC_C      0
#endif
#ifndef BLIS_EXTEND_3M_KC_C
#define BLIS_EXTEND_3M_KC_C      0
#endif
#ifndef BLIS_EXTEND_3M_NC_C
#define BLIS_EXTEND_3M_NC_C      0
#endif

#ifndef BLIS_EXTEND_3M_MC_Z
#define BLIS_EXTEND_3M_MC_Z      0
#endif
#ifndef BLIS_EXTEND_3M_KC_Z
#define BLIS_EXTEND_3M_KC_Z      0
#endif
#ifndef BLIS_EXTEND_3M_NC_Z
#define BLIS_EXTEND_3M_NC_Z      0
#endif


// -- Kernel macro checks ------------------------------------------------------

// Verify that cache blocksizes are whole multiples of register blocksizes.
// Specifically, verify that:
//   - MC is a whole multiple of MR *AND* NR.
//   - NC is a whole multiple of NR *AND* MR.
//   - KC is a whole multiple of KR *AND* both MR, NR.
// These constraints are enforced because it makes it easier to handle diagonals
// in the macro-kernel implementations. 

//
// MC must be a whole multiple of MR and NR.
//
#if ( \
      ( BLIS_DEFAULT_3M_MC_C % BLIS_DEFAULT_3M_MR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_MC_Z % BLIS_DEFAULT_3M_MR_Z != 0 )    \
    )
  #error "MC (3m) must be multiple of MR for all datatypes."
#endif

#if ( \
      ( BLIS_DEFAULT_3M_MC_C % BLIS_DEFAULT_3M_NR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_MC_Z % BLIS_DEFAULT_3M_NR_Z != 0 )    \
    )
  #error "MC (3m) must be multiple of NR for all datatypes."
#endif

//
// NC must be a whole multiple of NR and MR.
//
#if ( \
      ( BLIS_DEFAULT_3M_NC_C % BLIS_DEFAULT_3M_NR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_NC_Z % BLIS_DEFAULT_3M_NR_Z != 0 )    \
    )
  #error "NC (3m) must be multiple of NR for all datatypes."
#endif

#if ( \
      ( BLIS_DEFAULT_3M_NC_C % BLIS_DEFAULT_3M_MR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_NC_Z % BLIS_DEFAULT_3M_MR_Z != 0 )    \
    )
  #error "NC (3m) must be multiple of MR for all datatypes."
#endif

//
// KC must be a whole multiple of KR, MR, and NR.
//
#if ( \
      ( BLIS_DEFAULT_3M_KC_C % BLIS_DEFAULT_3M_KR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_KC_Z % BLIS_DEFAULT_3M_KR_Z != 0 )    \
    )
  #error "KC (3m) must be multiple of KR for all datatypes."
#endif

#if ( \
      ( BLIS_DEFAULT_3M_KC_C % BLIS_DEFAULT_3M_MR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_KC_Z % BLIS_DEFAULT_3M_MR_Z != 0 )    \
    )
  #error "KC (3m) must be multiple of MR for all datatypes."
#endif

#if ( \
      ( BLIS_DEFAULT_3M_KC_C % BLIS_DEFAULT_3M_NR_C != 0 ) || \
      ( BLIS_DEFAULT_3M_KC_Z % BLIS_DEFAULT_3M_NR_Z != 0 )    \
    )
  #error "KC (3m) must be multiple of NR for all datatypes."
#endif


// -- Compute maximum cache blocksizes -----------------------------------------

#define BLIS_MAXIMUM_3M_MC_C  ( BLIS_DEFAULT_3M_MC_C + BLIS_EXTEND_3M_MC_C )
#define BLIS_MAXIMUM_3M_KC_C  ( BLIS_DEFAULT_3M_KC_C + BLIS_EXTEND_3M_KC_C )
#define BLIS_MAXIMUM_3M_NC_C  ( BLIS_DEFAULT_3M_NC_C + BLIS_EXTEND_3M_NC_C )

#define BLIS_MAXIMUM_3M_MC_Z  ( BLIS_DEFAULT_3M_MC_Z + BLIS_EXTEND_3M_MC_Z )
#define BLIS_MAXIMUM_3M_KC_Z  ( BLIS_DEFAULT_3M_KC_Z + BLIS_EXTEND_3M_KC_Z )
#define BLIS_MAXIMUM_3M_NC_Z  ( BLIS_DEFAULT_3M_NC_Z + BLIS_EXTEND_3M_NC_Z )

// -- Compute leading dim blocksizes used for packing --------------------------

#define BLIS_PACKDIM_3M_MR_C  ( BLIS_DEFAULT_3M_MR_C + BLIS_EXTEND_3M_MR_C )
#define BLIS_PACKDIM_3M_KR_C  ( BLIS_DEFAULT_3M_KR_C + BLIS_EXTEND_3M_KR_C )
#define BLIS_PACKDIM_3M_NR_C  ( BLIS_DEFAULT_3M_NR_C + BLIS_EXTEND_3M_NR_C )

#define BLIS_PACKDIM_3M_MR_Z  ( BLIS_DEFAULT_3M_MR_Z + BLIS_EXTEND_3M_MR_Z )
#define BLIS_PACKDIM_3M_KR_Z  ( BLIS_DEFAULT_3M_KR_Z + BLIS_EXTEND_3M_KR_Z )
#define BLIS_PACKDIM_3M_NR_Z  ( BLIS_DEFAULT_3M_NR_Z + BLIS_EXTEND_3M_NR_Z )



#endif 