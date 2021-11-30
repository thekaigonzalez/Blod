
typedef struct IError IError;

typedef struct multi_return_u32_u32 multi_return_u32_u32;
typedef struct multi_return_u32_u32_u32 multi_return_u32_u32_u32;
typedef struct multi_return_int_strconv__PrepNumber multi_return_int_strconv__PrepNumber;
typedef struct multi_return_u64_int multi_return_u64_int;
typedef struct multi_return_strconv__Dec32_bool multi_return_strconv__Dec32_bool;
typedef struct multi_return_strconv__Dec64_bool multi_return_strconv__Dec64_bool;
typedef struct multi_return_u64_u64 multi_return_u64_u64;
typedef struct multi_return_f64_int multi_return_f64_int;

typedef struct strconv__BF_param strconv__BF_param;
typedef struct strconv__PrepNumber strconv__PrepNumber;
typedef struct strconv__Dec32 strconv__Dec32;
typedef struct strconv__Dec64 strconv__Dec64;
typedef struct strconv__Uint128 strconv__Uint128;
typedef union strconv__Uf32 strconv__Uf32;
typedef union strconv__Uf64 strconv__Uf64;
typedef union strconv__Float64u strconv__Float64u;
typedef union strconv__Float32u strconv__Float32u;
typedef struct array array;
typedef struct ZZZTmp1 ZZZTmp1;
typedef struct ZZZTmp2 ZZZTmp2;
typedef struct ZZZTmp3 ZZZTmp3;
typedef struct ZZZTmp4 ZZZTmp4;
typedef struct ZZZTmp5 ZZZTmp5;
typedef struct ZZZTmp6 ZZZTmp6;
typedef struct VCastTypeIndexName VCastTypeIndexName;
typedef struct VAssertMetaInfo VAssertMetaInfo;
typedef struct MethodArgs MethodArgs;
typedef struct FunctionData FunctionData;
typedef struct FieldData FieldData;
typedef struct StructAttribute StructAttribute;
typedef struct DenseArray DenseArray;
typedef struct map map;
typedef struct Error Error;
typedef struct None__ None__;
typedef struct Option Option;
typedef struct VMemoryBlock VMemoryBlock;
typedef struct SortedMap SortedMap;
typedef struct mapnode mapnode;
typedef struct string string;
typedef struct RepIndex RepIndex;
typedef union StrIntpMem StrIntpMem;
typedef struct StrIntpCgenData StrIntpCgenData;
typedef struct StrIntpData StrIntpData;

typedef struct none none;
typedef struct Option_int Option_int;
typedef struct Option_u64 Option_u64;
typedef struct Option_i64 Option_i64;
typedef struct Option_byte Option_byte;


#if defined(__TINYC__) && defined(__has_include)
// tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif

#if defined(__has_include)

#if __has_include(<inttypes.h>)
#include <inttypes.h>
#else
#error ERROR_MESSAGE The C compiler can not find <inttypes.h>. Please install build-essentials
#endif

#else
#include <inttypes.h>
#endif


#if defined(__has_include)

#if __has_include(<stddef.h>)
#include <stddef.h>
#else
#error ERROR_MESSAGE The C compiler can not find <stddef.h>. Please install build-essentials
#endif

#else
#include <stddef.h>
#endif


//================================== builtin types ================================*/
typedef int64_t i64;
typedef int16_t i16;
typedef int8_t i8;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint8_t byte;
typedef uint32_t rune;
typedef size_t usize;
typedef ptrdiff_t isize;
typedef float f32;
typedef double f64;
typedef int64_t int_literal;
typedef double float_literal;
typedef unsigned char* byteptr;
typedef void* voidptr;
typedef char* charptr;
typedef byte array_fixed_byte_300 [300];

typedef struct sync__Channel* chan;

#ifndef __cplusplus
	#ifndef bool
		typedef byte bool;
		#define true 1
		#define false 0
	#endif
#endif

typedef u64 (*MapHashFn)(voidptr);
typedef bool (*MapEqFn)(voidptr, voidptr);
typedef void (*MapCloneFn)(voidptr, voidptr);
typedef void (*MapFreeFn)(voidptr);

//============================== HELPER C MACROS =============================*/
// _SLIT0 is used as NULL string for literal arguments
// `"" s` is used to enforce a string literal argument
#define _SLIT0 (string){.str=(byteptr)(""), .len=0, .is_lit=1}
#define _SLIT(s) ((string){.str=(byteptr)("" s), .len=(sizeof(s)-1), .is_lit=1})
#define _SLEN(s, n) ((string){.str=(byteptr)("" s), .len=n, .is_lit=1})

// take the address of an rvalue
#define ADDR(type, expr) (&((type[]){expr}[0]))

// copy something to the heap
#define HEAP(type, expr) ((type*)memdup((void*)&((type[]){expr}[0]), sizeof(type)))
#define HEAP_noscan(type, expr) ((type*)memdup_noscan((void*)&((type[]){expr}[0]), sizeof(type)))

#define _PUSH_MANY(arr, val, tmp, tmp_typ) {tmp_typ tmp = (val); array_push_many(arr, tmp.data, tmp.len);}
#define _PUSH_MANY_noscan(arr, val, tmp, tmp_typ) {tmp_typ tmp = (val); array_push_many_noscan(arr, tmp.data, tmp.len);}

// unsigned/signed comparisons
static inline bool _us32_gt(uint32_t a, int32_t b) { return a > INT32_MAX || (int32_t)a > b; }
static inline bool _us32_ge(uint32_t a, int32_t b) { return a >= INT32_MAX || (int32_t)a >= b; }
static inline bool _us32_eq(uint32_t a, int32_t b) { return a <= INT32_MAX && (int32_t)a == b; }
static inline bool _us32_ne(uint32_t a, int32_t b) { return a > INT32_MAX || (int32_t)a != b; }
static inline bool _us32_le(uint32_t a, int32_t b) { return a <= INT32_MAX && (int32_t)a <= b; }
static inline bool _us32_lt(uint32_t a, int32_t b) { return a < INT32_MAX && (int32_t)a < b; }
static inline bool _us64_gt(uint64_t a, int64_t b) { return a > INT64_MAX || (int64_t)a > b; }
static inline bool _us64_ge(uint64_t a, int64_t b) { return a >= INT64_MAX || (int64_t)a >= b; }
static inline bool _us64_eq(uint64_t a, int64_t b) { return a <= INT64_MAX && (int64_t)a == b; }
static inline bool _us64_ne(uint64_t a, int64_t b) { return a > INT64_MAX || (int64_t)a != b; }
static inline bool _us64_le(uint64_t a, int64_t b) { return a <= INT64_MAX && (int64_t)a <= b; }
static inline bool _us64_lt(uint64_t a, int64_t b) { return a < INT64_MAX && (int64_t)a < b; }

#define EMPTY_VARG_INITIALIZATION 0
#define EMPTY_STRUCT_DECLARATION
#define EMPTY_STRUCT_INITIALIZATION
// Due to a tcc bug, the length of an array needs to be specified, but GCC crashes if it is...
#define EMPTY_ARRAY_OF_ELEMS(x,n) (x[])
#define TCCSKIP(x) x

#define __NOINLINE __attribute__((noinline))
#define __IRQHANDLER __attribute__((interrupt))

#define _Darchitecture 0
#if defined(__x86_64__)
	#define _Damd64  1
	#undef _Darchitecture
	#define _Darchitecture 1
#endif

#if defined(__aarch64__) || defined(__arm64__)
	#define _Darm64  1
	#undef _Darchitecture
	#define _Darchitecture 2
#endif

// Using just __GNUC__ for detecting gcc, is not reliable because other compilers define it too:
#ifdef __GNUC__
	#define _DGCC__
#endif
#ifdef __TINYC__
	#undef _DGCC__
#endif
#ifdef __cplusplus
	#undef _DGCC__
#endif
#ifdef __clang__
	#undef _DGCC__
#endif
#ifdef _MSC_VER
	#undef _DGCC__
	#undef EMPTY_STRUCT_INITIALIZATION
	#define EMPTY_STRUCT_INITIALIZATION 0
#endif

#ifdef __TINYC__
	#undef EMPTY_STRUCT_DECLARATION
	#define EMPTY_STRUCT_DECLARATION char _dummy
	#undef EMPTY_ARRAY_OF_ELEMS
	#define EMPTY_ARRAY_OF_ELEMS(x,n) (x[n])
	#undef __NOINLINE
	#undef __IRQHANDLER
	// tcc does not support inlining at all
	#define __NOINLINE
	#define __IRQHANDLER
	#undef TCCSKIP
	#define TCCSKIP(x)
	// #include <byteswap.h>
	#ifndef _WIN32
		#include <execinfo.h>
		int tcc_backtrace(const char *fmt, ...);
	#endif
#endif

// Use __offsetof_ptr instead of __offset_of, when you *do* have a valid pointer, to avoid UB:
#ifndef __offsetof_ptr
	#define __offsetof_ptr(ptr,PTYPE,FIELDNAME) ((size_t)((byte *)&((PTYPE *)ptr)->FIELDNAME - (byte *)ptr))
#endif

// for __offset_of
#ifndef __offsetof
	#define __offsetof(PTYPE,FIELDNAME) ((size_t)((char *)&((PTYPE *)0)->FIELDNAME - (char *)0))
#endif

#define OPTION_CAST(x) (x)

#ifndef V64_PRINTFORMAT
	#ifdef PRIx64
		#define V64_PRINTFORMAT "0x%"PRIx64
	#elif defined(__WIN32__)
		#define V64_PRINTFORMAT "0x%I64x"
	#elif defined(__linux__) && defined(__LP64__)
		#define V64_PRINTFORMAT "0x%lx"
	#else
		#define V64_PRINTFORMAT "0x%llx"
	#endif
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
	#define VV_EXPORTED_SYMBOL extern __declspec(dllexport)
	#define VV_LOCAL_SYMBOL static
#else
	// 4 < gcc < 5 is used by some older Ubuntu LTS and Centos versions,
	// and does not support __has_attribute(visibility) ...
	#ifndef __has_attribute
		#define __has_attribute(x) 0  // Compatibility with non-clang compilers.
	#endif
	#if (defined(__GNUC__) && (__GNUC__ >= 4)) || (defined(__clang__) && __has_attribute(visibility))
		#ifdef ARM
			#define VV_EXPORTED_SYMBOL  extern __attribute__((externally_visible,visibility("default")))
		#else
			#define VV_EXPORTED_SYMBOL  extern __attribute__((visibility("default")))
		#endif
		#define VV_LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))
	#else
		#define VV_EXPORTED_SYMBOL extern
		#define VV_LOCAL_SYMBOL static
	#endif
#endif

#ifdef __cplusplus
	#include <utility>
	#define _MOV std::move
#else
	#define _MOV
#endif

// tcc does not support has_include properly yet, turn it off completely
#if defined(__TINYC__) && defined(__has_include)
#undef __has_include
#endif


#if !defined(VWEAK)
	#define VWEAK __attribute__((weak))
	#ifdef _MSC_VER
		#undef VWEAK
		#define VWEAK
	#endif
#endif

#if !defined(VNORETURN)
	#if defined(__TINYC__)
		#include <stdnoreturn.h>
		#define VNORETURN noreturn
	#endif
	# if !defined(__TINYC__) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
	#  define VNORETURN _Noreturn
	# elif defined(__GNUC__) && __GNUC__ >= 2
	#  define VNORETURN __attribute__((noreturn))
	# endif
	#ifndef VNORETURN
		#define VNORETURN
	#endif
#endif

#if !defined(VUNREACHABLE)
	#if defined(__GNUC__) && !defined(__clang__)
		#define V_GCC_VERSION  (__GNUC__ * 10000L + __GNUC_MINOR__ * 100L + __GNUC_PATCHLEVEL__)
		#if (V_GCC_VERSION >= 40500L)
			#define VUNREACHABLE()  do { __builtin_unreachable(); } while (0)
		#endif
	#endif
	#if defined(__clang__) && defined(__has_builtin)
		#if __has_builtin(__builtin_unreachable)
			#define VUNREACHABLE()  do { __builtin_unreachable(); } while (0)
		#endif
	#endif
	#ifndef VUNREACHABLE
		#define VUNREACHABLE() do { } while (0)
	#endif
	#if defined(__FreeBSD__) && defined(__TINYC__)
		#define VUNREACHABLE() do { } while (0)
	#endif
#endif

//likely and unlikely macros
#if defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__clang__)
	#define _likely_(x)  __builtin_expect(x,1)
	#define _unlikely_(x)  __builtin_expect(x,0)
#else
	#define _likely_(x) (x)
	#define _unlikely_(x) (x)
#endif


// c_headers
typedef int (*qsort_callback_func)(const void*, const void*);
#include <stdio.h>  // TODO remove all these includes, define all function signatures and types manually
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(__CYGWIN__)
	#define VV_EXPORTED_SYMBOL extern __declspec(dllexport)
	#define VV_LOCAL_SYMBOL static
#else
	// 4 < gcc < 5 is used by some older Ubuntu LTS and Centos versions,
	// and does not support __has_attribute(visibility) ...
	#ifndef __has_attribute
		#define __has_attribute(x) 0  // Compatibility with non-clang compilers.
	#endif
	#if (defined(__GNUC__) && (__GNUC__ >= 4)) || (defined(__clang__) && __has_attribute(visibility))
		#ifdef ARM
			#define VV_EXPORTED_SYMBOL  extern __attribute__((externally_visible,visibility("default")))
		#else
			#define VV_EXPORTED_SYMBOL  extern __attribute__((visibility("default")))
		#endif
		#define VV_LOCAL_SYMBOL  __attribute__ ((visibility ("hidden")))
	#else
		#define VV_EXPORTED_SYMBOL extern
		#define VV_LOCAL_SYMBOL static
	#endif
#endif

#if defined(__TINYC__) && defined(__has_include)
// tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif

#ifndef _WIN32
	#if defined __has_include
		#if __has_include (<execinfo.h>)
			#include <execinfo.h>
		#else
			// Most probably musl OR __ANDROID__ ...
			int backtrace (void **__array, int __size) { return 0; }
			char **backtrace_symbols (void *const *__array, int __size){ return 0; }
			void backtrace_symbols_fd (void *const *__array, int __size, int __fd){}
		#endif
	#endif
#endif

#include <stdarg.h> // for va_list

//================================== GLOBALS =================================*/
int load_so(byteptr);
void _vinit(int ___argc, voidptr ___argv);
void _vcleanup(void);
#define sigaction_size sizeof(sigaction);
#define _ARR_LEN(a) ( (sizeof(a)) / (sizeof(a[0])) )

void v_free(voidptr ptr);
voidptr memdup(voidptr src, int sz);

#if INTPTR_MAX == INT32_MAX
	#define TARGET_IS_32BIT 1
#elif INTPTR_MAX == INT64_MAX
	#define TARGET_IS_64BIT 1
#else
	#error "The environment is not 32 or 64-bit."
#endif

#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ || defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)
	#define TARGET_ORDER_IS_BIG 1
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ || defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(_M_AMD64) || defined(_M_X64) || defined(_M_IX86)
	#define TARGET_ORDER_IS_LITTLE 1
#else
	#error "Unknown architecture endianness"
#endif

#ifndef _WIN32
	#include <ctype.h>
	#include <locale.h> // tolower
	#include <sys/time.h>
	#include <unistd.h> // sleep
	extern char **environ;
#endif

#if defined(__CYGWIN__) && !defined(_WIN32)
	#error Cygwin is not supported, please use MinGW or Visual Studio.
#endif

#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__vinix__) || defined(__serenity__) || defined(__sun)
	#include <sys/types.h>
	#include <sys/wait.h> // os__wait uses wait on nix
#endif

#ifdef __OpenBSD__
	#include <sys/types.h>
	#include <sys/resource.h>
	#include <sys/wait.h> // os__wait uses wait on nix
#endif

#ifdef __NetBSD__
	#include <sys/wait.h> // os__wait uses wait on nix
#endif

#ifdef _WIN32
	#define WINVER 0x0600
	#ifdef _WIN32_WINNT
		#undef _WIN32_WINNT
	#endif
	#define _WIN32_WINNT 0x0600
	#ifndef WIN32_FULL
	#define WIN32_LEAN_AND_MEAN
	#endif
	#ifndef _UNICODE
	#define _UNICODE
	#endif
	#ifndef UNICODE
	#define UNICODE
	#endif
	#include <windows.h>

	#include <io.h> // _waccess
	#include <direct.h> // _wgetcwd
	#include <signal.h> // signal and SIGSEGV for segmentation fault handler

	#ifdef _MSC_VER
		// On MSVC these are the same (as long as /volatile:ms is passed)
		#define _Atomic volatile

		// MSVC cannot parse some things properly
		#undef EMPTY_STRUCT_DECLARATION
		#undef OPTION_CAST

		#define EMPTY_STRUCT_DECLARATION char __pad
		#define OPTION_CAST(x)
		#undef __NOINLINE
		#undef __IRQHANDLER
		#define __NOINLINE __declspec(noinline)
		#define __IRQHANDLER __declspec(naked)

		#include <dbghelp.h>
		#pragma comment(lib, "Dbghelp")
	#endif
#else
	#include <pthread.h>
	#ifndef PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP
		// musl does not have that
		#define pthread_rwlockattr_setkind_np(a, b)
	#endif
#endif

// g_live_info is used by live.info()
static void* g_live_info = NULL;

#if defined(__MINGW32__) || defined(__MINGW64__) || (defined(_WIN32) && defined(__TINYC__))
	#undef PRId64
	#undef PRIi64
	#undef PRIo64
	#undef PRIu64
	#undef PRIx64
	#undef PRIX64
	#define PRId64 "lld"
	#define PRIi64 "lli"
	#define PRIo64 "llo"
	#define PRIu64 "llu"
	#define PRIx64 "llx"
	#define PRIX64 "llX"
#endif

#ifdef _VFREESTANDING
#undef _VFREESTANDING
#endif


// ============== wyhash ==============
#ifndef wyhash_final_version_3
#define wyhash_final_version_3

#ifndef WYHASH_CONDOM
// protections that produce different results:
// 1: normal valid behavior
// 2: extra protection against entropy loss (probability=2^-63), aka. "blind multiplication"
#define WYHASH_CONDOM 1
#endif

#ifndef WYHASH_32BIT_MUM
// 0: normal version, slow on 32 bit systems
// 1: faster on 32 bit systems but produces different results, incompatible with wy2u0k function
#define WYHASH_32BIT_MUM 0
#endif

// includes
#include <stdint.h>
#if defined(_MSC_VER) && defined(_M_X64)
	#include <intrin.h>
	#pragma intrinsic(_umul128)
#endif

// 128bit multiply function
static inline uint64_t _wyrot(uint64_t x) { return (x>>32)|(x<<32); }
static inline void _wymum(uint64_t *A, uint64_t *B){
#if(WYHASH_32BIT_MUM)
	uint64_t hh=(*A>>32)*(*B>>32), hl=(*A>>32)*(uint32_t)*B, lh=(uint32_t)*A*(*B>>32), ll=(uint64_t)(uint32_t)*A*(uint32_t)*B;
	#if(WYHASH_CONDOM>1)
	*A^=_wyrot(hl)^hh; *B^=_wyrot(lh)^ll;
	#else
	*A=_wyrot(hl)^hh; *B=_wyrot(lh)^ll;
	#endif
#elif defined(__SIZEOF_INT128__)
	__uint128_t r=*A; r*=*B;
	#if(WYHASH_CONDOM>1)
	*A^=(uint64_t)r; *B^=(uint64_t)(r>>64);
	#else
	*A=(uint64_t)r; *B=(uint64_t)(r>>64);
	#endif
#elif defined(_MSC_VER) && defined(_M_X64)
	#if(WYHASH_CONDOM>1)
	uint64_t  a,  b;
	a=_umul128(*A,*B,&b);
	*A^=a;  *B^=b;
	#else
	*A=_umul128(*A,*B,B);
	#endif
#else
	uint64_t ha=*A>>32, hb=*B>>32, la=(uint32_t)*A, lb=(uint32_t)*B, hi, lo;
	uint64_t rh=ha*hb, rm0=ha*lb, rm1=hb*la, rl=la*lb, t=rl+(rm0<<32), c=t<rl;
	lo=t+(rm1<<32); c+=lo<t; hi=rh+(rm0>>32)+(rm1>>32)+c;
	#if(WYHASH_CONDOM>1)
	*A^=lo;  *B^=hi;
	#else
	*A=lo;  *B=hi;
	#endif
#endif
}

// multiply and xor mix function, aka MUM
static inline uint64_t _wymix(uint64_t A, uint64_t B){ _wymum(&A,&B); return A^B; }

// endian macros
#ifndef WYHASH_LITTLE_ENDIAN
	#ifdef TARGET_ORDER_IS_LITTLE
		#define WYHASH_LITTLE_ENDIAN 1
	#else
		#define WYHASH_LITTLE_ENDIAN 0
	#endif
#endif

// read functions
#if (WYHASH_LITTLE_ENDIAN)
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return v;}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return v;}
#elif defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__clang__)
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return __builtin_bswap64(v);}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return __builtin_bswap32(v);}
#elif defined(_MSC_VER)
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return _byteswap_uint64(v);}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return _byteswap_ulong(v);}
#else
	static inline uint64_t _wyr8(const uint8_t *p) {
		uint64_t v; memcpy(&v, p, 8);
		return (((v >> 56) & 0xff)| ((v >> 40) & 0xff00)| ((v >> 24) & 0xff0000)| ((v >>  8) & 0xff000000)| ((v <<  8) & 0xff00000000)| ((v << 24) & 0xff0000000000)| ((v << 40) & 0xff000000000000)| ((v << 56) & 0xff00000000000000));
	}
	static inline uint64_t _wyr4(const uint8_t *p) {
		uint32_t v; memcpy(&v, p, 4);
		return (((v >> 24) & 0xff)| ((v >>  8) & 0xff00)| ((v <<  8) & 0xff0000)| ((v << 24) & 0xff000000));
	}
#endif
static inline uint64_t _wyr3(const uint8_t *p, size_t k) { return (((uint64_t)p[0])<<16)|(((uint64_t)p[k>>1])<<8)|p[k-1];}
// wyhash main function
static inline uint64_t wyhash(const void *key, size_t len, uint64_t seed, const uint64_t *secret){
	const uint8_t *p=(const uint8_t *)key; seed^=*secret;	uint64_t a, b;
	if (_likely_(len<=16)) {
		if (_likely_(len>=4)) { a=(_wyr4(p)<<32)|_wyr4(p+((len>>3)<<2)); b=(_wyr4(p+len-4)<<32)|_wyr4(p+len-4-((len>>3)<<2)); }
		else if (_likely_(len>0)) { a=_wyr3(p,len); b=0; }
		else a=b=0;
	} else {
		size_t i=len;
		if (_unlikely_(i>48)) {
			uint64_t see1=seed, see2=seed;
			do {
				seed=_wymix(_wyr8(p)^secret[1],_wyr8(p+8)^seed);
				see1=_wymix(_wyr8(p+16)^secret[2],_wyr8(p+24)^see1);
				see2=_wymix(_wyr8(p+32)^secret[3],_wyr8(p+40)^see2);
				p+=48; i-=48;
			} while(_likely_(i>48));
			seed^=see1^see2;
		}
		while(_unlikely_(i>16)) { seed=_wymix(_wyr8(p)^secret[1],_wyr8(p+8)^seed);  i-=16; p+=16; }
		a=_wyr8(p+i-16);  b=_wyr8(p+i-8);
	}
	return _wymix(secret[1]^len,_wymix(a^secret[1],b^seed));
}
// the default secret parameters
static const uint64_t _wyp[4] = {0xa0761d6478bd642full, 0xe7037ed1a0b428dbull, 0x8ebc6af09c88c6e3ull, 0x589965cc75374cc3ull};

// a useful 64bit-64bit mix function to produce deterministic pseudo random numbers that can pass BigCrush and PractRand
static inline uint64_t wyhash64(uint64_t A, uint64_t B){ A^=0xa0761d6478bd642full; B^=0xe7037ed1a0b428dbull; _wymum(&A,&B); return _wymix(A^0xa0761d6478bd642full,B^0xe7037ed1a0b428dbull);}

// the wyrand PRNG that pass BigCrush and PractRand
static inline uint64_t wyrand(uint64_t *seed){ *seed+=0xa0761d6478bd642full; return _wymix(*seed,*seed^0xe7037ed1a0b428dbull);}

#ifndef __vinix__
// convert any 64 bit pseudo random numbers to uniform distribution [0,1). It can be combined with wyrand, wyhash64 or wyhash.
static inline double wy2u01(uint64_t r){ const double _wynorm=1.0/(1ull<<52); return (r>>12)*_wynorm;}

// convert any 64 bit pseudo random numbers to APPROXIMATE Gaussian distribution. It can be combined with wyrand, wyhash64 or wyhash.
static inline double wy2gau(uint64_t r){ const double _wynorm=1.0/(1ull<<20); return ((r&0x1fffff)+((r>>21)&0x1fffff)+((r>>42)&0x1fffff))*_wynorm-3.0;}
#endif

#if(!WYHASH_32BIT_MUM)
// fast range integer random number generation on [0,k) credit to Daniel Lemire. May not work when WYHASH_32BIT_MUM=1. It can be combined with wyrand, wyhash64 or wyhash.
static inline uint64_t wy2u0k(uint64_t r, uint64_t k){ _wymum(&r,&k); return k; }
#endif
#endif

#define _IN_MAP(val, m) map_exists(m, val)



// V includes:

#if defined(__TINYC__) && defined(__has_include)
// tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif


// added by module `builtin`

#if defined(__has_include)

#if __has_include(<float.h>)
#include <float.h>
#else
#error ERROR_MESSAGE Header file <float.h>, needed for module `builtin` was not found. Please install the corresponding development headers.
#endif

#else
#include <float.h>
#endif




// Enum definitions:
typedef enum {
	strconv__Align_text__right = 0, // 0
	strconv__Align_text__left, // 0+1
	strconv__Align_text__center, // 0+2
} strconv__Align_text;

typedef enum {
	strconv__Char_parse_state__start, // 
	strconv__Char_parse_state__norm_char, // +1
	strconv__Char_parse_state__field_char, // +2
	strconv__Char_parse_state__pad_ch, // +3
	strconv__Char_parse_state__len_set_start, // +4
	strconv__Char_parse_state__len_set_in, // +5
	strconv__Char_parse_state__check_type, // +6
	strconv__Char_parse_state__check_float, // +7
	strconv__Char_parse_state__check_float_in, // +8
	strconv__Char_parse_state__reset_params, // +9
} strconv__Char_parse_state;

typedef enum {
	ArrayFlags__noslices = 1, // 1 << 0
} ArrayFlags;

typedef enum {
	AttributeKind__plain, // 
	AttributeKind__string, // +1
	AttributeKind__number, // +2
	AttributeKind__comptime_define, // +3
} AttributeKind;

typedef enum {
	ChanState__success, // 
	ChanState__not_ready, // +1
	ChanState__closed, // +2
} ChanState;

typedef enum {
	StrIntpType__si_no_str = 0, // 0
	StrIntpType__si_c, // 0+1
	StrIntpType__si_u8, // 0+2
	StrIntpType__si_i8, // 0+3
	StrIntpType__si_u16, // 0+4
	StrIntpType__si_i16, // 0+5
	StrIntpType__si_u32, // 0+6
	StrIntpType__si_i32, // 0+7
	StrIntpType__si_u64, // 0+8
	StrIntpType__si_i64, // 0+9
	StrIntpType__si_e32, // 0+10
	StrIntpType__si_e64, // 0+11
	StrIntpType__si_f32, // 0+12
	StrIntpType__si_f64, // 0+13
	StrIntpType__si_g32, // 0+14
	StrIntpType__si_g64, // 0+15
	StrIntpType__si_s, // 0+16
	StrIntpType__si_p, // 0+17
	StrIntpType__si_vp, // 0+18
} StrIntpType;


// V type definitions:
struct IError {
	union {
		void* _object;
		None__* _None__;
		Error* _Error;
	};
	int _typ;
	string* msg;
	int* code;
};

struct string {
	byte* str;
	int len;
	int is_lit;
};



struct array {
	int element_size;
	voidptr data;
	int offset;
	int len;
	int cap;
	ArrayFlags flags;
};



struct DenseArray {
	int key_bytes;
	int value_bytes;
	int cap;
	int len;
	u32 deletes;
	byte* all_deleted;
	byte* values;
	byte* keys;
};



struct map {
	int key_bytes;
	int value_bytes;
	u32 even_index;
	byte cached_hashbits;
	byte shift;
	DenseArray key_values;
	u32* metas;
	u32 extra_metas;
	bool has_string_keys;
	MapHashFn hash_fn;
	MapEqFn key_eq_fn;
	MapCloneFn clone_fn;
	MapFreeFn free_fn;
	int len;
};



struct Error {
	string msg;
	int code;
};



struct Option {
	byte state;
	IError err;
};


typedef array Array_string;
typedef array Array_byte;
typedef array Array_int;
typedef array Array_voidptr;
typedef array Array_VCastTypeIndexName;
typedef array Array_MethodArgs;
typedef array Array_byte_ptr;
typedef array Array_rune;
typedef string Array_fixed_string_11 [11];
typedef voidptr Array_fixed_voidptr_11 [11];
typedef array Array_RepIndex;
typedef map Map_string_int;
typedef byte Array_fixed_byte_5 [5];
typedef array Array_u64;
typedef array Array_u32;
typedef array Array_strconv__Uint128;
typedef array Array_f64;
typedef byte Array_fixed_byte_32 [32];
typedef byte Array_fixed_byte_26 [26];
typedef u8 Array_fixed_u8_32 [32];
typedef voidptr Array_fixed_voidptr_100 [100];
typedef byte Array_fixed_byte_1000 [1000];
typedef byte Array_fixed_byte_17 [17];
typedef array Array_StrIntpType;
typedef int i32;
typedef Array_byte strings__Builder;
typedef int (*anon_fn_voidptr_voidptr__int)(voidptr,voidptr);
typedef bool (*anon_fn_voidptr__bool)(voidptr);
typedef voidptr (*anon_fn_voidptr__voidptr)(voidptr);
typedef int (*anon_fn_int_int__int)(int,int);
typedef void (*FnExitCb)();
typedef int (*FnSortCB)(voidptr,voidptr);
// builtin types:
//------------------ #endbuiltin
struct none {
	EMPTY_STRUCT_DECLARATION;
};
typedef pthread_t _Dthread;

struct ZZZTmp1 {
	EMPTY_STRUCT_DECLARATION;
};



struct ZZZTmp2 {
	EMPTY_STRUCT_DECLARATION;
};



struct ZZZTmp3 {
	EMPTY_STRUCT_DECLARATION;
};



struct ZZZTmp4 {
	EMPTY_STRUCT_DECLARATION;
};



struct ZZZTmp5 {
	EMPTY_STRUCT_DECLARATION;
};



struct ZZZTmp6 {
	EMPTY_STRUCT_DECLARATION;
};



struct StrIntpCgenData {
	string str;
	string fmt;
	string d;
};



struct VCastTypeIndexName {
	int tindex;
	string tname;
};



struct VAssertMetaInfo {
	string fpath;
	int line_nr;
	string fn_name;
	string src;
	string op;
	string llabel;
	string rlabel;
	string lvalue;
	string rvalue;
};



struct MethodArgs {
	int typ;
	string name;
};



struct FunctionData {
	string name;
	Array_string attrs;
	Array_MethodArgs args;
	int return_type;
	int typ;
};



struct FieldData {
	string name;
	Array_string attrs;
	bool is_pub;
	bool is_mut;
	bool is_shared;
	int typ;
};



struct StructAttribute {
	string name;
	bool has_arg;
	string arg;
	AttributeKind kind;
};



union strconv__Float64u {
	f64 f;
	u64 u;
};



union strconv__Float32u {
	f32 f;
	u32 u;
};



struct None__ {
	string msg;
	int code;
};



struct VMemoryBlock {
	int id;
	int cap;
	byte* start;
	VMemoryBlock* previous;
	int remaining;
	byte* current;
	int mallocs;
};



struct SortedMap {
	int value_bytes;
	mapnode* root;
	int len;
};



struct RepIndex {
	int idx;
	int val_idx;
};



union StrIntpMem {
	u32 d_c;
	byte d_u8;
	i8 d_i8;
	u16 d_u16;
	i16 d_i16;
	u32 d_u32;
	int d_i32;
	u64 d_u64;
	i64 d_i64;
	f32 d_f32;
	f64 d_f64;
	string d_s;
	voidptr d_p;
	voidptr d_vp;
};



struct strconv__BF_param {
	byte pad_ch;
	int len0;
	int len1;
	bool positive;
	bool sign_flag;
	strconv__Align_text allign;
	bool rm_tail_zero;
};



struct strconv__PrepNumber {
	bool negative;
	int exponent;
	u64 mantissa;
};



struct strconv__Dec32 {
	u32 m;
	int e;
};



union strconv__Uf32 {
	f32 f;
	u32 u;
};



struct strconv__Dec64 {
	u64 m;
	int e;
};



union strconv__Uf64 {
	f64 f;
	u64 u;
};



struct strconv__Uint128 {
	u64 lo;
	u64 hi;
};



struct mapnode {
	voidptr* children;
	int len;
	Array_fixed_string_11 keys;
	Array_fixed_voidptr_11 values;
};



struct StrIntpData {
	string str;
	u32 fmt;
	StrIntpMem d;
};



// BEGIN_multi_return_structs
struct multi_return_u32_u32 {
	u32 arg0;
	u32 arg1;
};

struct multi_return_u32_u32_u32 {
	u32 arg0;
	u32 arg1;
	u32 arg2;
};

struct multi_return_int_strconv__PrepNumber {
	int arg0;
	strconv__PrepNumber arg1;
};

struct multi_return_u64_int {
	u64 arg0;
	int arg1;
};

struct multi_return_strconv__Dec32_bool {
	strconv__Dec32 arg0;
	bool arg1;
};

struct multi_return_strconv__Dec64_bool {
	strconv__Dec64 arg0;
	bool arg1;
};

struct multi_return_u64_u64 {
	u64 arg0;
	u64 arg1;
};

struct multi_return_f64_int {
	f64 arg0;
	int arg1;
};

// END_multi_return_structs


// V shared types:

// V Option_xxx definitions:
struct Option_int {
	byte state;
	IError err;
	byte data[sizeof(int)];
};

struct Option_u64 {
	byte state;
	IError err;
	byte data[sizeof(u64)];
};

struct Option_i64 {
	byte state;
	IError err;
	byte data[sizeof(i64)];
};

struct Option_byte {
	byte state;
	IError err;
	byte data[sizeof(byte)];
};


// V json forward decls:

// V definitions:
static char * v_typeof_interface_IError(int sidx);
// end of definitions #endif
strings__Builder strings__new_builder(int initial_size);
void strings__Builder_write_ptr(strings__Builder* b, byte* ptr, int len);
void strings__Builder_write_rune(strings__Builder* b, rune r);
void strings__Builder_write_runes(strings__Builder* b, Array_rune runes);
void strings__Builder_write_b(strings__Builder* b, byte data);
Option_int strings__Builder_write(strings__Builder* b, Array_byte data);
byte strings__Builder_byte_at(strings__Builder* b, int n);
void strings__Builder_write_string(strings__Builder* b, string s);
void strings__Builder_go_back(strings__Builder* b, int n);
string strings__Builder_cut_last(strings__Builder* b, int n);
string strings__Builder_cut_to(strings__Builder* b, int pos);
void strings__Builder_go_back_to(strings__Builder* b, int pos);
void strings__Builder_writeln(strings__Builder* b, string s);
string strings__Builder_last_n(strings__Builder* b, int n);
string strings__Builder_after(strings__Builder* b, int n);
string strings__Builder_str(strings__Builder* b);
void strings__Builder_free(strings__Builder* b);
int strings__levenshtein_distance(string a, string b);
f32 strings__levenshtein_distance_percentage(string a, string b);
f32 strings__dice_coefficient(string s1, string s2);
string strings__repeat(byte c, int n);
string strings__repeat_string(string s, int n);
u32 _const_math__bits__de_bruijn32 = 125613361; // precomputed
Array_byte _const_math__bits__de_bruijn32tab; // inited later
u64 _const_math__bits__de_bruijn64 = 285870213051353865U; // precomputed
Array_byte _const_math__bits__de_bruijn64tab; // inited later
u64 _const_math__bits__m0 = 6148914691236517205U; // precomputed
u64 _const_math__bits__m1 = 3689348814741910323U; // precomputed
u64 _const_math__bits__m2 = 1085102592571150095U; // precomputed
u64 _const_math__bits__m3 = 71777214294589695U; // precomputed
u64 _const_math__bits__m4 = 281470681808895U; // precomputed
u32 _const_math__bits__max_u32 = 4294967295; // precomputed
u64 _const_math__bits__max_u64 = 18446744073709551615U; // precomputed
int math__bits__leading_zeros_8(byte x);
int math__bits__leading_zeros_16(u16 x);
int math__bits__leading_zeros_32(u32 x);
int math__bits__leading_zeros_64(u64 x);
int math__bits__trailing_zeros_8(byte x);
int math__bits__trailing_zeros_16(u16 x);
int math__bits__trailing_zeros_32(u32 x);
int math__bits__trailing_zeros_64(u64 x);
int math__bits__ones_count_8(byte x);
int math__bits__ones_count_16(u16 x);
int math__bits__ones_count_32(u32 x);
int math__bits__ones_count_64(u64 x);
byte math__bits__rotate_left_8(byte x, int k);
u16 math__bits__rotate_left_16(u16 x, int k);
u32 math__bits__rotate_left_32(u32 x, int k);
u64 math__bits__rotate_left_64(u64 x, int k);
byte math__bits__reverse_8(byte x);
u16 math__bits__reverse_16(u16 x);
u32 math__bits__reverse_32(u32 x);
u64 math__bits__reverse_64(u64 x);
u16 math__bits__reverse_bytes_16(u16 x);
u32 math__bits__reverse_bytes_32(u32 x);
u64 math__bits__reverse_bytes_64(u64 x);
int math__bits__len_8(byte x);
int math__bits__len_16(u16 x);
int math__bits__len_32(u32 x);
int math__bits__len_64(u64 x);
multi_return_u32_u32 math__bits__add_32(u32 x, u32 y, u32 carry);
multi_return_u64_u64 math__bits__add_64(u64 x, u64 y, u64 carry);
multi_return_u32_u32 math__bits__sub_32(u32 x, u32 y, u32 borrow);
multi_return_u64_u64 math__bits__sub_64(u64 x, u64 y, u64 borrow);
u64 _const_math__bits__two32 = 4294967296U; // precomputed
u64 _const_math__bits__mask32 = 4294967295U; // precomputed
string _const_math__bits__overflow_error; // a string literal, inited later
string _const_math__bits__divide_error; // a string literal, inited later
multi_return_u32_u32 math__bits__mul_32(u32 x, u32 y);
multi_return_u64_u64 math__bits__mul_64(u64 x, u64 y);
multi_return_u32_u32 math__bits__div_32(u32 hi, u32 lo, u32 y);
multi_return_u64_u64 math__bits__div_64(u64 hi, u64 lo, u64 y1);
u32 math__bits__rem_32(u32 hi, u32 lo, u32 y);
u64 math__bits__rem_64(u64 hi, u64 lo, u64 y);
multi_return_f64_int math__bits__normalize(f64 x);
Array_byte _const_math__bits__ntz_8_tab; // inited later
Array_byte _const_math__bits__pop_8_tab; // inited later
Array_byte _const_math__bits__rev_8_tab; // inited later
Array_byte _const_math__bits__len_8_tab; // inited later
VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__lsr96(u32 s2, u32 s1, u32 s0);
VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__lsl96(u32 s2, u32 s1, u32 s0);
VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__add96(u32 s2, u32 s1, u32 s0, u32 d2, u32 d1, u32 d0);
VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__sub96(u32 s2, u32 s1, u32 s0, u32 d2, u32 d1, u32 d0);
u32 _const_strconv__single_plus_zero = 0; // precomputed
u32 _const_strconv__single_minus_zero = 2147483648; // precomputed
u32 _const_strconv__single_plus_infinity = 2139095040; // precomputed
u32 _const_strconv__single_minus_infinity = 4286578688; // precomputed
#define _const_strconv__digits 18
u64 _const_strconv__double_plus_zero = 0U; // precomputed
u64 _const_strconv__double_minus_zero = 9223372036854775808U; // precomputed
u64 _const_strconv__double_plus_infinity = 9218868437227405312U; // precomputed
u64 _const_strconv__double_minus_infinity = 18442240474082181120U; // precomputed
#define _const_strconv__parser_ok 0
#define _const_strconv__parser_pzero 1
#define _const_strconv__parser_mzero 2
#define _const_strconv__parser_pinf 3
#define _const_strconv__parser_minf 4
rune _const_strconv__c_dpoint = '.'; // precomputed
rune _const_strconv__c_plus = '+'; // precomputed
rune _const_strconv__c_minus = '-'; // precomputed
rune _const_strconv__c_zero = '0'; // precomputed
rune _const_strconv__c_nine = '9'; // precomputed
u32 _const_strconv__c_ten = 10; // precomputed
VV_LOCAL_SYMBOL bool strconv__is_digit(byte x);
VV_LOCAL_SYMBOL bool strconv__is_space(byte x);
VV_LOCAL_SYMBOL bool strconv__is_exp(byte x);
VV_LOCAL_SYMBOL multi_return_int_strconv__PrepNumber strconv__parser(string s);
VV_LOCAL_SYMBOL u64 strconv__converter(strconv__PrepNumber* pn);
f64 strconv__atof64(string s);
f64 strconv__atof_quick(string s);
Array_u64 _const_strconv__pos_exp; // inited later
Array_u64 _const_strconv__neg_exp; // inited later
#define _const_strconv__int_size 32
u64 _const_strconv__max_u64 = 18446744073709551615U; // precomputed
byte strconv__byte_to_lower(byte c);
Option_u64 strconv__common_parse_uint(string s, int _base, int _bit_size, bool error_on_non_digit, bool error_on_high_digit);
multi_return_u64_int strconv__common_parse_uint2(string s, int _base, int _bit_size);
Option_u64 strconv__parse_uint(string s, int _base, int _bit_size);
Option_i64 strconv__common_parse_int(string _s, int base, int _bit_size, bool error_on_non_digit, bool error_on_high_digit);
Option_i64 strconv__parse_int(string _s, int base, int _bit_size);
Option_int strconv__atoi(string s);
VV_LOCAL_SYMBOL bool strconv__underscore_ok(string s);
Array_u32 _const_strconv__ten_pow_table_32; // inited later
u32 _const_strconv__mantbits32 = 23; // precomputed
u32 _const_strconv__expbits32 = 8; // precomputed
#define _const_strconv__bias32 127
#define _const_strconv__maxexp32 255
string strconv__Dec32_get_string_32(strconv__Dec32 d, bool neg, int i_n_digit, int i_pad_digit);
VV_LOCAL_SYMBOL multi_return_strconv__Dec32_bool strconv__f32_to_decimal_exact_int(u32 i_mant, u32 exp);
VV_LOCAL_SYMBOL strconv__Dec32 strconv__f32_to_decimal(u32 mant, u32 exp);
string strconv__f32_to_str(f32 f, int n_digit);
string strconv__f32_to_str_pad(f32 f, int n_digit);
VV_LOCAL_SYMBOL string strconv__Dec64_get_string_64(strconv__Dec64 d, bool neg, int i_n_digit, int i_pad_digit);
VV_LOCAL_SYMBOL multi_return_strconv__Dec64_bool strconv__f64_to_decimal_exact_int(u64 i_mant, u64 exp);
VV_LOCAL_SYMBOL strconv__Dec64 strconv__f64_to_decimal(u64 mant, u64 exp);
string strconv__f64_to_str(f64 f, int n_digit);
string strconv__f64_to_str_pad(f64 f, int n_digit);
Array_u64 _const_strconv__ten_pow_table_64; // inited later
u32 _const_strconv__mantbits64 = 52; // precomputed
u32 _const_strconv__expbits64 = 11; // precomputed
#define _const_strconv__bias64 1023
#define _const_strconv__maxexp64 2047
Array_f64 _const_strconv__dec_round; // inited later
string strconv__format_str(string s, strconv__BF_param p);
void strconv__format_str_sb(string s, strconv__BF_param p, strings__Builder* sb);
#define _const_strconv__max_size_f64_char 32
string _const_strconv__digit_pairs; // a string literal, inited later
void strconv__format_dec_sb(u64 d, strconv__BF_param p, strings__Builder* res);
string strconv__f64_to_str_lnd1(f64 f, int dec_digit);
string strconv__format_fl(f64 f, strconv__BF_param p);
string strconv__format_es(f64 f, strconv__BF_param p);
string strconv__remove_tail_zeros(string s);
string strconv__ftoa_64(f64 f);
string strconv__ftoa_long_64(f64 f);
string strconv__ftoa_32(f32 f);
string strconv__ftoa_long_32(f32 f);
string _const_strconv__base_digits; // a string literal, inited later
string strconv__format_int(i64 n, int radix);
string strconv__format_uint(u64 n, int radix);
#define _const_strconv__pow5_num_bits_32 61
#define _const_strconv__pow5_inv_num_bits_32 59
#define _const_strconv__pow5_num_bits_64 121
#define _const_strconv__pow5_inv_num_bits_64 122
Array_u64 _const_strconv__powers_of_10; // inited later
Array_u64 _const_strconv__pow5_split_32; // inited later
Array_u64 _const_strconv__pow5_inv_split_32; // inited later
Array_strconv__Uint128 _const_strconv__pow5_split_64; // inited later
Array_strconv__Uint128 _const_strconv__pow5_inv_split_64; // inited later
string strconv__f32_to_str_l(f32 f);
string strconv__f32_to_str_l_no_dot(f32 f);
string strconv__f64_to_str_l(f64 f);
string strconv__f64_to_str_l_no_dot(f64 f);
string strconv__fxx_to_str_l_parse(string s);
string strconv__fxx_to_str_l_parse_no_dot(string s);
VV_LOCAL_SYMBOL int strconv__bool_to_int(bool b);
VV_LOCAL_SYMBOL u32 strconv__bool_to_u32(bool b);
VV_LOCAL_SYMBOL u64 strconv__bool_to_u64(bool b);
VV_LOCAL_SYMBOL string strconv__get_string_special(bool neg, bool expZero, bool mantZero);
VV_LOCAL_SYMBOL u32 strconv__mul_shift_32(u32 m, u64 mul, int ishift);
VV_LOCAL_SYMBOL u32 strconv__mul_pow5_invdiv_pow2(u32 m, u32 q, int j);
VV_LOCAL_SYMBOL u32 strconv__mul_pow5_div_pow2(u32 m, u32 i, int j);
VV_LOCAL_SYMBOL u32 strconv__pow5_factor_32(u32 i_v);
VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_five_32(u32 v, u32 p);
VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_two_32(u32 v, u32 p);
VV_LOCAL_SYMBOL u32 strconv__log10_pow2(int e);
VV_LOCAL_SYMBOL u32 strconv__log10_pow5(int e);
VV_LOCAL_SYMBOL int strconv__pow5_bits(int e);
VV_LOCAL_SYMBOL u64 strconv__shift_right_128(strconv__Uint128 v, int shift);
VV_LOCAL_SYMBOL u64 strconv__mul_shift_64(u64 m, strconv__Uint128 mul, int shift);
VV_LOCAL_SYMBOL u32 strconv__pow5_factor_64(u64 v_i);
VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_five_64(u64 v, u32 p);
VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_two_64(u64 v, u32 p);
int strconv__dec_digits(u64 n);
void strconv_Dprintf(string str, Array_voidptr pt);
string strconv_Dsprintf(string str, Array_voidptr pt);
VV_LOCAL_SYMBOL void strconv_Dsprintf_panic(int idx, int len);
VV_LOCAL_SYMBOL f64 strconv__fabs(f64 x);
string strconv__format_fl_old(f64 f, strconv__BF_param p);
string strconv__format_es_old(f64 f, strconv__BF_param p);
string strconv__remove_tail_zeros_old(string s);
string strconv__format_dec_old(u64 d, strconv__BF_param p);
VV_LOCAL_SYMBOL array __new_array(int mylen, int cap, int elm_size);
VV_LOCAL_SYMBOL array __new_array_with_default(int mylen, int cap, int elm_size, voidptr val);
VV_LOCAL_SYMBOL array __new_array_with_array_default(int mylen, int cap, int elm_size, array val);
VV_LOCAL_SYMBOL array new_array_from_c_array(int len, int cap, int elm_size, voidptr c_array);
VV_LOCAL_SYMBOL array new_array_from_c_array_no_alloc(int len, int cap, int elm_size, voidptr c_array);
VV_LOCAL_SYMBOL void array_ensure_cap(array* a, int required);
array array_repeat(array a, int count);
array array_repeat_to_depth(array a, int count, int depth);
void array_sort_with_compare(array* a, int (*callback)(voidptr , voidptr ));
void array_insert(array* a, int i, voidptr val);
void array_insert_many(array* a, int i, voidptr val, int size);
void array_prepend(array* a, voidptr val);
void array_prepend_many(array* a, voidptr val, int size);
void array_delete(array* a, int i);
void array_delete_many(array* a, int i, int size);
void array_clear(array* a);
void array_trim(array* a, int index);
VV_LOCAL_SYMBOL voidptr array_get_unsafe(array a, int i);
VV_LOCAL_SYMBOL voidptr array_get(array a, int i);
VV_LOCAL_SYMBOL voidptr array_get_with_check(array a, int i);
voidptr array_first(array a);
voidptr array_last(array a);
voidptr array_pop(array* a);
void array_delete_last(array* a);
VV_LOCAL_SYMBOL array array_slice(array a, int start, int _end);
VV_LOCAL_SYMBOL array array_slice2(array a, int start, int _end, bool end_max);
VV_LOCAL_SYMBOL array array_clone_static_to_depth(array a, int depth);
array array_clone(array* a);
array array_clone_to_depth(array* a, int depth);
VV_LOCAL_SYMBOL void array_set_unsafe(array* a, int i, voidptr val);
VV_LOCAL_SYMBOL void array_set(array* a, int i, voidptr val);
VV_LOCAL_SYMBOL void array_push(array* a, voidptr val);
void array_push_many(array* a3, voidptr val, int size);
void array_reverse_in_place(array* a);
array array_reverse(array a);
void array_free(array* a);
array array_filter(array a, bool (*predicate)(voidptr ));
bool array_any(array a, bool (*predicate)(voidptr ));
bool array_all(array a, bool (*predicate)(voidptr ));
array array_map(array a, voidptr (*callback)(voidptr ));
void array_sort(array* a, int (*callback)(voidptr , voidptr ));
bool array_contains(array a, voidptr val);
int array_index(array a, voidptr value);
void Array_string_free(Array_string* a);
string Array_string_str(Array_string a);
string Array_byte_hex(Array_byte b);
int copy(Array_byte dst, Array_byte src);
int Array_int_reduce(Array_int a, int (*iter)(int , int ), int accum_start);
void array_grow_cap(array* a, int amount);
void array_grow_len(array* a, int amount);
Array_voidptr array_pointers(array a);
Array_byte voidptr_vbytes(voidptr data, int len);
Array_byte byte_vbytes(byte* data, int len);
bool ArrayFlags_is_empty(ArrayFlags* e);
bool ArrayFlags_has(ArrayFlags* e, ArrayFlags flag);
bool ArrayFlags_all(ArrayFlags* e, ArrayFlags flag);
void ArrayFlags_set(ArrayFlags* e, ArrayFlags flag);
void ArrayFlags_clear(ArrayFlags* e, ArrayFlags flag);
void ArrayFlags_toggle(ArrayFlags* e, ArrayFlags flag);
VV_LOCAL_SYMBOL array __new_array_noscan(int mylen, int cap, int elm_size);
VV_LOCAL_SYMBOL void vhalt(void);
void Dexit(int code);
VV_LOCAL_SYMBOL string vcommithash(void);
VV_LOCAL_SYMBOL void panic_debug(int line_no, string file, string mod, string fn_name, string s);
void panic_optional_not_set(string s);
void Dpanic(string s);
string c_error_number_str(int errnum);
void panic_error_number(string basestr, int errnum);
void eprintln(string s);
void eprint(string s);
void print(string s);
void println(string s);
VV_LOCAL_SYMBOL void _writeln_to_fd(int fd, string s);
VV_LOCAL_SYMBOL void _write_buf_to_fd(int fd, byte* buf, int buf_len);
i64  total_m = ((i64)(0)); // global
byte* Dmalloc(int n);
byte* malloc_noscan(int n);
byte* v_realloc(byte* b, int n);
byte* realloc_data(byte* old_data, int old_size, int new_size);
byte* vcalloc(int n);
byte* vcalloc_noscan(int n);
void Dfree(voidptr ptr);
voidptr memdup(voidptr src, int sz);
voidptr memdup_noscan(voidptr src, int sz);
VV_LOCAL_SYMBOL int v_fixed_index(int i, int len);
void print_backtrace(void);
bool isnil(voidptr v);
Array_VCastTypeIndexName  as_cast_type_indexes; // global
VV_LOCAL_SYMBOL voidptr __as_cast(voidptr obj, int obj_type, int expected_type);
void VAssertMetaInfo_free(VAssertMetaInfo* ami);
VV_LOCAL_SYMBOL void __print_assert_failure(VAssertMetaInfo* i);
VV_LOCAL_SYMBOL void v_segmentation_fault_handler(int signal);
VV_LOCAL_SYMBOL void builtin_init(void);
VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames(int xskipframes);
VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames_bsd(int skipframes);
VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames_linux(int skipframes);
VV_LOCAL_SYMBOL void break_if_debugger_attached(void);
string winapi_lasterr_str(void);
void panic_lasterr(void);
void gc_check_leaks(void);
int proc_pidpath(int , voidptr , int );
int vstrlen(byte* s);
int vstrlen_char(char* s);
voidptr vmemcpy(voidptr dest, const voidptr const_src, int n);
voidptr vmemmove(voidptr dest, const voidptr const_src, int n);
int vmemcmp(const voidptr const_s1, const voidptr const_s2, int n);
voidptr vmemset(voidptr s, int c, int n);
VV_LOCAL_SYMBOL void vqsort(voidptr base, usize nmemb, usize size, int (*sort_cb)(const voidptr const_a, const voidptr const_b));
void chan_close(chan ch);
ChanState chan_try_pop(chan ch, voidptr obj);
ChanState chan_try_push(chan ch, voidptr obj);
string f64_str(f64 x);
string f64_strg(f64 x);
string float_literal_str(float_literal d);
string f64_strsci(f64 x, int digit_num);
string f64_strlong(f64 x);
string f32_str(f32 x);
string f32_strg(f32 x);
string f32_strsci(f32 x, int digit_num);
string f32_strlong(f32 x);
f32 f32_abs(f32 a);
VV_LOCAL_SYMBOL f64 f64_abs(f64 a);
f32 f32_max(f32 a, f32 b);
f32 f32_min(f32 a, f32 b);
f64 f64_max(f64 a, f64 b);
VV_LOCAL_SYMBOL f64 f64_min(f64 a, f64 b);
bool f32_eq_epsilon(f32 a, f32 b);
bool f64_eq_epsilon(f64 a, f64 b);
VV_LOCAL_SYMBOL void float_test(void);
string ptr_str(voidptr ptr);
string isize_str(isize x);
string usize_str(usize x);
string char_str(char* cptr);
string _const_digit_pairs; // a string literal, inited later
VV_LOCAL_SYMBOL string int_str_l(int nn, int max);
string i8_str(i8 n);
string i16_str(i16 n);
string u16_str(u16 n);
string int_str(int n);
string u32_str(u32 nn);
string int_literal_str(int_literal n);
string i64_str(i64 nn);
string u64_str(u64 nn);
string bool_str(bool b);
VV_LOCAL_SYMBOL string u64_to_hex(u64 nn, byte len);
VV_LOCAL_SYMBOL string u64_to_hex_no_leading_zeros(u64 nn, byte len);
string byte_hex(byte nn);
string i8_hex(i8 nn);
string u16_hex(u16 nn);
string i16_hex(i16 nn);
string u32_hex(u32 nn);
string int_hex(int nn);
string int_hex2(int n);
string u64_hex(u64 nn);
string i64_hex(i64 nn);
string int_literal_hex(int_literal nn);
string voidptr_str(voidptr nn);
string byteptr_str(byteptr nn);
string byte_hex_full(byte nn);
string i8_hex_full(i8 nn);
string u16_hex_full(u16 nn);
string i16_hex_full(i16 nn);
string u32_hex_full(u32 nn);
string int_hex_full(int nn);
string i64_hex_full(i64 nn);
string voidptr_hex_full(voidptr nn);
string int_literal_hex_full(int_literal nn);
string u64_hex_full(u64 nn);
string byte_str(byte b);
string byte_ascii_str(byte b);
string byte_str_escaped(byte b);
bool byte_is_capital(byte c);
Array_byte Array_byte_clone(Array_byte b);
string Array_byte_bytestr(Array_byte b);
string byte_repeat(byte b, int count);
VV_LOCAL_SYMBOL bool fast_string_eq(string a, string b);
VV_LOCAL_SYMBOL u64 map_hash_string(voidptr pkey);
VV_LOCAL_SYMBOL u64 map_hash_int_1(voidptr pkey);
VV_LOCAL_SYMBOL u64 map_hash_int_2(voidptr pkey);
VV_LOCAL_SYMBOL u64 map_hash_int_4(voidptr pkey);
VV_LOCAL_SYMBOL u64 map_hash_int_8(voidptr pkey);
VV_LOCAL_SYMBOL void DenseArray_zeros_to_end(DenseArray* d);
#define _const_hashbits 24
#define _const_max_cached_hashbits 16
#define _const_init_log_capicity 5
#define _const_init_capicity 32
f64 _const_max_load_factor = 0.8; // precomputed
#define _const_init_even_index 30
#define _const_extra_metas_inc 4
u32 _const_hash_mask = 16777215; // precomputed
u32 _const_probe_inc = 16777216; // precomputed
VV_LOCAL_SYMBOL DenseArray new_dense_array(int key_bytes, int value_bytes);
VV_LOCAL_SYMBOL voidptr DenseArray_key(DenseArray* d, int i);
VV_LOCAL_SYMBOL voidptr DenseArray_value(DenseArray* d, int i);
VV_LOCAL_SYMBOL bool DenseArray_has_index(DenseArray* d, int i);
VV_LOCAL_SYMBOL int DenseArray_expand(DenseArray* d);
VV_LOCAL_SYMBOL bool map_eq_string(voidptr a, voidptr b);
VV_LOCAL_SYMBOL bool map_eq_int_1(voidptr a, voidptr b);
VV_LOCAL_SYMBOL bool map_eq_int_2(voidptr a, voidptr b);
VV_LOCAL_SYMBOL bool map_eq_int_4(voidptr a, voidptr b);
VV_LOCAL_SYMBOL bool map_eq_int_8(voidptr a, voidptr b);
VV_LOCAL_SYMBOL void map_clone_string(voidptr dest, voidptr pkey);
VV_LOCAL_SYMBOL void map_clone_int_1(voidptr dest, voidptr pkey);
VV_LOCAL_SYMBOL void map_clone_int_2(voidptr dest, voidptr pkey);
VV_LOCAL_SYMBOL void map_clone_int_4(voidptr dest, voidptr pkey);
VV_LOCAL_SYMBOL void map_clone_int_8(voidptr dest, voidptr pkey);
VV_LOCAL_SYMBOL void map_free_string(voidptr pkey);
VV_LOCAL_SYMBOL void map_free_nop(voidptr _d1);
VV_LOCAL_SYMBOL map new_map(int key_bytes, int value_bytes, u64 (*hash_fn)(voidptr ), bool (*key_eq_fn)(voidptr , voidptr ), void (*clone_fn)(voidptr , voidptr ), void (*free_fn)(voidptr ));
VV_LOCAL_SYMBOL map new_map_init(u64 (*hash_fn)(voidptr ), bool (*key_eq_fn)(voidptr , voidptr ), void (*clone_fn)(voidptr , voidptr ), void (*free_fn)(voidptr ), int n, int key_bytes, int value_bytes, voidptr keys, voidptr values);
map map_move(map* m);
VV_LOCAL_SYMBOL multi_return_u32_u32 map_key_to_index(map* m, voidptr pkey);
VV_LOCAL_SYMBOL multi_return_u32_u32 map_meta_less(map* m, u32 _index, u32 _metas);
VV_LOCAL_SYMBOL void map_meta_greater(map* m, u32 _index, u32 _metas, u32 kvi);
VV_LOCAL_SYMBOL void map_ensure_extra_metas(map* m, u32 probe_count);
VV_LOCAL_SYMBOL void map_set(map* m, voidptr key, voidptr value);
VV_LOCAL_SYMBOL void map_expand(map* m);
VV_LOCAL_SYMBOL void map_rehash(map* m);
VV_LOCAL_SYMBOL void map_cached_rehash(map* m, u32 old_cap);
VV_LOCAL_SYMBOL voidptr map_get_and_set(map* m, voidptr key, voidptr zero);
VV_LOCAL_SYMBOL voidptr map_get(map* m, voidptr key, voidptr zero);
VV_LOCAL_SYMBOL voidptr map_get_check(map* m, voidptr key);
VV_LOCAL_SYMBOL bool map_exists(map* m, voidptr key);
VV_LOCAL_SYMBOL void DenseArray_delete(DenseArray* d, int i);
void map_delete(map* m, voidptr key);
array map_keys(map* m);
VV_LOCAL_SYMBOL DenseArray DenseArray_clone(DenseArray* d);
map map_clone(map* m);
void map_free(map* m);
void IError_free(IError* ie);
string IError_str(IError err);
IError _const_none__; // inited later
VV_LOCAL_SYMBOL string None___str(None__ _d1);
IError Derror(string message);
IError error_with_code(string message, int code);
VV_LOCAL_SYMBOL void opt_ok(voidptr data, Option* option, int size);
void Error_free(Error* e);
void None___free(None__* n);
#define _const_prealloc_block_size 16777216
VMemoryBlock*  g_memory_block; // global
VV_LOCAL_SYMBOL VMemoryBlock* vmemory_block_new(VMemoryBlock* prev, int at_least);
VV_LOCAL_SYMBOL byte* vmemory_block_malloc(int n);
VV_LOCAL_SYMBOL void prealloc_vinit(void);
VV_LOCAL_SYMBOL void prealloc_vcleanup(void);
VV_LOCAL_SYMBOL byte* prealloc_malloc(int n);
VV_LOCAL_SYMBOL byte* prealloc_realloc(byte* old_data, int old_size, int new_size);
VV_LOCAL_SYMBOL byte* prealloc_calloc(int n);
string rune_str(rune c);
string Array_rune_string(Array_rune ra);
string rune_repeat(rune c, int count);
#define _const_degree 6
#define _const_mid_index 5
#define _const_max_len 11
u32 _const_children_bytes; // inited later
VV_LOCAL_SYMBOL SortedMap new_sorted_map(int n, int value_bytes);
VV_LOCAL_SYMBOL SortedMap new_sorted_map_init(int n, int value_bytes, string* keys, voidptr values);
VV_LOCAL_SYMBOL mapnode* new_node(void);
VV_LOCAL_SYMBOL void SortedMap_set(SortedMap* m, string key, voidptr value);
VV_LOCAL_SYMBOL void mapnode_split_child(mapnode* n, int child_index, mapnode* y);
VV_LOCAL_SYMBOL bool SortedMap_get(SortedMap m, string key, voidptr out);
VV_LOCAL_SYMBOL bool SortedMap_exists(SortedMap m, string key);
VV_LOCAL_SYMBOL int mapnode_find_key(mapnode* n, string k);
VV_LOCAL_SYMBOL bool mapnode_remove_key(mapnode* n, string k);
VV_LOCAL_SYMBOL void mapnode_remove_from_leaf(mapnode* n, int idx);
VV_LOCAL_SYMBOL void mapnode_remove_from_non_leaf(mapnode* n, int idx);
VV_LOCAL_SYMBOL void mapnode_fill(mapnode* n, int idx);
VV_LOCAL_SYMBOL void mapnode_borrow_from_prev(mapnode* n, int idx);
VV_LOCAL_SYMBOL void mapnode_borrow_from_next(mapnode* n, int idx);
VV_LOCAL_SYMBOL void mapnode_merge(mapnode* n, int idx);
void SortedMap_delete(SortedMap* m, string key);
VV_LOCAL_SYMBOL int mapnode_subkeys(mapnode* n, Array_string* keys, int at);
Array_string SortedMap_keys(SortedMap* m);
VV_LOCAL_SYMBOL void mapnode_free(mapnode* n);
void SortedMap_free(SortedMap* m);
void SortedMap_print(SortedMap m);
Array_rune string_runes(string s);
string tos(byte* s, int len);
string tos_clone(byte* s);
string tos2(byte* s);
string tos3(char* s);
string tos4(byte* s);
string tos5(char* s);
string byte_vstring(byte* bp);
string byte_vstring_with_len(byte* bp, int len);
string char_vstring(char* cp);
string char_vstring_with_len(char* cp, int len);
string byte_vstring_literal(byte* bp);
string byte_vstring_literal_with_len(byte* bp, int len);
string char_vstring_literal(char* cp);
string char_vstring_literal_with_len(char* cp, int len);
VV_LOCAL_SYMBOL string string_clone_static(string a);
string string_clone(string a);
string cstring_to_vstring(char* cstr);
string string_replace_once(string s, string rep, string with);
string string_replace(string s, string rep, string with);
string string_replace_each(string s, Array_string vals);
int compare_RepIndex_by_idx(RepIndex* a, RepIndex* b) {
	if (a->idx < b->idx) return -1;
	else return 1;
}

bool string_bool(string s);
int string_int(string s);
i64 string_i64(string s);
i8 string_i8(string s);
i16 string_i16(string s);
f32 string_f32(string s);
f64 string_f64(string s);
u8 string_byte(string s);
u16 string_u16(string s);
u32 string_u32(string s);
u64 string_u64(string s);
VV_LOCAL_SYMBOL bool string__eq(string s, string a);
int string_compare(string s, string a);
VV_LOCAL_SYMBOL bool string__lt(string s, string a);
VV_LOCAL_SYMBOL string string__plus(string s, string a);
Array_string string_split(string s, string delim);
Array_string string_split_nth(string s, string delim, int nth);
Array_string string_split_into_lines(string s);
VV_LOCAL_SYMBOL string string_substr2(string s, int start, int _end, bool end_max);
string string_substr(string s, int start, int end);
VV_LOCAL_SYMBOL int string_index_(string s, string p);
Option_int string_index(string s, string p);
VV_LOCAL_SYMBOL int string_index_kmp(string s, string p);
int string_index_any(string s, string chars);
VV_LOCAL_SYMBOL int string_last_index_(string s, string p);
Option_int string_last_index(string s, string p);
int string_index_after(string s, string p, int start);
int string_index_byte(string s, byte c);
int string_last_index_byte(string s, byte c);
int string_count(string s, string substr);
bool string_contains(string s, string substr);
bool string_contains_any(string s, string chars);
bool string_contains_any_substr(string s, Array_string substrs);
bool string_starts_with(string s, string p);
bool string_ends_with(string s, string p);
string string_to_lower(string s);
bool string_is_lower(string s);
string string_to_upper(string s);
bool string_is_upper(string s);
string string_capitalize(string s);
bool string_is_capital(string s);
bool string_starts_with_capital(string s);
string string_title(string s);
bool string_is_title(string s);
string string_find_between(string s, string start, string end);
string string_trim_space(string s);
string string_trim(string s, string cutset);
string string_trim_left(string s, string cutset);
string string_trim_right(string s, string cutset);
string string_trim_prefix(string s, string str);
string string_trim_suffix(string s, string str);
int compare_strings(string* a, string* b);
VV_LOCAL_SYMBOL int compare_strings_by_len(string* a, string* b);
VV_LOCAL_SYMBOL int compare_lower_strings(string* a, string* b);
void Array_string_sort_ignore_case(Array_string* s);
void Array_string_sort_by_len(Array_string* s);
string string_str(string s);
VV_LOCAL_SYMBOL byte string_at(string s, int idx);
VV_LOCAL_SYMBOL Option_byte string_at_with_check(string s, int idx);
bool byte_is_space(byte c);
bool byte_is_digit(byte c);
bool byte_is_hex_digit(byte c);
bool byte_is_oct_digit(byte c);
bool byte_is_bin_digit(byte c);
bool byte_is_letter(byte c);
bool byte_is_alnum(byte c);
void string_free(string* s);
string string_before(string s, string sub);
string string_all_before(string s, string sub);
string string_all_before_last(string s, string sub);
string string_all_after(string s, string sub);
string string_all_after_last(string s, string sub);
string string_after(string s, string sub);
string string_after_char(string s, byte sub);
string Array_string_join(Array_string a, string sep);
string Array_string_join_lines(Array_string s);
string string_reverse(string s);
string string_limit(string s, int max);
int string_hash(string s);
Array_byte string_bytes(string s);
string string_repeat(string s, int count);
Array_string string_fields(string s);
string string_strip_margin(string s);
string string_strip_margin_custom(string s, byte del);
Array_byte byteptr_vbytes(byteptr data, int len);
string byteptr_vstring(byteptr bp);
string byteptr_vstring_with_len(byteptr bp, int len);
string charptr_vstring(charptr cp);
string charptr_vstring_with_len(charptr cp, int len);
string byteptr_vstring_literal(byteptr bp);
string byteptr_vstring_literal_with_len(byteptr bp, int len);
string charptr_vstring_literal(charptr cp);
string charptr_vstring_literal_with_len(charptr cp, int len);
string StrIntpType_str(StrIntpType x);
VV_LOCAL_SYMBOL f32 fabs32(f32 x);
VV_LOCAL_SYMBOL f64 fabs64(f64 x);
VV_LOCAL_SYMBOL u64 abs64(i64 x);
u64 get_str_intp_u64_format(StrIntpType fmt_type, int in_width, int in_precision, bool in_tail_zeros, bool in_sign, byte in_pad_ch, int in_base, bool in_upper_case);
u32 get_str_intp_u32_format(StrIntpType fmt_type, int in_width, int in_precision, bool in_tail_zeros, bool in_sign, byte in_pad_ch, int in_base, bool in_upper_case);
VV_LOCAL_SYMBOL void StrIntpData_get_fmt_format(StrIntpData data, strings__Builder* sb);
string str_intp(int data_len, voidptr in_data);
string _const_si_s_code; // a string literal, inited later
string _const_si_g32_code; // a string literal, inited later
string _const_si_g64_code; // a string literal, inited later
string str_intp_sq(string in_str);
string str_intp_rune(string in_str);
string str_intp_g32(string in_str);
string str_intp_g64(string in_str);
string str_intp_sub(string base_str, string in_str);
#define _const_cp_utf8 65001
u16* string_to_wide(string _str);
string string_from_wide(u16* _wstr);
string string_from_wide2(u16* _wstr, int len);
int utf8_getchar(void);
int utf8_char_len(byte b);
string utf32_to_str(u32 code);
string utf32_to_str_no_malloc(u32 code, byte* buf);
int string_utf32_code(string _rune);
VV_LOCAL_SYMBOL int utf8_len(byte c);
int utf8_str_len(string s);
int utf8_str_visible_length(string s);
VV_LOCAL_SYMBOL void main__main(void);
VV_LOCAL_SYMBOL void main__execv_blod(string code);


// V interface table:
static IError I_None___to_Interface_IError(None__* x);
const int _IError_None___index = 0;
static IError I_Error_to_Interface_IError(Error* x);
const int _IError_Error_index = 1;
// ^^^ number of types for interface IError: 2


// Casting functions for converting "None__" to interface "IError"
static inline IError I_None___to_Interface_IError(None__* x) {
	return (IError) {
		._None__ = x,
		._typ = _IError_None___index,
		.msg = (string*)((char*)x + __offsetof_ptr(x, None__, msg)),
		.code = (int*)((char*)x + __offsetof_ptr(x, None__, code)),
	};
}

// Casting functions for converting "Error" to interface "IError"
static inline IError I_Error_to_Interface_IError(Error* x) {
	return (IError) {
		._Error = x,
		._typ = _IError_Error_index,
		.msg = (string*)((char*)x + __offsetof_ptr(x, Error, msg)),
		.code = (int*)((char*)x + __offsetof_ptr(x, Error, code)),
	};
}



// V stringliterals:

// >> string literal consts
void vinit_string_literals(void){
	_const_math__bits__overflow_error = _SLIT("Overflow Error");
	_const_math__bits__divide_error = _SLIT("Divide Error");
	_const_strconv__digit_pairs = _SLIT("00102030405060708090011121314151617181910212223242526272829203132333435363738393041424344454647484940515253545556575859506162636465666768696071727374757677787970818283848586878889809192939495969798999");
	_const_strconv__base_digits = _SLIT("0123456789abcdefghijklmnopqrstuvwxyz");
	_const_digit_pairs = _SLIT("00102030405060708090011121314151617181910212223242526272829203132333435363738393041424344454647484940515253545556575859506162636465666768696071727374757677787970818283848586878889809192939495969798999");
	_const_si_s_code = _SLIT("0xfe10");
	_const_si_g32_code = _SLIT("0xfe0e");
	_const_si_g64_code = _SLIT("0xfe0f");
}
// << string literal consts


// V out

// >> typeof() support for sum types / interfaces
static char * v_typeof_interface_IError(int sidx) { /* IError */ 
	if (sidx == _IError_None___index) return "None__";
	if (sidx == _IError_Error_index) return "Error";
	return "unknown IError";
}

static int v_typeof_interface_idx_IError(int sidx) { /* IError */ 
	if (sidx == _IError_None___index) return 65618;
	if (sidx == _IError_Error_index) return 81;
	return 29;
}
// << typeof() support for sum types

// TypeDecl
strings__Builder strings__new_builder(int initial_size) {
	strings__Builder res = ((__new_array_with_default(0, initial_size, sizeof(byte), 0)));
	ArrayFlags_set(&res.flags, ArrayFlags__noslices);
	return res;
}

// Attr: [unsafe]
void strings__Builder_write_ptr(strings__Builder* b, byte* ptr, int len) {
	if (len == 0) {
		return;
	}
	array_push_many(b, ptr, len);
}

// Attr: [manualfree]
void strings__Builder_write_rune(strings__Builder* b, rune r) {
	Array_fixed_byte_5 buffer = {0};
	string res = utf32_to_str_no_malloc(((u32)(r)), &buffer[0]);
	if (res.len == 0) {
		return;
	}
	array_push_many(b, res.str, res.len);
}

void strings__Builder_write_runes(strings__Builder* b, Array_rune runes) {
	Array_fixed_byte_5 buffer = {0};
	for (int _t1 = 0; _t1 < runes.len; ++_t1) {
		rune r = ((rune*)runes.data)[_t1];
		string res = utf32_to_str_no_malloc(((u32)(r)), &buffer[0]);
		if (res.len == 0) {
			continue;
		}
		array_push_many(b, res.str, res.len);
	}
}

void strings__Builder_write_b(strings__Builder* b, byte data) {
	array_push((array*)b, _MOV((byte[]){ data }));
}

Option_int strings__Builder_write(strings__Builder* b, Array_byte data) {
	if (data.len == 0) {
		Option_int _t1;
		opt_ok(&(int[]) { 0 }, (Option*)(&_t1), sizeof(int));
		return _t1;
	}
	_PUSH_MANY(b, (data), _t2, strings__Builder);
	Option_int _t3;
	opt_ok(&(int[]) { data.len }, (Option*)(&_t3), sizeof(int));
	return _t3;
}

// Attr: [inline]
inline byte strings__Builder_byte_at(strings__Builder* b, int n) {
	return (*(byte*)/*ee elem_typ */array_get(*(((Array_byte*)(b))), n));
}

// Attr: [inline]
inline void strings__Builder_write_string(strings__Builder* b, string s) {
	if (s.len == 0) {
		return;
	}
	array_push_many(b, s.str, s.len);
}

void strings__Builder_go_back(strings__Builder* b, int n) {
	array_trim(b, b->len - n);
}

string strings__Builder_cut_last(strings__Builder* b, int n) {
	int cut_pos = b->len - n;
	Array_byte x = array_slice(*(((Array_byte*)(b))), cut_pos, (*(((Array_byte*)(b)))).len);
	string res = Array_byte_bytestr(x);
	array_trim(b, cut_pos);
	return res;
}

string strings__Builder_cut_to(strings__Builder* b, int pos) {
	if (pos > b->len) {
		return _SLIT("");
	}
	return strings__Builder_cut_last(b, b->len - pos);
}

void strings__Builder_go_back_to(strings__Builder* b, int pos) {
	array_trim(b, pos);
}

// Attr: [inline]
inline void strings__Builder_writeln(strings__Builder* b, string s) {
	if (s.len > 0) {
		array_push_many(b, s.str, s.len);
	}
	array_push((array*)b, _MOV((byte[]){ ((byte)('\n')) }));
}

string strings__Builder_last_n(strings__Builder* b, int n) {
	if (n > b->len) {
		return _SLIT("");
	}
	Array_byte x = array_slice(*(((Array_byte*)(b))), b->len - n, (*(((Array_byte*)(b)))).len);
	return Array_byte_bytestr(x);
}

string strings__Builder_after(strings__Builder* b, int n) {
	if (n >= b->len) {
		return _SLIT("");
	}
	Array_byte x = array_slice(*(((Array_byte*)(b))), n, (*(((Array_byte*)(b)))).len);
	return Array_byte_bytestr(x);
}

string strings__Builder_str(strings__Builder* b) {
	array_push((array*)b, _MOV((byte[]){ ((byte)(0)) }));
	byte* bcopy = ((byte*)(memdup_noscan(b->data, b->len)));
	string s = byte_vstring_with_len(bcopy, b->len - 1);
	array_trim(b, 0);
	return s;
}

// Attr: [unsafe]
void strings__Builder_free(strings__Builder* b) {
	if (b->data != 0) {
		Dfree(b->data);
		{ // Unsafe block
			b->data = ((voidptr)(0));
		}
	}
}

int strings__levenshtein_distance(string a, string b) {
	Array_int f = array_repeat_to_depth(new_array_from_c_array(1, 1, sizeof(int), _MOV((int[1]){0})), b.len + 1, 0);
	for (int j = 0; j < f.len; ++j) {
		array_set(&f, j, &(int[]) { j });
	}
	for (int _t1 = 0; _t1 < a.len; ++_t1) {
		byte ca = a.str[_t1];
		int j = 1;
		int fj1 = (*(int*)/*ee elem_typ */array_get(f, 0));
		(*(int*)/*ee elem_typ */array_get(f, 0))++;
		for (int _t2 = 0; _t2 < b.len; ++_t2) {
			byte cb = b.str[_t2];
			int mn = ((*(int*)/*ee elem_typ */array_get(f, j)) + 1 <= (*(int*)/*ee elem_typ */array_get(f, j - 1)) + 1 ? ((*(int*)/*ee elem_typ */array_get(f, j)) + 1) : ((*(int*)/*ee elem_typ */array_get(f, j - 1)) + 1));
			if (cb != ca) {
				mn = (mn <= fj1 + 1 ? (mn) : (fj1 + 1));
			} else {
				mn = (mn <= fj1 ? (mn) : (fj1));
			}
			fj1 = (*(int*)/*ee elem_typ */array_get(f, j));
			array_set(&f, j, &(int[]) { mn });
			j++;
		}
	}
	return (*(int*)/*ee elem_typ */array_get(f, f.len - 1));
}

f32 strings__levenshtein_distance_percentage(string a, string b) {
	int d = strings__levenshtein_distance(a, b);
	int l = (a.len >= b.len ? (a.len) : (b.len));
	return (1.00 - ((f32)(d)) / ((f32)(l))) * 100.00;
}

f32 strings__dice_coefficient(string s1, string s2) {
	if (s1.len == 0 || s2.len == 0) {
		return 0.0;
	}
	if (string__eq(s1, s2)) {
		return 1.0;
	}
	if (s1.len < 2 || s2.len < 2) {
		return 0.0;
	}
	string a = (s1.len > s2.len ? (s1) : (s2));
	string b = (string__eq(a, s1) ? (s2) : (s1));
	Map_string_int first_bigrams = new_map(sizeof(string), sizeof(int), &map_hash_string, &map_eq_string, &map_clone_string, &map_free_string);
	for (int i = 0; i < a.len - 1; ++i) {
		string bigram = string_substr(a, i, i + 2);
		int q = (_IN_MAP(ADDR(string, bigram), ADDR(map, first_bigrams)) ? ((*(int*)map_get(ADDR(map, first_bigrams), &(string[]){bigram}, &(int[]){ 0 })) + 1) : (1));
		map_set(&first_bigrams, &(string[]){bigram}, &(int[]) { q });
	}
	int intersection_size = 0;
	for (int i = 0; i < b.len - 1; ++i) {
		string bigram = string_substr(b, i, i + 2);
		int count = (_IN_MAP(ADDR(string, bigram), ADDR(map, first_bigrams)) ? ((*(int*)map_get(ADDR(map, first_bigrams), &(string[]){bigram}, &(int[]){ 0 }))) : (0));
		if (count > 0) {
			map_set(&first_bigrams, &(string[]){bigram}, &(int[]) { count - 1 });
			intersection_size++;
		}
	}
	return (2.0 * ((f32)(intersection_size))) / (((f32)(a.len)) + ((f32)(b.len)) - 2);
}

string strings__repeat(byte c, int n) {
	if (n <= 0) {
		return _SLIT("");
	}
	byte* bytes = malloc_noscan(n + 1);
	{ // Unsafe block
		memset(bytes, c, n);
		bytes[n] = '0';
	}
	return byte_vstring_with_len(bytes, n);
}

string strings__repeat_string(string s, int n) {
	if (n <= 0 || s.len == 0) {
		return _SLIT("");
	}
	int slen = s.len;
	int blen = slen * n;
	byte* bytes = malloc_noscan(blen + 1);
	for (int bi = 0; bi < n; ++bi) {
		int bislen = bi * slen;
		for (int si = 0; si < slen; ++si) {
			{ // Unsafe block
				bytes[bislen + si] = string_at(s, si);
			}
		}
	}
	{ // Unsafe block
		bytes[blen] = '0';
	}
	return byte_vstring_with_len(bytes, blen);
}

int math__bits__leading_zeros_8(byte x) {
	int _t1 = 8 - math__bits__len_8(x);
	return _t1;
}

int math__bits__leading_zeros_16(u16 x) {
	int _t1 = 16 - math__bits__len_16(x);
	return _t1;
}

int math__bits__leading_zeros_32(u32 x) {
	int _t1 = 32 - math__bits__len_32(x);
	return _t1;
}

int math__bits__leading_zeros_64(u64 x) {
	int _t1 = 64 - math__bits__len_64(x);
	return _t1;
}

int math__bits__trailing_zeros_8(byte x) {
	int _t1 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__ntz_8_tab, x))));
	return _t1;
}

int math__bits__trailing_zeros_16(u16 x) {
	if (x == 0U) {
		int _t1 = 16;
		return _t1;
	}
	int _t2 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__de_bruijn32tab, ((u32)((x & -x))) * _const_math__bits__de_bruijn32 >> (32 - 5)))));
	return _t2;
}

int math__bits__trailing_zeros_32(u32 x) {
	if (x == 0U) {
		int _t1 = 32;
		return _t1;
	}
	int _t2 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__de_bruijn32tab, ((x & -x)) * _const_math__bits__de_bruijn32 >> (32 - 5)))));
	return _t2;
}

int math__bits__trailing_zeros_64(u64 x) {
	if (x == 0U) {
		int _t1 = 64;
		return _t1;
	}
	int _t2 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__de_bruijn64tab, ((x & -x)) * _const_math__bits__de_bruijn64 >> (64 - 6)))));
	return _t2;
}

int math__bits__ones_count_8(byte x) {
	int _t1 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, x))));
	return _t1;
}

int math__bits__ones_count_16(u16 x) {
	int _t1 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, x >> 8U)) + (*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, (x & ((u16)(0xffU)))))));
	return _t1;
}

int math__bits__ones_count_32(u32 x) {
	int _t1 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, x >> 24U)) + (*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, (x >> 16U & 0xffU))) + (*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, (x >> 8U & 0xffU))) + (*(byte*)/*ee elem_typ */array_get(_const_math__bits__pop_8_tab, (x & ((u32)(0xffU)))))));
	return _t1;
}

int math__bits__ones_count_64(u64 x) {
	u64 y = ((x >> ((u64)(1U)) & ((_const_math__bits__m0 & _const_math__bits__max_u64)))) + ((x & ((_const_math__bits__m0 & _const_math__bits__max_u64))));
	y = ((y >> ((u64)(2U)) & ((_const_math__bits__m1 & _const_math__bits__max_u64)))) + ((y & ((_const_math__bits__m1 & _const_math__bits__max_u64))));
	y = (((y >> 4U) + y) & ((_const_math__bits__m2 & _const_math__bits__max_u64)));
	y += y >> 8U;
	y += y >> 16U;
	y += y >> 32U;
	int _t1 = (((int)(y)) & ((1 << 7) - 1));
	return _t1;
}

// Attr: [inline]
inline byte math__bits__rotate_left_8(byte x, int k) {
	byte n = ((byte)(8));
	byte s = (((byte)(k)) & (n - ((byte)(1))));
	byte _t1 = ((x << s) | (x >> (n - s)));
	return _t1;
}

// Attr: [inline]
inline u16 math__bits__rotate_left_16(u16 x, int k) {
	u16 n = ((u16)(16U));
	u16 s = (((u16)(k)) & (n - ((u16)(1U))));
	u16 _t1 = ((x << s) | (x >> (n - s)));
	return _t1;
}

// Attr: [inline]
inline u32 math__bits__rotate_left_32(u32 x, int k) {
	u32 n = ((u32)(32U));
	u32 s = (((u32)(k)) & (n - ((u32)(1U))));
	u32 _t1 = ((x << s) | (x >> (n - s)));
	return _t1;
}

// Attr: [inline]
inline u64 math__bits__rotate_left_64(u64 x, int k) {
	u64 n = ((u64)(64U));
	u64 s = (((u64)(k)) & (n - ((u64)(1U))));
	u64 _t1 = ((x << s) | (x >> (n - s)));
	return _t1;
}

// Attr: [inline]
inline byte math__bits__reverse_8(byte x) {
	byte _t1 = (*(byte*)/*ee elem_typ */array_get(_const_math__bits__rev_8_tab, x));
	return _t1;
}

// Attr: [inline]
inline u16 math__bits__reverse_16(u16 x) {
	u16 _t1 = (((u16)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__rev_8_tab, x >> 8U)))) | (((u16)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__rev_8_tab, (x & ((u16)(0xffU))))))) << 8U));
	return _t1;
}

// Attr: [inline]
inline u32 math__bits__reverse_32(u32 x) {
	u64 y = ((((x >> ((u32)(1U)) & ((_const_math__bits__m0 & _const_math__bits__max_u32)))) | (((x & ((_const_math__bits__m0 & _const_math__bits__max_u32)))) << 1U)));
	y = ((((y >> ((u32)(2U)) & ((_const_math__bits__m1 & _const_math__bits__max_u32)))) | (((y & ((_const_math__bits__m1 & _const_math__bits__max_u32)))) << ((u32)(2U)))));
	y = ((((y >> ((u32)(4U)) & ((_const_math__bits__m2 & _const_math__bits__max_u32)))) | (((y & ((_const_math__bits__m2 & _const_math__bits__max_u32)))) << ((u32)(4U)))));
	u32 _t1 = math__bits__reverse_bytes_32(((u32)(y)));
	return _t1;
}

// Attr: [inline]
inline u64 math__bits__reverse_64(u64 x) {
	u64 y = ((((x >> ((u64)(1U)) & ((_const_math__bits__m0 & _const_math__bits__max_u64)))) | (((x & ((_const_math__bits__m0 & _const_math__bits__max_u64)))) << 1U)));
	y = ((((y >> ((u64)(2U)) & ((_const_math__bits__m1 & _const_math__bits__max_u64)))) | (((y & ((_const_math__bits__m1 & _const_math__bits__max_u64)))) << 2U)));
	y = ((((y >> ((u64)(4U)) & ((_const_math__bits__m2 & _const_math__bits__max_u64)))) | (((y & ((_const_math__bits__m2 & _const_math__bits__max_u64)))) << 4U)));
	u64 _t1 = math__bits__reverse_bytes_64(y);
	return _t1;
}

// Attr: [inline]
inline u16 math__bits__reverse_bytes_16(u16 x) {
	u16 _t1 = ((x >> 8U) | (x << 8U));
	return _t1;
}

// Attr: [inline]
inline u32 math__bits__reverse_bytes_32(u32 x) {
	u64 y = ((((x >> ((u32)(8U)) & ((_const_math__bits__m3 & _const_math__bits__max_u32)))) | (((x & ((_const_math__bits__m3 & _const_math__bits__max_u32)))) << ((u32)(8U)))));
	u32 _t1 = ((u32)(((y >> 16U) | (y << 16U))));
	return _t1;
}

// Attr: [inline]
inline u64 math__bits__reverse_bytes_64(u64 x) {
	u64 y = ((((x >> ((u64)(8U)) & ((_const_math__bits__m3 & _const_math__bits__max_u64)))) | (((x & ((_const_math__bits__m3 & _const_math__bits__max_u64)))) << ((u64)(8U)))));
	y = ((((y >> ((u64)(16U)) & ((_const_math__bits__m4 & _const_math__bits__max_u64)))) | (((y & ((_const_math__bits__m4 & _const_math__bits__max_u64)))) << ((u64)(16U)))));
	u64 _t1 = ((y >> 32U) | (y << 32U));
	return _t1;
}

int math__bits__len_8(byte x) {
	int _t1 = ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__len_8_tab, x))));
	return _t1;
}

int math__bits__len_16(u16 x) {
	u16 y = x;
	int n = 0;
	if (y >= 256U) {
		y >>= 8U;
		n = 8;
	}
	int _t1 = n + ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__len_8_tab, y))));
	return _t1;
}

int math__bits__len_32(u32 x) {
	u32 y = x;
	int n = 0;
	if (y >= (1 << 16)) {
		y >>= 16U;
		n = 16;
	}
	if (y >= (1 << 8)) {
		y >>= 8U;
		n += 8;
	}
	int _t1 = n + ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__len_8_tab, y))));
	return _t1;
}

int math__bits__len_64(u64 x) {
	u64 y = x;
	int n = 0;
	if (y >= ((u64)(1U)) << ((u64)(32U))) {
		y >>= 32U;
		n = 32;
	}
	if (y >= ((u64)(1U)) << ((u64)(16U))) {
		y >>= 16U;
		n += 16;
	}
	if (y >= ((u64)(1U)) << ((u64)(8U))) {
		y >>= 8U;
		n += 8;
	}
	int _t1 = n + ((int)((*(byte*)/*ee elem_typ */array_get(_const_math__bits__len_8_tab, y))));
	return _t1;
}

multi_return_u32_u32 math__bits__add_32(u32 x, u32 y, u32 carry) {
	u64 sum64 = ((u64)(x)) + ((u64)(y)) + ((u64)(carry));
	u32 sum = ((u32)(sum64));
	u32 carry_out = ((u32)(sum64 >> 32U));
	return (multi_return_u32_u32){.arg0=sum, .arg1=carry_out};
}

multi_return_u64_u64 math__bits__add_64(u64 x, u64 y, u64 carry) {
	u64 sum = x + y + carry;
	u64 carry_out = ((((x & y)) | ((((x | y)) & ~sum)))) >> 63U;
	return (multi_return_u64_u64){.arg0=sum, .arg1=carry_out};
}

multi_return_u32_u32 math__bits__sub_32(u32 x, u32 y, u32 borrow) {
	u32 diff = x - y - borrow;
	u32 borrow_out = ((((~x & y)) | ((~((x ^ y)) & diff)))) >> 31U;
	return (multi_return_u32_u32){.arg0=diff, .arg1=borrow_out};
}

multi_return_u64_u64 math__bits__sub_64(u64 x, u64 y, u64 borrow) {
	u64 diff = x - y - borrow;
	u64 borrow_out = ((((~x & y)) | ((~((x ^ y)) & diff)))) >> 63U;
	return (multi_return_u64_u64){.arg0=diff, .arg1=borrow_out};
}

multi_return_u32_u32 math__bits__mul_32(u32 x, u32 y) {
	u64 tmp = ((u64)(x)) * ((u64)(y));
	u32 hi = ((u32)(tmp >> 32U));
	u32 lo = ((u32)(tmp));
	return (multi_return_u32_u32){.arg0=hi, .arg1=lo};
}

multi_return_u64_u64 math__bits__mul_64(u64 x, u64 y) {
	u64 x0 = (x & _const_math__bits__mask32);
	u64 x1 = x >> 32U;
	u64 y0 = (y & _const_math__bits__mask32);
	u64 y1 = y >> 32U;
	u64 w0 = x0 * y0;
	u64 t = x1 * y0 + (w0 >> 32U);
	u64 w1 = (t & _const_math__bits__mask32);
	u64 w2 = t >> 32U;
	w1 += x0 * y1;
	u64 hi = x1 * y1 + w2 + (w1 >> 32U);
	u64 lo = x * y;
	return (multi_return_u64_u64){.arg0=hi, .arg1=lo};
}

multi_return_u32_u32 math__bits__div_32(u32 hi, u32 lo, u32 y) {
	if (y != 0U && y <= hi) {
		Dpanic(_const_math__bits__overflow_error);
		VUNREACHABLE();
	}
	u64 z = ((((u64)(hi)) << 32U) | ((u64)(lo)));
	u32 quo = ((u32)(z / ((u64)(y))));
	u32 rem = ((u32)(z % ((u64)(y))));
	return (multi_return_u32_u32){.arg0=quo, .arg1=rem};
}

multi_return_u64_u64 math__bits__div_64(u64 hi, u64 lo, u64 y1) {
	u64 y = y1;
	if (y == 0U) {
		Dpanic(_const_math__bits__overflow_error);
		VUNREACHABLE();
	}
	if (y <= hi) {
		Dpanic(_const_math__bits__overflow_error);
		VUNREACHABLE();
	}
	u32 s = ((u32)(math__bits__leading_zeros_64(y)));
	y <<= s;
	u64 yn1 = y >> 32U;
	u64 yn0 = (y & _const_math__bits__mask32);
	u64 un32 = ((hi << s) | (lo >> (64 - s)));
	u64 un10 = lo << s;
	u64 un1 = un10 >> 32U;
	u64 un0 = (un10 & _const_math__bits__mask32);
	u64 q1 = un32 / yn1;
	u64 rhat = un32 - q1 * yn1;
	for (;;) {
		if (!(q1 >= _const_math__bits__two32 || q1 * yn0 > _const_math__bits__two32 * rhat + un1)) break;
		q1--;
		rhat += yn1;
		if (rhat >= _const_math__bits__two32) {
			break;
		}
	}
	u64 un21 = un32 * _const_math__bits__two32 + un1 - q1 * y;
	u64 q0 = un21 / yn1;
	rhat = un21 - q0 * yn1;
	for (;;) {
		if (!(q0 >= _const_math__bits__two32 || q0 * yn0 > _const_math__bits__two32 * rhat + un0)) break;
		q0--;
		rhat += yn1;
		if (rhat >= _const_math__bits__two32) {
			break;
		}
	}
	return (multi_return_u64_u64){.arg0=q1 * _const_math__bits__two32 + q0, .arg1=(un21 * _const_math__bits__two32 + un0 - q0 * y) >> s};
}

u32 math__bits__rem_32(u32 hi, u32 lo, u32 y) {
	u32 _t1 = ((u32)((((((u64)(hi)) << 32U) | ((u64)(lo)))) % ((u64)(y))));
	return _t1;
}

u64 math__bits__rem_64(u64 hi, u64 lo, u64 y) {
	multi_return_u64_u64 mr_15611 = math__bits__div_64(hi % y, lo, y);
	u64 rem = mr_15611.arg1;
	u64 _t1 = rem;
	return _t1;
}

multi_return_f64_int math__bits__normalize(f64 x) {
	f64 smallest_normal = 2.2250738585072014e-308;
	if (((x > 0.0 ? (x) : (-x))) < smallest_normal) {
		return (multi_return_f64_int){.arg0=x * (((u64)(1U)) << ((u64)(52U))), .arg1=-52};
	}
	return (multi_return_f64_int){.arg0=x, .arg1=0};
}

VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__lsr96(u32 s2, u32 s1, u32 s0) {
	u32 r0 = ((u32)(0U));
	u32 r1 = ((u32)(0U));
	u32 r2 = ((u32)(0U));
	r0 = ((s0 >> 1U) | (((s1 & ((u32)(1U)))) << 31U));
	r1 = ((s1 >> 1U) | (((s2 & ((u32)(1U)))) << 31U));
	r2 = s2 >> 1U;
	return (multi_return_u32_u32_u32){.arg0=r2, .arg1=r1, .arg2=r0};
}

VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__lsl96(u32 s2, u32 s1, u32 s0) {
	u32 r0 = ((u32)(0U));
	u32 r1 = ((u32)(0U));
	u32 r2 = ((u32)(0U));
	r2 = ((s2 << 1U) | (((s1 & (((u32)(1U)) << 31U))) >> 31U));
	r1 = ((s1 << 1U) | (((s0 & (((u32)(1U)) << 31U))) >> 31U));
	r0 = s0 << 1U;
	return (multi_return_u32_u32_u32){.arg0=r2, .arg1=r1, .arg2=r0};
}

VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__add96(u32 s2, u32 s1, u32 s0, u32 d2, u32 d1, u32 d0) {
	u64 w = ((u64)(0U));
	u32 r0 = ((u32)(0U));
	u32 r1 = ((u32)(0U));
	u32 r2 = ((u32)(0U));
	w = ((u64)(s0)) + ((u64)(d0));
	r0 = ((u32)(w));
	w >>= 32U;
	w += ((u64)(s1)) + ((u64)(d1));
	r1 = ((u32)(w));
	w >>= 32U;
	w += ((u64)(s2)) + ((u64)(d2));
	r2 = ((u32)(w));
	return (multi_return_u32_u32_u32){.arg0=r2, .arg1=r1, .arg2=r0};
}

VV_LOCAL_SYMBOL multi_return_u32_u32_u32 strconv__sub96(u32 s2, u32 s1, u32 s0, u32 d2, u32 d1, u32 d0) {
	u64 w = ((u64)(0U));
	u32 r0 = ((u32)(0U));
	u32 r1 = ((u32)(0U));
	u32 r2 = ((u32)(0U));
	w = ((u64)(s0)) - ((u64)(d0));
	r0 = ((u32)(w));
	w >>= 32U;
	w += ((u64)(s1)) - ((u64)(d1));
	r1 = ((u32)(w));
	w >>= 32U;
	w += ((u64)(s2)) - ((u64)(d2));
	r2 = ((u32)(w));
	return (multi_return_u32_u32_u32){.arg0=r2, .arg1=r1, .arg2=r0};
}

VV_LOCAL_SYMBOL bool strconv__is_digit(byte x) {
	return (x >= _const_strconv__c_zero && x <= _const_strconv__c_nine) == true;
}

VV_LOCAL_SYMBOL bool strconv__is_space(byte x) {
	return x == '\t' || x == '\n' || x == '\v' || x == '\f' || x == '\r' || x == ' ';
}

VV_LOCAL_SYMBOL bool strconv__is_exp(byte x) {
	return (x == 'E' || x == 'e') == true;
}

VV_LOCAL_SYMBOL multi_return_int_strconv__PrepNumber strconv__parser(string s) {
	int digx = 0;
	int result = _const_strconv__parser_ok;
	bool expneg = false;
	int expexp = 0;
	int i = 0;
	strconv__PrepNumber pn = (strconv__PrepNumber){.negative = 0,.exponent = 0,.mantissa = 0,};
	for (;;) {
		if (!(i < s.len && byte_is_space(string_at(s, i)))) break;
		i++;
	}
	if (string_at(s, i) == '-') {
		pn.negative = true;
		i++;
	}
	if (string_at(s, i) == '+') {
		i++;
	}
	for (;;) {
		if (!(i < s.len && byte_is_digit(string_at(s, i)))) break;
		if (digx < _const_strconv__digits) {
			pn.mantissa *= 10U;
			pn.mantissa += ((u64)(string_at(s, i) - _const_strconv__c_zero));
			digx++;
		} else if (pn.exponent < 2147483647) {
			pn.exponent++;
		}
		i++;
	}
	if ((i < s.len) && (string_at(s, i) == '.')) {
		i++;
		for (;;) {
			if (!(i < s.len && byte_is_digit(string_at(s, i)))) break;
			if (digx < _const_strconv__digits) {
				pn.mantissa *= 10U;
				pn.mantissa += ((u64)(string_at(s, i) - _const_strconv__c_zero));
				pn.exponent--;
				digx++;
			}
			i++;
		}
	}
	if ((i < s.len) && ((string_at(s, i) == 'e') || (string_at(s, i) == 'E'))) {
		i++;
		if (i < s.len) {
			if (string_at(s, i) == _const_strconv__c_plus) {
				i++;
			} else if (string_at(s, i) == _const_strconv__c_minus) {
				expneg = true;
				i++;
			}
			for (;;) {
				if (!(i < s.len && byte_is_digit(string_at(s, i)))) break;
				if (expexp < 214748364) {
					expexp *= 10;
					expexp += ((int)(string_at(s, i) - _const_strconv__c_zero));
				}
				i++;
			}
		}
	}
	if (expneg) {
		expexp = -expexp;
	}
	pn.exponent += expexp;
	if (pn.mantissa == 0U) {
		if (pn.negative) {
			result = _const_strconv__parser_mzero;
		} else {
			result = _const_strconv__parser_pzero;
		}
	} else if (pn.exponent > 309) {
		if (pn.negative) {
			result = _const_strconv__parser_minf;
		} else {
			result = _const_strconv__parser_pinf;
		}
	} else if (pn.exponent < -328) {
		if (pn.negative) {
			result = _const_strconv__parser_mzero;
		} else {
			result = _const_strconv__parser_pzero;
		}
	}
	return (multi_return_int_strconv__PrepNumber){.arg0=result, .arg1=pn};
}

VV_LOCAL_SYMBOL u64 strconv__converter(strconv__PrepNumber* pn) {
	int binexp = 92;
	u32 s2 = ((u32)(0U));
	u32 s1 = ((u32)(0U));
	u32 s0 = ((u32)(0U));
	u32 q2 = ((u32)(0U));
	u32 q1 = ((u32)(0U));
	u32 q0 = ((u32)(0U));
	u32 r2 = ((u32)(0U));
	u32 r1 = ((u32)(0U));
	u32 r0 = ((u32)(0U));
	u32 mask28 = ((u32)(((u64)(0xFU)) << 28U));
	u64 result = ((u64)(0U));
	s0 = ((u32)((pn->mantissa & ((u64)(0x00000000FFFFFFFFU)))));
	s1 = ((u32)(pn->mantissa >> 32U));
	s2 = ((u32)(0U));
	for (;;) {
		if (!(pn->exponent > 0)) break;
		multi_return_u32_u32_u32 mr_5660 = strconv__lsl96(s2, s1, s0);
		q2 = mr_5660.arg0;
		q1 = mr_5660.arg1;
		q0 = mr_5660.arg2;
		multi_return_u32_u32_u32 mr_5706 = strconv__lsl96(q2, q1, q0);
		r2 = mr_5706.arg0;
		r1 = mr_5706.arg1;
		r0 = mr_5706.arg2;
		multi_return_u32_u32_u32 mr_5762 = strconv__lsl96(r2, r1, r0);
		s2 = mr_5762.arg0;
		s1 = mr_5762.arg1;
		s0 = mr_5762.arg2;
		multi_return_u32_u32_u32 mr_5818 = strconv__add96(s2, s1, s0, q2, q1, q0);
		s2 = mr_5818.arg0;
		s1 = mr_5818.arg1;
		s0 = mr_5818.arg2;
		pn->exponent--;
		for (;;) {
			if (!(((s2 & mask28)) != 0U)) break;
			multi_return_u32_u32_u32 mr_5941 = strconv__lsr96(s2, s1, s0);
			q2 = mr_5941.arg0;
			q1 = mr_5941.arg1;
			q0 = mr_5941.arg2;
			binexp++;
			s2 = q2;
			s1 = q1;
			s0 = q0;
		}
	}
	for (;;) {
		if (!(pn->exponent < 0)) break;
		for (;;) {
			if (!(!(((s2 & (((u32)(1U)) << 31U))) != 0U))) break;
			multi_return_u32_u32_u32 mr_6088 = strconv__lsl96(s2, s1, s0);
			q2 = mr_6088.arg0;
			q1 = mr_6088.arg1;
			q0 = mr_6088.arg2;
			binexp--;
			s2 = q2;
			s1 = q1;
			s0 = q0;
		}
		q2 = s2 / _const_strconv__c_ten;
		r1 = s2 % _const_strconv__c_ten;
		r2 = ((s1 >> 8U) | (r1 << 24U));
		q1 = r2 / _const_strconv__c_ten;
		r1 = r2 % _const_strconv__c_ten;
		r2 = (((((s1 & ((u32)(0xFFU)))) << 16U) | (s0 >> 16U)) | (r1 << 24U));
		r0 = r2 / _const_strconv__c_ten;
		r1 = r2 % _const_strconv__c_ten;
		q1 = ((q1 << 8U) | (((r0 & ((u32)(0x00FF0000U)))) >> 16U));
		q0 = r0 << 16U;
		r2 = (((s0 & ((u32)(0xFFFFU)))) | (r1 << 16U));
		q0 |= r2 / _const_strconv__c_ten;
		s2 = q2;
		s1 = q1;
		s0 = q0;
		pn->exponent++;
	}
	if (s2 != 0U || s1 != 0U || s0 != 0U) {
		for (;;) {
			if (!(((s2 & mask28)) == 0U)) break;
			multi_return_u32_u32_u32 mr_6823 = strconv__lsl96(s2, s1, s0);
			q2 = mr_6823.arg0;
			q1 = mr_6823.arg1;
			q0 = mr_6823.arg2;
			binexp--;
			s2 = q2;
			s1 = q1;
			s0 = q0;
		}
	}
	int nbit = 7;
	u32 check_round_bit = ((u32)(1U)) << ((u32)(nbit));
	u32 check_round_mask = ((u32)(0xFFFFFFFFU)) << ((u32)(nbit));
	if (((s1 & check_round_bit)) != 0U) {
		if (((s1 & ~check_round_mask)) != 0U) {
			multi_return_u32_u32_u32 mr_7905 = strconv__add96(s2, s1, s0, 0U, check_round_bit, 0U);
			s2 = mr_7905.arg0;
			s1 = mr_7905.arg1;
			s0 = mr_7905.arg2;
		} else {
			if (((s1 & (check_round_bit << ((u32)(1U))))) != 0U) {
				multi_return_u32_u32_u32 mr_8097 = strconv__add96(s2, s1, s0, 0U, check_round_bit, 0U);
				s2 = mr_8097.arg0;
				s1 = mr_8097.arg1;
				s0 = mr_8097.arg2;
			}
		}
		s1 = (s1 & check_round_mask);
		s0 = ((u32)(0U));
		if ((s2 & (mask28 << ((u32)(1U)))) != 0U) {
			multi_return_u32_u32_u32 mr_8301 = strconv__lsr96(s2, s1, s0);
			q2 = mr_8301.arg0;
			q1 = mr_8301.arg1;
			q0 = mr_8301.arg2;
			binexp--;
			s2 = q2;
			s1 = q1;
			s0 = q0;
		}
	}
	binexp += 1023;
	if (binexp > 2046) {
		if (pn->negative) {
			result = _const_strconv__double_minus_infinity;
		} else {
			result = _const_strconv__double_plus_infinity;
		}
	} else if (binexp < 1) {
		if (pn->negative) {
			result = _const_strconv__double_minus_zero;
		} else {
			result = _const_strconv__double_plus_zero;
		}
	} else if (s2 != 0U) {
		u64 q = ((u64)(0U));
		u64 binexs2 = ((u64)(binexp)) << 52U;
		q = (((((u64)((s2 & ~mask28))) << 24U) | ((((u64)(s1)) + ((u64)(128U))) >> 8U)) | binexs2);
		if (pn->negative) {
			q |= (((u64)(1U)) << 63U);
		}
		result = q;
	}
	return result;
}

f64 strconv__atof64(string s) {
	strconv__PrepNumber pn = (strconv__PrepNumber){.negative = 0,.exponent = 0,.mantissa = 0,};
	int res_parsing = 0;
	strconv__Float64u res = (strconv__Float64u){0};
	multi_return_int_strconv__PrepNumber mr_9336 = strconv__parser(s);
	res_parsing = mr_9336.arg0;
	pn = mr_9336.arg1;

	if (res_parsing == (_const_strconv__parser_ok)) {
		res.u = strconv__converter((voidptr)&/*qq*/pn);
	}
	else if (res_parsing == (_const_strconv__parser_pzero)) {
		res.u = _const_strconv__double_plus_zero;
	}
	else if (res_parsing == (_const_strconv__parser_mzero)) {
		res.u = _const_strconv__double_minus_zero;
	}
	else if (res_parsing == (_const_strconv__parser_pinf)) {
		res.u = _const_strconv__double_plus_infinity;
	}
	else if (res_parsing == (_const_strconv__parser_minf)) {
		res.u = _const_strconv__double_minus_infinity;
	}
	else {
	};
	return res.f;
}

f64 strconv__atof_quick(string s) {
	strconv__Float64u f = (strconv__Float64u){0};
	f64 sign = ((f64)(1.0));
	int i = 0;
	for (;;) {
		if (!(i < s.len && string_at(s, i) == ' ')) break;
		i++;
	}
	if (i < s.len) {
		if (string_at(s, i) == '-') {
			sign = -1.0;
			i++;
		} else if (string_at(s, i) == '+') {
			i++;
		}
	}
	if (string_at(s, i) == 'i' && i + 2 < s.len && string_at(s, i + 1) == 'n' && string_at(s, i + 2) == 'f') {
		if (sign > 0.0) {
			f.u = _const_strconv__double_plus_infinity;
		} else {
			f.u = _const_strconv__double_minus_infinity;
		}
		return f.f;
	}
	for (;;) {
		if (!(i < s.len && string_at(s, i) == '0')) break;
		i++;
		if (i >= s.len) {
			if (sign > 0.0) {
				f.u = _const_strconv__double_plus_zero;
			} else {
				f.u = _const_strconv__double_minus_zero;
			}
			return f.f;
		}
	}
	for (;;) {
		if (!(i < s.len && (string_at(s, i) >= '0' && string_at(s, i) <= '9'))) break;
		f.f *= ((f64)(10.0));
		f.f += ((f64)(string_at(s, i) - '0'));
		i++;
	}
	if (i < s.len && string_at(s, i) == '.') {
		i++;
		f64 frac_mul = ((f64)(0.1));
		for (;;) {
			if (!(i < s.len && (string_at(s, i) >= '0' && string_at(s, i) <= '9'))) break;
			f.f += ((f64)(string_at(s, i) - '0')) * frac_mul;
			frac_mul *= ((f64)(0.1));
			i++;
		}
	}
	if (i < s.len && (string_at(s, i) == 'e' || string_at(s, i) == 'E')) {
		i++;
		int exp = 0;
		int exp_sign = 1;
		if (i < s.len) {
			if (string_at(s, i) == '-') {
				exp_sign = -1;
				i++;
			} else if (string_at(s, i) == '+') {
				i++;
			}
		}
		for (;;) {
			if (!(i < s.len && string_at(s, i) == '0')) break;
			i++;
		}
		for (;;) {
			if (!(i < s.len && (string_at(s, i) >= '0' && string_at(s, i) <= '9'))) break;
			exp *= 10;
			exp += ((int)(string_at(s, i) - '0'));
			i++;
		}
		if (exp_sign == 1) {
			if (exp > _const_strconv__pos_exp.len) {
				if (sign > 0) {
					f.u = _const_strconv__double_plus_infinity;
				} else {
					f.u = _const_strconv__double_minus_infinity;
				}
				return f.f;
			}
			strconv__Float64u tmp_mul = (strconv__Float64u){.u = (*(u64*)/*ee elem_typ */array_get(_const_strconv__pos_exp, exp)),};
			f.f = f.f * tmp_mul.f;
		} else {
			if (exp > _const_strconv__neg_exp.len) {
				if (sign > 0) {
					f.u = _const_strconv__double_plus_zero;
				} else {
					f.u = _const_strconv__double_minus_zero;
				}
				return f.f;
			}
			strconv__Float64u tmp_mul = (strconv__Float64u){.u = (*(u64*)/*ee elem_typ */array_get(_const_strconv__neg_exp, exp)),};
			f.f = f.f * tmp_mul.f;
		}
	}
	{ // Unsafe block
		f.f = f.f * sign;
		return f.f;
	}
	return 0;
}

byte strconv__byte_to_lower(byte c) {
	return (c | ('x' - 'X'));
}

Option_u64 strconv__common_parse_uint(string s, int _base, int _bit_size, bool error_on_non_digit, bool error_on_high_digit) {
	multi_return_u64_int mr_824 = strconv__common_parse_uint2(s, _base, _bit_size);
	u64 result = mr_824.arg0;
	int err = mr_824.arg1;
	if (err != 0 && (error_on_non_digit || error_on_high_digit)) {

		if (err == (-1)) {
			return (Option_u64){ .state=2, .err=Derror( str_intp(3, _MOV((StrIntpData[]){{_SLIT("common_parse_uint: wrong base "), 0xfe07, {.d_i32 = _base}}, {_SLIT(" for "), 0xfe10, {.d_s = s}}, {_SLIT0, 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
		}
		else if (err == (-2)) {
			return (Option_u64){ .state=2, .err=Derror( str_intp(3, _MOV((StrIntpData[]){{_SLIT("common_parse_uint: wrong bit size "), 0xfe07, {.d_i32 = _bit_size}}, {_SLIT(" for "), 0xfe10, {.d_s = s}}, {_SLIT0, 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
		}
		else if (err == (-3)) {
			return (Option_u64){ .state=2, .err=Derror( str_intp(2, _MOV((StrIntpData[]){{_SLIT("common_parse_uint: integer overflow "), 0xfe10, {.d_s = s}}, {_SLIT0, 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
		}
		else {
			return (Option_u64){ .state=2, .err=Derror( str_intp(2, _MOV((StrIntpData[]){{_SLIT("common_parse_uint: syntax error "), 0xfe10, {.d_s = s}}, {_SLIT0, 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
		};
	}
	Option_u64 _t5;
	opt_ok(&(u64[]) { result }, (Option*)(&_t5), sizeof(u64));
	return _t5;
}

multi_return_u64_int strconv__common_parse_uint2(string s, int _base, int _bit_size) {
	int bit_size = _bit_size;
	int base = _base;
	if (s.len < 1 || !strconv__underscore_ok(s)) {
		return (multi_return_u64_int){.arg0=((u64)(0U)), .arg1=1};
	}
	bool base0 = base == 0;
	int start_index = 0;
	if (2 <= base && base <= 36) {
	} else if (base == 0) {
		base = 10;
		if (string_at(s, 0) == '0') {
			if (s.len >= 3 && strconv__byte_to_lower(string_at(s, 1)) == 'b') {
				base = 2;
				start_index += 2;
			} else if (s.len >= 3 && strconv__byte_to_lower(string_at(s, 1)) == 'o') {
				base = 8;
				start_index += 2;
			} else if (s.len >= 3 && strconv__byte_to_lower(string_at(s, 1)) == 'x') {
				base = 16;
				start_index += 2;
			} else if (s.len >= 2 && (string_at(s, 1) >= '0' && string_at(s, 1) <= '9')) {
				base = 10;
				start_index++;
			} else {
				base = 8;
				start_index++;
			}
		}
	} else {
		return (multi_return_u64_int){.arg0=((u64)(0U)), .arg1=-1};
	}
	if (bit_size == 0) {
		bit_size = _const_strconv__int_size;
	} else if (bit_size < 0 || bit_size > 64) {
		return (multi_return_u64_int){.arg0=((u64)(0U)), .arg1=-2};
	}
	u64 cutoff = _const_strconv__max_u64 / ((u64)(base)) + ((u64)(1U));
	u64 max_val = (bit_size == 64 ? (_const_strconv__max_u64) : ((((u64)(1U)) << ((u64)(bit_size))) - ((u64)(1U))));
	u64 n = ((u64)(0U));
	for (int i = start_index; i < s.len; ++i) {
		byte c = string_at(s, i);
		byte cl = strconv__byte_to_lower(c);
		byte d = ((byte)(0));
		if (c == '_' && base0) {
			continue;
		} else if ('0' <= c && c <= '9') {
			d = c - '0';
		} else if ('a' <= cl && cl <= 'z') {
			d = cl - 'a' + 10;
		} else {
			return (multi_return_u64_int){.arg0=n, .arg1=i + 1};
		}
		if (d >= ((byte)(base))) {
			return (multi_return_u64_int){.arg0=n, .arg1=i + 1};
		}
		if (n >= cutoff) {
			return (multi_return_u64_int){.arg0=max_val, .arg1=-3};
		}
		n *= ((u64)(base));
		u64 n1 = n + ((u64)(d));
		if (n1 < n || n1 > max_val) {
			return (multi_return_u64_int){.arg0=max_val, .arg1=-3};
		}
		n = n1;
	}
	return (multi_return_u64_int){.arg0=n, .arg1=0};
}

Option_u64 strconv__parse_uint(string s, int _base, int _bit_size) {
	return strconv__common_parse_uint(s, _base, _bit_size, true, true);
}

Option_i64 strconv__common_parse_int(string _s, int base, int _bit_size, bool error_on_non_digit, bool error_on_high_digit) {
	string s = _s;
	int bit_size = _bit_size;
	if (s.len < 1) {
		Option_i64 _t1;
		opt_ok(&(i64[]) { ((i64)(0)) }, (Option*)(&_t1), sizeof(i64));
		return _t1;
	}
	bool neg = false;
	if (string_at(s, 0) == '+') {
		s = string_substr(s, 1, s.len);
	} else if (string_at(s, 0) == '-') {
		neg = true;
		s = string_substr(s, 1, s.len);
	}
	Option_u64 _t2 = strconv__common_parse_uint(s, base, bit_size, error_on_non_digit, error_on_high_digit);
	if (_t2.state != 0) { /*or block*/ 
		Option_i64 _t3;
		memcpy(&_t3, &_t2, sizeof(Option));
		return _t3;
	}
	
 	u64 un =  (*(u64*)_t2.data);
	if (un == 0U) {
		Option_i64 _t4;
		opt_ok(&(i64[]) { ((i64)(0)) }, (Option*)(&_t4), sizeof(i64));
		return _t4;
	}
	if (bit_size == 0) {
		bit_size = _const_strconv__int_size;
	}
	u64 cutoff = ((u64)(1U)) << ((u64)(bit_size - 1));
	if (!neg && un >= cutoff) {
		Option_i64 _t5;
		opt_ok(&(i64[]) { ((i64)(cutoff - ((u64)(1U)))) }, (Option*)(&_t5), sizeof(i64));
		return _t5;
	}
	if (neg && un > cutoff) {
		Option_i64 _t6;
		opt_ok(&(i64[]) { -((i64)(cutoff)) }, (Option*)(&_t6), sizeof(i64));
		return _t6;
	}
	Option_i64 _t8; /* if prepend */
	if (neg) {
		opt_ok(&(i64[]) { -((i64)(un)) }, (Option*)(&_t8), sizeof(i64));
	} else {
		opt_ok(&(i64[]) { ((i64)(un)) }, (Option*)(&_t8), sizeof(i64));
	}
	return  _t8;
}

Option_i64 strconv__parse_int(string _s, int base, int _bit_size) {
	return strconv__common_parse_int(_s, base, _bit_size, true, true);
}

Option_int strconv__atoi(string s) {
	if ((s).len == 0) {
		return (Option_int){ .state=2, .err=Derror( str_intp(2, _MOV((StrIntpData[]){{_SLIT("strconv.atoi: parsing \""), 0xfe10, {.d_s = s}}, {_SLIT("\": invalid syntax "), 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
	}
	if ((_const_strconv__int_size == 32 && (0 < s.len && s.len < 10)) || (_const_strconv__int_size == 64 && (0 < s.len && s.len < 19))) {
		int start_idx = 0;
		if (string_at(s, 0) == '-' || string_at(s, 0) == '+') {
			start_idx++;
			if (s.len - start_idx < 1) {
				return (Option_int){ .state=2, .err=Derror( str_intp(2, _MOV((StrIntpData[]){{_SLIT("strconv.atoi: parsing \""), 0xfe10, {.d_s = s}}, {_SLIT("\": invalid syntax "), 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
			}
		}
		int n = 0;
		for (int i = start_idx; i < s.len; ++i) {
			rune ch = string_at(s, i) - '0';
			if (ch > 9) {
				return (Option_int){ .state=2, .err=Derror( str_intp(2, _MOV((StrIntpData[]){{_SLIT("strconv.atoi: parsing \""), 0xfe10, {.d_s = s}}, {_SLIT("\": invalid syntax "), 0, { .d_c = 0 }}}))), .data={EMPTY_STRUCT_INITIALIZATION} };
			}
			n = n * 10 + ((int)(ch));
		}
		Option_int _t5; /* if prepend */
		if (string_at(s, 0) == '-') {
			opt_ok(&(int[]) { -n }, (Option*)(&_t5), sizeof(int));
		} else {
			opt_ok(&(int[]) { n }, (Option*)(&_t5), sizeof(int));
		}
		return  _t5;
	}
	Option_i64 _t6 = strconv__parse_int(s, 10, 0);
	if (_t6.state != 0) { /*or block*/ 
		Option_int _t7;
		memcpy(&_t7, &_t6, sizeof(Option));
		return _t7;
	}
	
 	i64 int64 =  (*(i64*)_t6.data);
	Option_int _t8;
	opt_ok(&(int[]) { ((int)(int64)) }, (Option*)(&_t8), sizeof(int));
	return _t8;
}

VV_LOCAL_SYMBOL bool strconv__underscore_ok(string s) {
	rune saw = '^';
	int i = 0;
	if (s.len >= 1 && (string_at(s, 0) == '-' || string_at(s, 0) == '+')) {
		i++;
	}
	bool hex = false;
	if (s.len - i >= 2 && string_at(s, i) == '0' && (strconv__byte_to_lower(string_at(s, i + 1)) == 'b' || strconv__byte_to_lower(string_at(s, i + 1)) == 'o' || strconv__byte_to_lower(string_at(s, i + 1)) == 'x')) {
		saw = '0';
		hex = strconv__byte_to_lower(string_at(s, i + 1)) == 'x';
		i += 2;
	}
	for (; i < s.len; i++) {
		if (('0' <= string_at(s, i) && string_at(s, i) <= '9') || (hex && 'a' <= strconv__byte_to_lower(string_at(s, i)) && strconv__byte_to_lower(string_at(s, i)) <= 'f')) {
			saw = '0';
			continue;
		}
		if (string_at(s, i) == '_') {
			if (saw != '0') {
				return false;
			}
			saw = '_';
			continue;
		}
		if (saw == '_') {
			return false;
		}
		saw = '!';
	}
	return saw != '_';
}

// Attr: [direct_array_access]
string strconv__Dec32_get_string_32(strconv__Dec32 d, bool neg, int i_n_digit, int i_pad_digit) {
	int n_digit = i_n_digit + 1;
	int pad_digit = i_pad_digit + 1;
	u32 out = d.m;
	int out_len = strconv__dec_digits(out);
	int out_len_original = out_len;
	int fw_zeros = 0;
	if (pad_digit > out_len) {
		fw_zeros = pad_digit - out_len;
	}
	Array_byte buf = __new_array_with_default(((int)(out_len + 5 + 1 + 1)), 0, sizeof(byte), 0);
	int i = 0;
	if (neg) {
		if (buf.data != 0) {
			((byte*)buf.data)[i] = '-';
		}
		i++;
	}
	int disp = 0;
	if (out_len <= 1) {
		disp = 1;
	}
	if (n_digit < out_len) {
		out += ((u32*)_const_strconv__ten_pow_table_32.data)[out_len - n_digit - 1] * 5U;
		out /= ((u32*)_const_strconv__ten_pow_table_32.data)[out_len - n_digit];
		out_len = n_digit;
	}
	int y = i + out_len;
	int x = 0;
	for (;;) {
		if (!(x < (out_len - disp - 1))) break;
		((byte*)buf.data)[y - x] = '0' + ((byte)(out % 10U));
		out /= 10U;
		i++;
		x++;
	}
	if (i_n_digit == 0) {
		{ // Unsafe block
			((byte*)buf.data)[i] = 0;
			return tos(((byte*)(&((byte*)buf.data)[0])), i);
		}
	}
	if (out_len >= 1) {
		((byte*)buf.data)[y - x] = '.';
		x++;
		i++;
	}
	if (y - x >= 0) {
		((byte*)buf.data)[y - x] = '0' + ((byte)(out % 10U));
		i++;
	}
	for (;;) {
		if (!(fw_zeros > 0)) break;
		((byte*)buf.data)[i] = '0';
		i++;
		fw_zeros--;
	}
	((byte*)buf.data)[i] = 'e';
	i++;
	int exp = d.e + out_len_original - 1;
	if (exp < 0) {
		((byte*)buf.data)[i] = '-';
		i++;
		exp = -exp;
	} else {
		((byte*)buf.data)[i] = '+';
		i++;
	}
	int d1 = exp % 10;
	int d0 = exp / 10;
	((byte*)buf.data)[i] = '0' + ((byte)(d0));
	i++;
	((byte*)buf.data)[i] = '0' + ((byte)(d1));
	i++;
	((byte*)buf.data)[i] = 0;
	return tos(((byte*)(&((byte*)buf.data)[0])), i);
}

VV_LOCAL_SYMBOL multi_return_strconv__Dec32_bool strconv__f32_to_decimal_exact_int(u32 i_mant, u32 exp) {
	strconv__Dec32 d = (strconv__Dec32){.m = 0,.e = 0,};
	u32 e = exp - _const_strconv__bias32;
	if (e > _const_strconv__mantbits32) {
		return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=false};
	}
	u32 shift = _const_strconv__mantbits32 - e;
	u32 mant = (i_mant | 0x00800000U);
	d.m = mant >> shift;
	if ((d.m << shift) != mant) {
		return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=false};
	}
	for (;;) {
		if (!((d.m % 10U) == 0U)) break;
		d.m /= 10U;
		d.e++;
	}
	return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=true};
}

VV_LOCAL_SYMBOL strconv__Dec32 strconv__f32_to_decimal(u32 mant, u32 exp) {
	int e2 = 0;
	u32 m2 = ((u32)(0U));
	if (exp == 0U) {
		e2 = 1 - _const_strconv__bias32 - ((int)(_const_strconv__mantbits32)) - 2;
		m2 = mant;
	} else {
		e2 = ((int)(exp)) - _const_strconv__bias32 - ((int)(_const_strconv__mantbits32)) - 2;
		m2 = ((((u32)(1U)) << _const_strconv__mantbits32) | mant);
	}
	bool even = ((m2 & 1U)) == 0U;
	bool accept_bounds = even;
	u32 mv = ((u32)(4 * m2));
	u32 mp = ((u32)(4 * m2 + 2U));
	u32 mm_shift = strconv__bool_to_u32(mant != 0U || exp <= 1U);
	u32 mm = ((u32)(4 * m2 - 1U - mm_shift));
	u32 vr = ((u32)(0U));
	u32 vp = ((u32)(0U));
	u32 vm = ((u32)(0U));
	int e10 = 0;
	bool vm_is_trailing_zeros = false;
	bool vr_is_trailing_zeros = false;
	byte last_removed_digit = ((byte)(0));
	if (e2 >= 0) {
		u32 q = strconv__log10_pow2(e2);
		e10 = ((int)(q));
		int k = _const_strconv__pow5_inv_num_bits_32 + strconv__pow5_bits(((int)(q))) - 1;
		int i = -e2 + ((int)(q)) + k;
		vr = strconv__mul_pow5_invdiv_pow2(mv, q, i);
		vp = strconv__mul_pow5_invdiv_pow2(mp, q, i);
		vm = strconv__mul_pow5_invdiv_pow2(mm, q, i);
		if (q != 0U && (vp - 1U) / 10U <= vm / 10U) {
			int l = _const_strconv__pow5_inv_num_bits_32 + strconv__pow5_bits(((int)(q - 1U))) - 1;
			last_removed_digit = ((byte)(strconv__mul_pow5_invdiv_pow2(mv, q - 1U, -e2 + ((int)(q - 1U)) + l) % 10U));
		}
		if (q <= 9U) {
			if (mv % 5U == 0U) {
				vr_is_trailing_zeros = strconv__multiple_of_power_of_five_32(mv, q);
			} else if (accept_bounds) {
				vm_is_trailing_zeros = strconv__multiple_of_power_of_five_32(mm, q);
			} else if (strconv__multiple_of_power_of_five_32(mp, q)) {
				vp--;
			}
		}
	} else {
		u32 q = strconv__log10_pow5(-e2);
		e10 = ((int)(q)) + e2;
		int i = -e2 - ((int)(q));
		int k = strconv__pow5_bits(i) - _const_strconv__pow5_num_bits_32;
		int j = ((int)(q)) - k;
		vr = strconv__mul_pow5_div_pow2(mv, ((u32)(i)), j);
		vp = strconv__mul_pow5_div_pow2(mp, ((u32)(i)), j);
		vm = strconv__mul_pow5_div_pow2(mm, ((u32)(i)), j);
		if (q != 0U && ((vp - 1U) / 10U) <= vm / 10U) {
			j = ((int)(q)) - 1 - (strconv__pow5_bits(i + 1) - _const_strconv__pow5_num_bits_32);
			last_removed_digit = ((byte)(strconv__mul_pow5_div_pow2(mv, ((u32)(i + 1)), j) % 10U));
		}
		if (q <= 1U) {
			vr_is_trailing_zeros = true;
			if (accept_bounds) {
				vm_is_trailing_zeros = mm_shift == 1U;
			} else {
				vp--;
			}
		} else if (q < 31U) {
			vr_is_trailing_zeros = strconv__multiple_of_power_of_two_32(mv, q - 1U);
		}
	}
	int removed = 0;
	u32 out = ((u32)(0U));
	if (vm_is_trailing_zeros || vr_is_trailing_zeros) {
		for (;;) {
			if (!(vp / 10U > vm / 10U)) break;
			vm_is_trailing_zeros = vm_is_trailing_zeros && (vm % 10U) == 0U;
			vr_is_trailing_zeros = vr_is_trailing_zeros && (last_removed_digit == 0);
			last_removed_digit = ((byte)(vr % 10U));
			vr /= 10U;
			vp /= 10U;
			vm /= 10U;
			removed++;
		}
		if (vm_is_trailing_zeros) {
			for (;;) {
				if (!(vm % 10U == 0U)) break;
				vr_is_trailing_zeros = vr_is_trailing_zeros && (last_removed_digit == 0);
				last_removed_digit = ((byte)(vr % 10U));
				vr /= 10U;
				vp /= 10U;
				vm /= 10U;
				removed++;
			}
		}
		if (vr_is_trailing_zeros && (last_removed_digit == 5) && (vr % 2U) == 0U) {
			last_removed_digit = 4;
		}
		out = vr;
		if ((vr == vm && (!accept_bounds || !vm_is_trailing_zeros)) || last_removed_digit >= 5) {
			out++;
		}
	} else {
		for (;;) {
			if (!(vp / 10U > vm / 10U)) break;
			last_removed_digit = ((byte)(vr % 10U));
			vr /= 10U;
			vp /= 10U;
			vm /= 10U;
			removed++;
		}
		out = vr + strconv__bool_to_u32(vr == vm || last_removed_digit >= 5);
	}
	return (strconv__Dec32){.m = out,.e = e10 + removed,};
}

string strconv__f32_to_str(f32 f, int n_digit) {
	strconv__Uf32 u1 = (strconv__Uf32){0};
	u1.f = f;
	u32 u = u1.u;
	bool neg = (u >> (_const_strconv__mantbits32 + _const_strconv__expbits32)) != 0U;
	u32 mant = (u & ((((u32)(1U)) << _const_strconv__mantbits32) - ((u32)(1U))));
	u32 exp = ((u >> _const_strconv__mantbits32) & ((((u32)(1U)) << _const_strconv__expbits32) - ((u32)(1U))));
	if ((exp == _const_strconv__maxexp32) || (exp == 0U && mant == 0U)) {
		return strconv__get_string_special(neg, exp == 0U, mant == 0U);
	}
	multi_return_strconv__Dec32_bool mr_8773 = strconv__f32_to_decimal_exact_int(mant, exp);
	strconv__Dec32 d = mr_8773.arg0;
	bool ok = mr_8773.arg1;
	if (!ok) {
		d = strconv__f32_to_decimal(mant, exp);
	}
	return strconv__Dec32_get_string_32(d, neg, n_digit, 0);
}

string strconv__f32_to_str_pad(f32 f, int n_digit) {
	strconv__Uf32 u1 = (strconv__Uf32){0};
	u1.f = f;
	u32 u = u1.u;
	bool neg = (u >> (_const_strconv__mantbits32 + _const_strconv__expbits32)) != 0U;
	u32 mant = (u & ((((u32)(1U)) << _const_strconv__mantbits32) - ((u32)(1U))));
	u32 exp = ((u >> _const_strconv__mantbits32) & ((((u32)(1U)) << _const_strconv__expbits32) - ((u32)(1U))));
	if ((exp == _const_strconv__maxexp32) || (exp == 0U && mant == 0U)) {
		return strconv__get_string_special(neg, exp == 0U, mant == 0U);
	}
	multi_return_strconv__Dec32_bool mr_9547 = strconv__f32_to_decimal_exact_int(mant, exp);
	strconv__Dec32 d = mr_9547.arg0;
	bool ok = mr_9547.arg1;
	if (!ok) {
		d = strconv__f32_to_decimal(mant, exp);
	}
	return strconv__Dec32_get_string_32(d, neg, n_digit, n_digit);
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL string strconv__Dec64_get_string_64(strconv__Dec64 d, bool neg, int i_n_digit, int i_pad_digit) {
	int n_digit = i_n_digit + 1;
	int pad_digit = i_pad_digit + 1;
	u64 out = d.m;
	int d_exp = d.e;
	int out_len = strconv__dec_digits(out);
	int out_len_original = out_len;
	int fw_zeros = 0;
	if (pad_digit > out_len) {
		fw_zeros = pad_digit - out_len;
	}
	Array_byte buf = __new_array_with_default((out_len + 6 + 1 + 1 + fw_zeros), 0, sizeof(byte), 0);
	int i = 0;
	if (neg) {
		((byte*)buf.data)[i] = '-';
		i++;
	}
	int disp = 0;
	if (out_len <= 1) {
		disp = 1;
	}
	if (n_digit < out_len) {
		out += ((u64*)_const_strconv__ten_pow_table_64.data)[out_len - n_digit - 1] * 5U;
		out /= ((u64*)_const_strconv__ten_pow_table_64.data)[out_len - n_digit];
		if (d.m / ((u64*)_const_strconv__ten_pow_table_64.data)[out_len - n_digit] < out) {
			d_exp++;
			n_digit++;
		}
		out_len = n_digit;
	}
	int y = i + out_len;
	int x = 0;
	for (;;) {
		if (!(x < (out_len - disp - 1))) break;
		((byte*)buf.data)[y - x] = '0' + ((byte)(out % 10U));
		out /= 10U;
		i++;
		x++;
	}
	if (i_n_digit == 0) {
		{ // Unsafe block
			((byte*)buf.data)[i] = 0;
			return tos(((byte*)(&((byte*)buf.data)[0])), i);
		}
	}
	if (out_len >= 1) {
		((byte*)buf.data)[y - x] = '.';
		x++;
		i++;
	}
	if (y - x >= 0) {
		((byte*)buf.data)[y - x] = '0' + ((byte)(out % 10U));
		i++;
	}
	for (;;) {
		if (!(fw_zeros > 0)) break;
		((byte*)buf.data)[i] = '0';
		i++;
		fw_zeros--;
	}
	((byte*)buf.data)[i] = 'e';
	i++;
	int exp = d_exp + out_len_original - 1;
	if (exp < 0) {
		((byte*)buf.data)[i] = '-';
		i++;
		exp = -exp;
	} else {
		((byte*)buf.data)[i] = '+';
		i++;
	}
	int d2 = exp % 10;
	exp /= 10;
	int d1 = exp % 10;
	int d0 = exp / 10;
	if (d0 > 0) {
		((byte*)buf.data)[i] = '0' + ((byte)(d0));
		i++;
	}
	((byte*)buf.data)[i] = '0' + ((byte)(d1));
	i++;
	((byte*)buf.data)[i] = '0' + ((byte)(d2));
	i++;
	((byte*)buf.data)[i] = 0;
	return tos(((byte*)(&((byte*)buf.data)[0])), i);
}

VV_LOCAL_SYMBOL multi_return_strconv__Dec64_bool strconv__f64_to_decimal_exact_int(u64 i_mant, u64 exp) {
	strconv__Dec64 d = (strconv__Dec64){.m = 0,.e = 0,};
	u64 e = exp - _const_strconv__bias64;
	if (e > _const_strconv__mantbits64) {
		return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=false};
	}
	u64 shift = _const_strconv__mantbits64 - e;
	u64 mant = (i_mant | ((u64)(0x0010000000000000U)));
	d.m = mant >> shift;
	if ((d.m << shift) != mant) {
		return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=false};
	}
	for (;;) {
		if (!((d.m % 10U) == 0U)) break;
		d.m /= 10U;
		d.e++;
	}
	return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=true};
}

VV_LOCAL_SYMBOL strconv__Dec64 strconv__f64_to_decimal(u64 mant, u64 exp) {
	int e2 = 0;
	u64 m2 = ((u64)(0U));
	if (exp == 0U) {
		e2 = 1 - _const_strconv__bias64 - ((int)(_const_strconv__mantbits64)) - 2;
		m2 = mant;
	} else {
		e2 = ((int)(exp)) - _const_strconv__bias64 - ((int)(_const_strconv__mantbits64)) - 2;
		m2 = ((((u64)(1U)) << _const_strconv__mantbits64) | mant);
	}
	bool even = ((m2 & 1U)) == 0U;
	bool accept_bounds = even;
	u64 mv = ((u64)(4 * m2));
	u64 mm_shift = strconv__bool_to_u64(mant != 0U || exp <= 1U);
	u64 vr = ((u64)(0U));
	u64 vp = ((u64)(0U));
	u64 vm = ((u64)(0U));
	int e10 = 0;
	bool vm_is_trailing_zeros = false;
	bool vr_is_trailing_zeros = false;
	if (e2 >= 0) {
		u32 q = strconv__log10_pow2(e2) - strconv__bool_to_u32(e2 > 3);
		e10 = ((int)(q));
		int k = _const_strconv__pow5_inv_num_bits_64 + strconv__pow5_bits(((int)(q))) - 1;
		int i = -e2 + ((int)(q)) + k;
		strconv__Uint128 mul = (*(strconv__Uint128*)/*ee elem_typ */array_get(_const_strconv__pow5_inv_split_64, q));
		vr = strconv__mul_shift_64(((u64)(4U)) * m2, mul, i);
		vp = strconv__mul_shift_64(((u64)(4U)) * m2 + ((u64)(2U)), mul, i);
		vm = strconv__mul_shift_64(((u64)(4U)) * m2 - ((u64)(1U)) - mm_shift, mul, i);
		if (q <= 21U) {
			if (mv % 5U == 0U) {
				vr_is_trailing_zeros = strconv__multiple_of_power_of_five_64(mv, q);
			} else if (accept_bounds) {
				vm_is_trailing_zeros = strconv__multiple_of_power_of_five_64(mv - 1U - mm_shift, q);
			} else if (strconv__multiple_of_power_of_five_64(mv + 2U, q)) {
				vp--;
			}
		}
	} else {
		u32 q = strconv__log10_pow5(-e2) - strconv__bool_to_u32(-e2 > 1);
		e10 = ((int)(q)) + e2;
		int i = -e2 - ((int)(q));
		int k = strconv__pow5_bits(i) - _const_strconv__pow5_num_bits_64;
		int j = ((int)(q)) - k;
		strconv__Uint128 mul = (*(strconv__Uint128*)/*ee elem_typ */array_get(_const_strconv__pow5_split_64, i));
		vr = strconv__mul_shift_64(((u64)(4U)) * m2, mul, j);
		vp = strconv__mul_shift_64(((u64)(4U)) * m2 + ((u64)(2U)), mul, j);
		vm = strconv__mul_shift_64(((u64)(4U)) * m2 - ((u64)(1U)) - mm_shift, mul, j);
		if (q <= 1U) {
			vr_is_trailing_zeros = true;
			if (accept_bounds) {
				vm_is_trailing_zeros = (mm_shift == 1U);
			} else {
				vp--;
			}
		} else if (q < 63U) {
			vr_is_trailing_zeros = strconv__multiple_of_power_of_two_64(mv, q - 1U);
		}
	}
	int removed = 0;
	byte last_removed_digit = ((byte)(0));
	u64 out = ((u64)(0U));
	if (vm_is_trailing_zeros || vr_is_trailing_zeros) {
		for (;;) {
			u64 vp_div_10 = vp / 10U;
			u64 vm_div_10 = vm / 10U;
			if (vp_div_10 <= vm_div_10) {
				break;
			}
			u64 vm_mod_10 = vm % 10U;
			u64 vr_div_10 = vr / 10U;
			u64 vr_mod_10 = vr % 10U;
			vm_is_trailing_zeros = vm_is_trailing_zeros && vm_mod_10 == 0U;
			vr_is_trailing_zeros = vr_is_trailing_zeros && (last_removed_digit == 0);
			last_removed_digit = ((byte)(vr_mod_10));
			vr = vr_div_10;
			vp = vp_div_10;
			vm = vm_div_10;
			removed++;
		}
		if (vm_is_trailing_zeros) {
			for (;;) {
				u64 vm_div_10 = vm / 10U;
				u64 vm_mod_10 = vm % 10U;
				if (vm_mod_10 != 0U) {
					break;
				}
				u64 vp_div_10 = vp / 10U;
				u64 vr_div_10 = vr / 10U;
				u64 vr_mod_10 = vr % 10U;
				vr_is_trailing_zeros = vr_is_trailing_zeros && (last_removed_digit == 0);
				last_removed_digit = ((byte)(vr_mod_10));
				vr = vr_div_10;
				vp = vp_div_10;
				vm = vm_div_10;
				removed++;
			}
		}
		if (vr_is_trailing_zeros && (last_removed_digit == 5) && (vr % 2U) == 0U) {
			last_removed_digit = 4;
		}
		out = vr;
		if ((vr == vm && (!accept_bounds || !vm_is_trailing_zeros)) || last_removed_digit >= 5) {
			out++;
		}
	} else {
		bool round_up = false;
		for (;;) {
			if (!(vp / 100U > vm / 100U)) break;
			round_up = (vr % 100U) >= 50U;
			vr /= 100U;
			vp /= 100U;
			vm /= 100U;
			removed += 2;
		}
		for (;;) {
			if (!(vp / 10U > vm / 10U)) break;
			round_up = (vr % 10U) >= 5U;
			vr /= 10U;
			vp /= 10U;
			vm /= 10U;
			removed++;
		}
		out = vr + strconv__bool_to_u64(vr == vm || round_up);
	}
	return (strconv__Dec64){.m = out,.e = e10 + removed,};
}

string strconv__f64_to_str(f64 f, int n_digit) {
	strconv__Uf64 u1 = (strconv__Uf64){0};
	u1.f = f;
	u64 u = u1.u;
	bool neg = (u >> (_const_strconv__mantbits64 + _const_strconv__expbits64)) != 0U;
	u64 mant = (u & ((((u64)(1U)) << _const_strconv__mantbits64) - ((u64)(1U))));
	u64 exp = ((u >> _const_strconv__mantbits64) & ((((u64)(1U)) << _const_strconv__expbits64) - ((u64)(1U))));
	if ((exp == _const_strconv__maxexp64) || (exp == 0U && mant == 0U)) {
		return strconv__get_string_special(neg, exp == 0U, mant == 0U);
	}
	multi_return_strconv__Dec64_bool mr_9326 = strconv__f64_to_decimal_exact_int(mant, exp);
	strconv__Dec64 d = mr_9326.arg0;
	bool ok = mr_9326.arg1;
	if (!ok) {
		d = strconv__f64_to_decimal(mant, exp);
	}
	return strconv__Dec64_get_string_64(d, neg, n_digit, 0);
}

string strconv__f64_to_str_pad(f64 f, int n_digit) {
	strconv__Uf64 u1 = (strconv__Uf64){0};
	u1.f = f;
	u64 u = u1.u;
	bool neg = (u >> (_const_strconv__mantbits64 + _const_strconv__expbits64)) != 0U;
	u64 mant = (u & ((((u64)(1U)) << _const_strconv__mantbits64) - ((u64)(1U))));
	u64 exp = ((u >> _const_strconv__mantbits64) & ((((u64)(1U)) << _const_strconv__expbits64) - ((u64)(1U))));
	if ((exp == _const_strconv__maxexp64) || (exp == 0U && mant == 0U)) {
		return strconv__get_string_special(neg, exp == 0U, mant == 0U);
	}
	multi_return_strconv__Dec64_bool mr_10079 = strconv__f64_to_decimal_exact_int(mant, exp);
	strconv__Dec64 d = mr_10079.arg0;
	bool ok = mr_10079.arg1;
	if (!ok) {
		d = strconv__f64_to_decimal(mant, exp);
	}
	return strconv__Dec64_get_string_64(d, neg, n_digit, n_digit);
}

string strconv__format_str(string s, strconv__BF_param p) {
bool strconv__format_str_defer_0 = false;
strings__Builder res;
	if (p.len0 <= 0) {
		return string_clone(s);
	}
	int dif = p.len0 - utf8_str_visible_length(s);
	if (dif <= 0) {
		return string_clone(s);
	}
	res = strings__new_builder(s.len + dif);
	strconv__format_str_defer_0 = true;
	if (p.allign == strconv__Align_text__right) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(&res, p.pad_ch);
		}
	}
	strings__Builder_write_string(&res, s);
	if (p.allign == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(&res, p.pad_ch);
		}
	}
	string _t3 = strings__Builder_str(&res);
	// Defer begin
	if (strconv__format_str_defer_0) {
		strings__Builder_free(&res);
	}
	// Defer end
	return _t3;
}

void strconv__format_str_sb(string s, strconv__BF_param p, strings__Builder* sb) {
	if (p.len0 <= 0) {
		strings__Builder_write_string(sb, s);
		return;
	}
	int dif = p.len0 - utf8_str_visible_length(s);
	if (dif <= 0) {
		strings__Builder_write_string(sb, s);
		return;
	}
	if (p.allign == strconv__Align_text__right) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(sb, p.pad_ch);
		}
	}
	strings__Builder_write_string(sb, s);
	if (p.allign == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(sb, p.pad_ch);
		}
	}
}

// Attr: [direct_array_access]
void strconv__format_dec_sb(u64 d, strconv__BF_param p, strings__Builder* res) {
	int n_char = strconv__dec_digits(d);
	int sign_len = (!p.positive || p.sign_flag ? (1) : (0));
	int number_len = sign_len + n_char;
	int dif = p.len0 - number_len;
	bool sign_written = false;
	if (p.allign == strconv__Align_text__right) {
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					strings__Builder_write_b(res, '+');
					sign_written = true;
				}
			} else {
				strings__Builder_write_b(res, '-');
				sign_written = true;
			}
		}
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(res, p.pad_ch);
		}
	}
	if (!sign_written) {
		if (p.positive) {
			if (p.sign_flag) {
				strings__Builder_write_b(res, '+');
			}
		} else {
			strings__Builder_write_b(res, '-');
		}
	}
	Array_fixed_byte_32 buf = {0};
	int i = 20;
	u64 n = d;
	u64 d_i = ((u64)(0U));
	if (n > 0U) {
		for (;;) {
			if (!(n > 0U)) break;
			u64 n1 = n / 100U;
			d_i = (n - (n1 * 100U)) << 1U;
			n = n1;
			{ // Unsafe block
				buf[i] = _const_strconv__digit_pairs.str[d_i];
			}
			i--;
			d_i++;
			{ // Unsafe block
				buf[i] = _const_strconv__digit_pairs.str[d_i];
			}
			i--;
		}
		i++;
		if (d_i < 20U) {
			i++;
		}
		strings__Builder_write_ptr(res, &buf[i], n_char);
	} else {
		strings__Builder_write_b(res, '0');
	}
	if (p.allign == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(res, p.pad_ch);
		}
	}
	return;
}

// Attr: [direct_array_access]
// Attr: [manualfree]
string strconv__f64_to_str_lnd1(f64 f, int dec_digit) {
	{ // Unsafe block
		string s = strconv__f64_to_str(f + ((f64*)_const_strconv__dec_round.data)[dec_digit], 18);
		if (s.len > 2 && (s.str[ 0] == 'n' || s.str[ 1] == 'i')) {
			return s;
		}
		bool m_sgn_flag = false;
		int sgn = 1;
		Array_fixed_byte_26 b = {0};
		int d_pos = 1;
		int i = 0;
		int i1 = 0;
		int exp = 0;
		int exp_sgn = 1;
		int dot_res_sp = -1;
		for (int _t2 = 0; _t2 < s.len; ++_t2) {
			byte c = s.str[_t2];
			if (c == '-') {
				sgn = -1;
				i++;
			} else if (c == '+') {
				sgn = 1;
				i++;
			} else if (c >= '0' && c <= '9') {
				b[i1] = c;
				i1++;
				i++;
			} else if (c == '.') {
				if (sgn > 0) {
					d_pos = i;
				} else {
					d_pos = i - 1;
				}
				i++;
			} else if (c == 'e') {
				i++;
				break;
			} else {
				string_free(&s);
				return _SLIT("[Float conversion error!!]");
			}
		}
		b[i1] = 0;
		if (s.str[ i] == '-') {
			exp_sgn = -1;
			i++;
		} else if (s.str[ i] == '+') {
			exp_sgn = 1;
			i++;
		}
		int c = i;
		for (;;) {
			if (!(c < s.len)) break;
			exp = exp * 10 + ((int)(s.str[ c] - '0'));
			c++;
		}
		Array_byte res = __new_array_with_default(exp + 32, 0, sizeof(byte), &(byte[]){0});
		int r_i = 0;
		string_free(&s);
		if (sgn == 1) {
			if (m_sgn_flag) {
				((byte*)res.data)[r_i] = '+';
				r_i++;
			}
		} else {
			((byte*)res.data)[r_i] = '-';
			r_i++;
		}
		i = 0;
		if (exp_sgn >= 0) {
			for (;;) {
				if (!(b[i] != 0)) break;
				((byte*)res.data)[r_i] = b[i];
				r_i++;
				i++;
				if (i >= d_pos && exp >= 0) {
					if (exp == 0) {
						dot_res_sp = r_i;
						((byte*)res.data)[r_i] = '.';
						r_i++;
					}
					exp--;
				}
			}
			for (;;) {
				if (!(exp >= 0)) break;
				((byte*)res.data)[r_i] = '0';
				r_i++;
				exp--;
			}
		} else {
			bool dot_p = true;
			for (;;) {
				if (!(exp > 0)) break;
				((byte*)res.data)[r_i] = '0';
				r_i++;
				exp--;
				if (dot_p) {
					dot_res_sp = r_i;
					((byte*)res.data)[r_i] = '.';
					r_i++;
					dot_p = false;
				}
			}
			for (;;) {
				if (!(b[i] != 0)) break;
				((byte*)res.data)[r_i] = b[i];
				r_i++;
				i++;
			}
		}
		if (dec_digit <= 0) {
			string tmp_res = string_clone(tos(res.data, dot_res_sp));
			array_free(&res);
			return tmp_res;
		}
		if (dot_res_sp >= 0) {
			if ((r_i - dot_res_sp) > dec_digit) {
				r_i = dot_res_sp + dec_digit + 1;
			}
			((byte*)res.data)[r_i] = 0;
			string tmp_res = string_clone(tos(res.data, r_i));
			array_free(&res);
			return tmp_res;
		} else {
			if (dec_digit > 0) {
				int c1 = 0;
				((byte*)res.data)[r_i] = '.';
				r_i++;
				for (;;) {
					if (!(c1 < dec_digit)) break;
					((byte*)res.data)[r_i] = '0';
					r_i++;
					c1++;
				}
				((byte*)res.data)[r_i] = 0;
			}
			string tmp_res = string_clone(tos(res.data, r_i));
			array_free(&res);
			return tmp_res;
		}
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
// Attr: [manualfree]
string strconv__format_fl(f64 f, strconv__BF_param p) {
	{ // Unsafe block
		string fs = strconv__f64_to_str_lnd1((f >= 0.0 ? (f) : (-f)), p.len1);
		if (fs.str[ 0] == '[') {
			return fs;
		}
		if (p.rm_tail_zero) {
			string tmp = fs;
			fs = strconv__remove_tail_zeros(fs);
			string_free(&tmp);
		}
		Array_fixed_u8_32 buf = {0};
		Array_fixed_u8_32 out = {0};
		int buf_i = 0;
		int out_i = 0;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					out[out_i] = '+';
					out_i++;
					sign_len_diff = -1;
				}
			} else {
				out[out_i] = '-';
				out_i++;
				sign_len_diff = -1;
			}
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					buf[buf_i] = '+';
					buf_i++;
				}
			} else {
				buf[buf_i] = '-';
				buf_i++;
			}
		}
		vmemcpy(&buf[buf_i], fs.str, fs.len);
		buf_i += fs.len;
		int dif = p.len0 - buf_i + sign_len_diff;
		if (p.allign == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		vmemcpy(&out[out_i], &buf[0], buf_i);
		out_i += buf_i;
		if (p.allign == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		out[out_i] = 0;
		string tmp = fs;
		fs = tos_clone(&out[0]);
		string_free(&tmp);
		return fs;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
// Attr: [manualfree]
string strconv__format_es(f64 f, strconv__BF_param p) {
	{ // Unsafe block
		string fs = strconv__f64_to_str_pad((f > 0 ? (f) : (-f)), p.len1);
		if (p.rm_tail_zero) {
			string tmp = fs;
			fs = strconv__remove_tail_zeros(fs);
			string_free(&tmp);
		}
		Array_fixed_u8_32 buf = {0};
		Array_fixed_u8_32 out = {0};
		int buf_i = 0;
		int out_i = 0;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					out[out_i] = '+';
					out_i++;
					sign_len_diff = -1;
				}
			} else {
				out[out_i] = '-';
				out_i++;
				sign_len_diff = -1;
			}
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					buf[buf_i] = '+';
					buf_i++;
				}
			} else {
				buf[buf_i] = '-';
				buf_i++;
			}
		}
		vmemcpy(&buf[buf_i], fs.str, fs.len);
		buf_i += fs.len;
		int dif = p.len0 - buf_i + sign_len_diff;
		if (p.allign == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		vmemcpy(&out[out_i], &buf[0], buf_i);
		out_i += buf_i;
		if (p.allign == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		out[out_i] = 0;
		string tmp = fs;
		fs = tos_clone(&out[0]);
		string_free(&tmp);
		return fs;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
string strconv__remove_tail_zeros(string s) {
	{ // Unsafe block
		byte* buf = malloc_noscan(s.len + 1);
		int i_d = 0;
		int i_s = 0;
		for (;;) {
			if (!(i_s < s.len && !(s.str[ i_s] == '-' || s.str[ i_s] == '+') && (s.str[ i_s] > '9' || s.str[ i_s] < '0'))) break;
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		if (i_s < s.len && (s.str[ i_s] == '-' || s.str[ i_s] == '+')) {
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		for (;;) {
			if (!(i_s < s.len && s.str[ i_s] >= '0' && s.str[ i_s] <= '9')) break;
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		if (i_s < s.len && s.str[ i_s] == '.') {
			int i_s1 = i_s + 1;
			int sum = 0;
			for (;;) {
				if (!(i_s1 < s.len && s.str[ i_s1] >= '0' && s.str[ i_s1] <= '9')) break;
				sum += s.str[ i_s1] - ((byte)('0'));
				i_s1++;
			}
			if (sum > 0) {
				for (int c_i = i_s; c_i < i_s1; ++c_i) {
					buf[i_d] = s.str[ c_i];
					i_d++;
				}
			}
			i_s = i_s1;
		}
		if (i_s < s.len && s.str[ i_s] != '.') {
			for (;;) {
				buf[i_d] = s.str[ i_s];
				i_s++;
				i_d++;
				if (i_s >= s.len) {
					break;
				}
			}
		}
		buf[i_d] = 0;
		return tos(buf, i_d);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string strconv__ftoa_64(f64 f) {
	return strconv__f64_to_str(f, 17);
}

// Attr: [inline]
inline string strconv__ftoa_long_64(f64 f) {
	return strconv__f64_to_str_l(f);
}

// Attr: [inline]
inline string strconv__ftoa_32(f32 f) {
	return strconv__f32_to_str(f, 8);
}

// Attr: [inline]
inline string strconv__ftoa_long_32(f32 f) {
	return strconv__f32_to_str_l(f);
}

// Attr: [manualfree]
string strconv__format_int(i64 n, int radix) {
	{ // Unsafe block
		if (radix < 2 || radix > 36) {
			Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("invalid radix: "), 0xfe07, {.d_i32 = radix}}, {_SLIT(" . It should be => 2 and <= 36"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
		if (n == 0) {
			return _SLIT("0");
		}
		i64 n_copy = n;
		string sign = _SLIT("");
		if (n < 0) {
			sign = _SLIT("-");
			n_copy = -n_copy;
		}
		string res = _SLIT("");
		for (;;) {
			if (!(n_copy != 0)) break;
			string tmp_0 = res;
			string tmp_1 = byte_ascii_str(string_at(_const_strconv__base_digits, n_copy % radix));
			res = string__plus(tmp_1, res);
			string_free(&tmp_0);
			string_free(&tmp_1);
			n_copy /= radix;
		}
		return  str_intp(3, _MOV((StrIntpData[]){{_SLIT0, 0xfe10, {.d_s = sign}}, {_SLIT0, 0xfe10, {.d_s = res}}, {_SLIT0, 0, { .d_c = 0 }}}));
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [manualfree]
string strconv__format_uint(u64 n, int radix) {
	{ // Unsafe block
		if (radix < 2 || radix > 36) {
			Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("invalid radix: "), 0xfe07, {.d_i32 = radix}}, {_SLIT(" . It should be => 2 and <= 36"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
		if (n == 0U) {
			return _SLIT("0");
		}
		u64 n_copy = n;
		string res = _SLIT("");
		u64 uradix = ((u64)(radix));
		for (;;) {
			if (!(n_copy != 0U)) break;
			string tmp_0 = res;
			string tmp_1 = byte_ascii_str(string_at(_const_strconv__base_digits, n_copy % uradix));
			res = string__plus(tmp_1, res);
			string_free(&tmp_0);
			string_free(&tmp_1);
			n_copy /= uradix;
		}
		return res;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [manualfree]
string strconv__f32_to_str_l(f32 f) {
	string s = strconv__f32_to_str(f, 6);
	string res = strconv__fxx_to_str_l_parse(s);
	string_free(&s);
	return res;
}

// Attr: [manualfree]
string strconv__f32_to_str_l_no_dot(f32 f) {
	string s = strconv__f32_to_str(f, 6);
	string res = strconv__fxx_to_str_l_parse_no_dot(s);
	string_free(&s);
	return res;
}

// Attr: [manualfree]
string strconv__f64_to_str_l(f64 f) {
	string s = strconv__f64_to_str(f, 18);
	string res = strconv__fxx_to_str_l_parse(s);
	string_free(&s);
	return res;
}

// Attr: [manualfree]
string strconv__f64_to_str_l_no_dot(f64 f) {
	string s = strconv__f64_to_str(f, 18);
	string res = strconv__fxx_to_str_l_parse_no_dot(s);
	string_free(&s);
	return res;
}

// Attr: [manualfree]
string strconv__fxx_to_str_l_parse(string s) {
	if (s.len > 2 && (string_at(s, 0) == 'n' || string_at(s, 1) == 'i')) {
		return string_clone(s);
	}
	bool m_sgn_flag = false;
	int sgn = 1;
	Array_fixed_byte_26 b = {0};
	int d_pos = 1;
	int i = 0;
	int i1 = 0;
	int exp = 0;
	int exp_sgn = 1;
	for (int _t2 = 0; _t2 < s.len; ++_t2) {
		byte c = s.str[_t2];
		if (c == '-') {
			sgn = -1;
			i++;
		} else if (c == '+') {
			sgn = 1;
			i++;
		} else if (c >= '0' && c <= '9') {
			b[v_fixed_index(i1, 26)] = c;
			i1++;
			i++;
		} else if (c == '.') {
			if (sgn > 0) {
				d_pos = i;
			} else {
				d_pos = i - 1;
			}
			i++;
		} else if (c == 'e') {
			i++;
			break;
		} else {
			return _SLIT("Float conversion error!!");
		}
	}
	b[v_fixed_index(i1, 26)] = 0;
	if (string_at(s, i) == '-') {
		exp_sgn = -1;
		i++;
	} else if (string_at(s, i) == '+') {
		exp_sgn = 1;
		i++;
	}
	int c = i;
	for (;;) {
		if (!(c < s.len)) break;
		exp = exp * 10 + ((int)(string_at(s, c) - '0'));
		c++;
	}
	Array_byte res = __new_array_with_default(exp + 32, 0, sizeof(byte), &(byte[]){0});
	int r_i = 0;
	if (sgn == 1) {
		if (m_sgn_flag) {
			array_set(&res, r_i, &(byte[]) { '+' });
			r_i++;
		}
	} else {
		array_set(&res, r_i, &(byte[]) { '-' });
		r_i++;
	}
	i = 0;
	if (exp_sgn >= 0) {
		for (;;) {
			if (!(b[v_fixed_index(i, 26)] != 0)) break;
			array_set(&res, r_i, &(byte[]) { b[v_fixed_index(i, 26)] });
			r_i++;
			i++;
			if (i >= d_pos && exp >= 0) {
				if (exp == 0) {
					array_set(&res, r_i, &(byte[]) { '.' });
					r_i++;
				}
				exp--;
			}
		}
		for (;;) {
			if (!(exp >= 0)) break;
			array_set(&res, r_i, &(byte[]) { '0' });
			r_i++;
			exp--;
		}
	} else {
		bool dot_p = true;
		for (;;) {
			if (!(exp > 0)) break;
			array_set(&res, r_i, &(byte[]) { '0' });
			r_i++;
			exp--;
			if (dot_p) {
				array_set(&res, r_i, &(byte[]) { '.' });
				r_i++;
				dot_p = false;
			}
		}
		for (;;) {
			if (!(b[v_fixed_index(i, 26)] != 0)) break;
			array_set(&res, r_i, &(byte[]) { b[v_fixed_index(i, 26)] });
			r_i++;
			i++;
		}
	}
	array_set(&res, r_i, &(byte[]) { 0 });
	return tos(res.data, r_i);
}

// Attr: [manualfree]
string strconv__fxx_to_str_l_parse_no_dot(string s) {
	if (s.len > 2 && (string_at(s, 0) == 'n' || string_at(s, 1) == 'i')) {
		return string_clone(s);
	}
	bool m_sgn_flag = false;
	int sgn = 1;
	Array_fixed_byte_26 b = {0};
	int d_pos = 1;
	int i = 0;
	int i1 = 0;
	int exp = 0;
	int exp_sgn = 1;
	for (int _t2 = 0; _t2 < s.len; ++_t2) {
		byte c = s.str[_t2];
		if (c == '-') {
			sgn = -1;
			i++;
		} else if (c == '+') {
			sgn = 1;
			i++;
		} else if (c >= '0' && c <= '9') {
			b[v_fixed_index(i1, 26)] = c;
			i1++;
			i++;
		} else if (c == '.') {
			if (sgn > 0) {
				d_pos = i;
			} else {
				d_pos = i - 1;
			}
			i++;
		} else if (c == 'e') {
			i++;
			break;
		} else {
			return _SLIT("Float conversion error!!");
		}
	}
	b[v_fixed_index(i1, 26)] = 0;
	if (string_at(s, i) == '-') {
		exp_sgn = -1;
		i++;
	} else if (string_at(s, i) == '+') {
		exp_sgn = 1;
		i++;
	}
	int c = i;
	for (;;) {
		if (!(c < s.len)) break;
		exp = exp * 10 + ((int)(string_at(s, c) - '0'));
		c++;
	}
	Array_byte res = __new_array_with_default(exp + 32, 0, sizeof(byte), &(byte[]){0});
	int r_i = 0;
	if (sgn == 1) {
		if (m_sgn_flag) {
			array_set(&res, r_i, &(byte[]) { '+' });
			r_i++;
		}
	} else {
		array_set(&res, r_i, &(byte[]) { '-' });
		r_i++;
	}
	i = 0;
	if (exp_sgn >= 0) {
		for (;;) {
			if (!(b[v_fixed_index(i, 26)] != 0)) break;
			array_set(&res, r_i, &(byte[]) { b[v_fixed_index(i, 26)] });
			r_i++;
			i++;
			if (i >= d_pos && exp >= 0) {
				if (exp == 0) {
					array_set(&res, r_i, &(byte[]) { '.' });
					r_i++;
				}
				exp--;
			}
		}
		for (;;) {
			if (!(exp >= 0)) break;
			array_set(&res, r_i, &(byte[]) { '0' });
			r_i++;
			exp--;
		}
	} else {
		bool dot_p = true;
		for (;;) {
			if (!(exp > 0)) break;
			array_set(&res, r_i, &(byte[]) { '0' });
			r_i++;
			exp--;
			if (dot_p) {
				array_set(&res, r_i, &(byte[]) { '.' });
				r_i++;
				dot_p = false;
			}
		}
		for (;;) {
			if (!(b[v_fixed_index(i, 26)] != 0)) break;
			array_set(&res, r_i, &(byte[]) { b[v_fixed_index(i, 26)] });
			r_i++;
			i++;
		}
	}
	if (r_i > 1 && (*(byte*)/*ee elem_typ */array_get(res, r_i - 1)) == '.') {
		r_i--;
	}
	array_set(&res, r_i, &(byte[]) { 0 });
	return tos(res.data, r_i);
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL int strconv__bool_to_int(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL u32 strconv__bool_to_u32(bool b) {
	if (b) {
		return ((u32)(1U));
	}
	return ((u32)(0U));
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL u64 strconv__bool_to_u64(bool b) {
	if (b) {
		return ((u64)(1U));
	}
	return ((u64)(0U));
}

VV_LOCAL_SYMBOL string strconv__get_string_special(bool neg, bool expZero, bool mantZero) {
	if (!mantZero) {
		return _SLIT("nan");
	}
	if (!expZero) {
		if (neg) {
			return _SLIT("-inf");
		} else {
			return _SLIT("+inf");
		}
	}
	if (neg) {
		return _SLIT("-0e+00");
	}
	return _SLIT("0e+00");
}

VV_LOCAL_SYMBOL u32 strconv__mul_shift_32(u32 m, u64 mul, int ishift) {
	multi_return_u64_u64 mr_746 = math__bits__mul_64(((u64)(m)), mul);
	u64 hi = mr_746.arg0;
	u64 lo = mr_746.arg1;
	u64 shifted_sum = (lo >> ((u64)(ishift))) + (hi << ((u64)(64 - ishift)));
	;
	return ((u32)(shifted_sum));
}

VV_LOCAL_SYMBOL u32 strconv__mul_pow5_invdiv_pow2(u32 m, u32 q, int j) {
	return strconv__mul_shift_32(m, (*(u64*)/*ee elem_typ */array_get(_const_strconv__pow5_inv_split_32, q)), j);
}

VV_LOCAL_SYMBOL u32 strconv__mul_pow5_div_pow2(u32 m, u32 i, int j) {
	return strconv__mul_shift_32(m, (*(u64*)/*ee elem_typ */array_get(_const_strconv__pow5_split_32, i)), j);
}

VV_LOCAL_SYMBOL u32 strconv__pow5_factor_32(u32 i_v) {
	u32 v = i_v;
	for (u32 n = ((u32)(0U)); true; n++) {
		u32 q = v / 5U;
		u32 r = v % 5U;
		if (r != 0U) {
			return n;
		}
		v = q;
	}
	return v;
}

VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_five_32(u32 v, u32 p) {
	return strconv__pow5_factor_32(v) >= p;
}

VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_two_32(u32 v, u32 p) {
	return ((u32)(math__bits__trailing_zeros_32(v))) >= p;
}

VV_LOCAL_SYMBOL u32 strconv__log10_pow2(int e) {
	;
	;
	return (((u32)(e)) * 78913U) >> 18U;
}

VV_LOCAL_SYMBOL u32 strconv__log10_pow5(int e) {
	;
	;
	return (((u32)(e)) * 732923U) >> 20U;
}

VV_LOCAL_SYMBOL int strconv__pow5_bits(int e) {
	;
	;
	return ((int)(((((u32)(e)) * 1217359U) >> 19U) + 1U));
}

VV_LOCAL_SYMBOL u64 strconv__shift_right_128(strconv__Uint128 v, int shift) {
	;
	return ((v.hi << ((u64)(64 - shift))) | (v.lo >> ((u32)(shift))));
}

VV_LOCAL_SYMBOL u64 strconv__mul_shift_64(u64 m, strconv__Uint128 mul, int shift) {
	multi_return_u64_u64 mr_3065 = math__bits__mul_64(m, mul.hi);
	u64 hihi = mr_3065.arg0;
	u64 hilo = mr_3065.arg1;
	multi_return_u64_u64 mr_3100 = math__bits__mul_64(m, mul.lo);
	u64 lohi = mr_3100.arg0;
	strconv__Uint128 sum = (strconv__Uint128){.lo = lohi + hilo,.hi = hihi,};
	if (sum.lo < lohi) {
		sum.hi++;
	}
	return strconv__shift_right_128(sum, shift - 64);
}

VV_LOCAL_SYMBOL u32 strconv__pow5_factor_64(u64 v_i) {
	u64 v = v_i;
	for (u32 n = ((u32)(0U)); true; n++) {
		u64 q = v / 5U;
		u64 r = v % 5U;
		if (r != 0U) {
			return n;
		}
		v = q;
	}
	return ((u32)(0U));
}

VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_five_64(u64 v, u32 p) {
	return strconv__pow5_factor_64(v) >= p;
}

VV_LOCAL_SYMBOL bool strconv__multiple_of_power_of_two_64(u64 v, u32 p) {
	return ((u32)(math__bits__trailing_zeros_64(v))) >= p;
}

int strconv__dec_digits(u64 n) {
	if (n <= 9999999999U) {
		if (n <= 99999U) {
			if (n <= 99U) {
				if (n <= 9U) {
					return 1;
				} else {
					return 2;
				}
			} else {
				if (n <= 999U) {
					return 3;
				} else {
					if (n <= 9999U) {
						return 4;
					} else {
						return 5;
					}
				}
			}
		} else {
			if (n <= 9999999U) {
				if (n <= 999999U) {
					return 6;
				} else {
					return 7;
				}
			} else {
				if (n <= 99999999U) {
					return 8;
				} else {
					if (n <= 999999999U) {
						return 9;
					}
					return 10;
				}
			}
		}
	} else {
		if (n <= 999999999999999U) {
			if (n <= 999999999999U) {
				if (n <= 99999999999U) {
					return 11;
				} else {
					return 12;
				}
			} else {
				if (n <= 9999999999999U) {
					return 13;
				} else {
					if (n <= 99999999999999U) {
						return 14;
					} else {
						return 15;
					}
				}
			}
		} else {
			if (n <= 99999999999999999U) {
				if (n <= 9999999999999999U) {
					return 16;
				} else {
					return 17;
				}
			} else {
				if (n <= 999999999999999999U) {
					return 18;
				} else {
					if (n <= 9999999999999999999U) {
						return 19;
					}
					return 20;
				}
			}
		}
	}
	return 0;
}

void strconv_Dprintf(string str, Array_voidptr pt) {
	print(strconv_Dsprintf(str, new_array_from_c_array(1, 1, sizeof(voidptr), _MOV((voidptr[1]){(voidptr)&/*qq*/pt}))));
}

string strconv_Dsprintf(string str, Array_voidptr pt) {
bool strconv_Dsprintf_defer_0 = false;
strings__Builder res;
	res = strings__new_builder(pt.len * 16);
	strconv_Dsprintf_defer_0 = true;
	int i = 0;
	int p_index = 0;
	bool sign = false;
	strconv__Align_text allign = strconv__Align_text__right;
	int len0 = -1;
	int len1 = -1;
	int def_len1 = 6;
	byte pad_ch = ((byte)(' '));
	rune ch1 = '0';
	rune ch2 = '0';
	strconv__Char_parse_state status = strconv__Char_parse_state__norm_char;
	for (;;) {
		if (!(i < str.len)) break;
		if (status == strconv__Char_parse_state__reset_params) {
			sign = false;
			allign = strconv__Align_text__right;
			len0 = -1;
			len1 = -1;
			pad_ch = ' ';
			status = strconv__Char_parse_state__norm_char;
			ch1 = '0';
			ch2 = '0';
			continue;
		}
		byte ch = string_at(str, i);
		if (ch != '%' && status == strconv__Char_parse_state__norm_char) {
			strings__Builder_write_b(&res, ch);
			i++;
			continue;
		}
		if (ch == '%' && status == strconv__Char_parse_state__norm_char) {
			status = strconv__Char_parse_state__field_char;
			i++;
			continue;
		}
		if (ch == 'c' && status == strconv__Char_parse_state__field_char) {
			strconv_Dsprintf_panic(p_index, pt.len);
			byte d1 = *(((byte*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
			strings__Builder_write_b(&res, d1);
			status = strconv__Char_parse_state__reset_params;
			p_index++;
			i++;
			continue;
		}
		if (ch == 'p' && status == strconv__Char_parse_state__field_char) {
			strconv_Dsprintf_panic(p_index, pt.len);
			strings__Builder_write_string(&res, _SLIT("0x"));
			strings__Builder_write_string(&res, ptr_str((*(voidptr*)/*ee elem_typ */array_get(pt, p_index))));
			status = strconv__Char_parse_state__reset_params;
			p_index++;
			i++;
			continue;
		}
		if (status == strconv__Char_parse_state__field_char) {
			rune fc_ch1 = '0';
			rune fc_ch2 = '0';
			if ((i + 1) < str.len) {
				fc_ch1 = string_at(str, i + 1);
				if ((i + 2) < str.len) {
					fc_ch2 = string_at(str, i + 2);
				}
			}
			if (ch == '+') {
				sign = true;
				i++;
				continue;
			} else if (ch == '-') {
				allign = strconv__Align_text__left;
				i++;
				continue;
			} else if (ch == '0' || ch == ' ') {
				if (allign == strconv__Align_text__right) {
					pad_ch = ch;
				}
				i++;
				continue;
			} else if (ch == '\'') {
				i++;
				continue;
			} else if (ch == '.' && fc_ch1 >= '1' && fc_ch1 <= '9') {
				status = strconv__Char_parse_state__check_float;
				i++;
				continue;
			} else if (ch == '.' && fc_ch1 == '*' && fc_ch2 == 's') {
				strconv_Dsprintf_panic(p_index, pt.len);
				int len = *(((int*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
				p_index++;
				strconv_Dsprintf_panic(p_index, pt.len);
				string s = *(((string*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
				s = string_substr(s, 0, len);
				p_index++;
				strings__Builder_write_string(&res, s);
				status = strconv__Char_parse_state__reset_params;
				i += 3;
				continue;
			}
			status = strconv__Char_parse_state__len_set_start;
			continue;
		}
		if (status == strconv__Char_parse_state__len_set_start) {
			if (ch >= '1' && ch <= '9') {
				len0 = ((int)(ch - '0'));
				status = strconv__Char_parse_state__len_set_in;
				i++;
				continue;
			}
			if (ch == '.') {
				status = strconv__Char_parse_state__check_float;
				i++;
				continue;
			}
			status = strconv__Char_parse_state__check_type;
			continue;
		}
		if (status == strconv__Char_parse_state__len_set_in) {
			if (ch >= '0' && ch <= '9') {
				len0 *= 10;
				len0 += ((int)(ch - '0'));
				i++;
				continue;
			}
			if (ch == '.') {
				status = strconv__Char_parse_state__check_float;
				i++;
				continue;
			}
			status = strconv__Char_parse_state__check_type;
			continue;
		}
		if (status == strconv__Char_parse_state__check_float) {
			if (ch >= '0' && ch <= '9') {
				len1 = ((int)(ch - '0'));
				status = strconv__Char_parse_state__check_float_in;
				i++;
				continue;
			}
			status = strconv__Char_parse_state__check_type;
			continue;
		}
		if (status == strconv__Char_parse_state__check_float_in) {
			if (ch >= '0' && ch <= '9') {
				len1 *= 10;
				len1 += ((int)(ch - '0'));
				i++;
				continue;
			}
			status = strconv__Char_parse_state__check_type;
			continue;
		}
		if (status == strconv__Char_parse_state__check_type) {
			if (ch == 'l') {
				if (ch1 == '0') {
					ch1 = 'l';
					i++;
					continue;
				} else {
					ch2 = 'l';
					i++;
					continue;
				}
			} else if (ch == 'h') {
				if (ch1 == '0') {
					ch1 = 'h';
					i++;
					continue;
				} else {
					ch2 = 'h';
					i++;
					continue;
				}
			} else if (ch == 'd' || ch == 'i') {
				u64 d1 = ((u64)(0U));
				bool positive = true;

				if (ch1 == ('h')) {
					if (ch2 == 'h') {
						strconv_Dsprintf_panic(p_index, pt.len);
						i8 x = *(((i8*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
						positive = (x >= 0 ? (true) : (false));
						d1 = (positive ? (((u64)(x))) : (((u64)(-x))));
					} else {
						i16 x = *(((i16*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
						positive = (x >= 0 ? (true) : (false));
						d1 = (positive ? (((u64)(x))) : (((u64)(-x))));
					}
				}
				else if (ch1 == ('l')) {
					strconv_Dsprintf_panic(p_index, pt.len);
					i64 x = *(((i64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					positive = (x >= 0 ? (true) : (false));
					d1 = (positive ? (((u64)(x))) : (((u64)(-x))));
				}
				else {
					strconv_Dsprintf_panic(p_index, pt.len);
					int x = *(((int*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					positive = (x >= 0 ? (true) : (false));
					d1 = (positive ? (((u64)(x))) : (((u64)(-x))));
				};
				strings__Builder_write_string(&res, strconv__format_dec_old(d1, (strconv__BF_param){
					.pad_ch = pad_ch,
					.len0 = len0,
					.len1 = 0,
					.positive = positive,
					.sign_flag = sign,
					.allign = allign,
					.rm_tail_zero = 0,
				}));
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				ch1 = '0';
				ch2 = '0';
				continue;
			} else if (ch == 'u') {
				u64 d1 = ((u64)(0U));
				bool positive = true;
				strconv_Dsprintf_panic(p_index, pt.len);

				if (ch1 == ('h')) {
					if (ch2 == 'h') {
						d1 = ((u64)(*(((byte*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))))));
					} else {
						d1 = ((u64)(*(((u16*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))))));
					}
				}
				else if (ch1 == ('l')) {
					d1 = ((u64)(*(((u64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))))));
				}
				else {
					d1 = ((u64)(*(((u32*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))))));
				};
				strings__Builder_write_string(&res, strconv__format_dec_old(d1, (strconv__BF_param){
					.pad_ch = pad_ch,
					.len0 = len0,
					.len1 = 0,
					.positive = positive,
					.sign_flag = sign,
					.allign = allign,
					.rm_tail_zero = 0,
				}));
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			} else if (ch == 'x' || ch == 'X') {
				strconv_Dsprintf_panic(p_index, pt.len);
				string s = _SLIT("");

				if (ch1 == ('h')) {
					if (ch2 == 'h') {
						i8 x = *(((i8*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
						s = i8_hex(x);
					} else {
						i16 x = *(((i16*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
						s = i16_hex(x);
					}
				}
				else if (ch1 == ('l')) {
					i64 x = *(((i64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					s = i64_hex(x);
				}
				else {
					int x = *(((int*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					s = int_hex(x);
				};
				if (ch == 'X') {
					s = string_to_upper(s);
				}
				strings__Builder_write_string(&res, strconv__format_str(s, (strconv__BF_param){
					.pad_ch = pad_ch,
					.len0 = len0,
					.len1 = 0,
					.positive = true,
					.sign_flag = false,
					.allign = allign,
					.rm_tail_zero = 0,
				}));
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			}
			if (ch == 'f' || ch == 'F') {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					strconv_Dsprintf_panic(p_index, pt.len);
					f64 x = *(((f64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					bool positive = x >= ((f64)(0.0));
					len1 = (len1 >= 0 ? (len1) : (def_len1));
					string s = strconv__format_fl_old(((f64)(x)), (strconv__BF_param){
						.pad_ch = pad_ch,
						.len0 = len0,
						.len1 = len1,
						.positive = positive,
						.sign_flag = sign,
						.allign = allign,
						.rm_tail_zero = 0,
					});
					strings__Builder_write_string(&res, (ch == 'F' ? (string_to_upper(s)) : (s)));
				}
				#endif
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			} else if (ch == 'e' || ch == 'E') {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					strconv_Dsprintf_panic(p_index, pt.len);
					f64 x = *(((f64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					bool positive = x >= ((f64)(0.0));
					len1 = (len1 >= 0 ? (len1) : (def_len1));
					string s = strconv__format_es_old(((f64)(x)), (strconv__BF_param){
						.pad_ch = pad_ch,
						.len0 = len0,
						.len1 = len1,
						.positive = positive,
						.sign_flag = sign,
						.allign = allign,
						.rm_tail_zero = 0,
					});
					strings__Builder_write_string(&res, (ch == 'E' ? (string_to_upper(s)) : (s)));
				}
				#endif
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			} else if (ch == 'g' || ch == 'G') {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					strconv_Dsprintf_panic(p_index, pt.len);
					f64 x = *(((f64*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
					bool positive = x >= ((f64)(0.0));
					string s = _SLIT("");
					f64 tx = strconv__fabs(x);
					if (tx < 999999.0 && tx >= 0.00001) {
						len1 = (len1 >= 0 ? (len1 + 1) : (def_len1));
						s = strconv__format_fl_old(x, (strconv__BF_param){
							.pad_ch = pad_ch,
							.len0 = len0,
							.len1 = len1,
							.positive = positive,
							.sign_flag = sign,
							.allign = allign,
							.rm_tail_zero = true,
						});
					} else {
						len1 = (len1 >= 0 ? (len1 + 1) : (def_len1));
						s = strconv__format_es_old(x, (strconv__BF_param){
							.pad_ch = pad_ch,
							.len0 = len0,
							.len1 = len1,
							.positive = positive,
							.sign_flag = sign,
							.allign = allign,
							.rm_tail_zero = true,
						});
					}
					strings__Builder_write_string(&res, (ch == 'G' ? (string_to_upper(s)) : (s)));
				}
				#endif
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			} else if (ch == 's') {
				strconv_Dsprintf_panic(p_index, pt.len);
				string s1 = *(((string*)((*(voidptr*)/*ee elem_typ */array_get(pt, p_index)))));
				pad_ch = ' ';
				strings__Builder_write_string(&res, strconv__format_str(s1, (strconv__BF_param){
					.pad_ch = pad_ch,
					.len0 = len0,
					.len1 = 0,
					.positive = true,
					.sign_flag = false,
					.allign = allign,
					.rm_tail_zero = 0,
				}));
				status = strconv__Char_parse_state__reset_params;
				p_index++;
				i++;
				continue;
			}
		}
		status = strconv__Char_parse_state__reset_params;
		p_index++;
		i++;
	}
	if (p_index != pt.len) {
		Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT0, 0xfe07, {.d_i32 = p_index}}, {_SLIT(" % conversion specifiers, but given "), 0xfe07, {.d_i32 = pt.len}}, {_SLIT(" args"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	string _t1 = strings__Builder_str(&res);
	// Defer begin
	if (strconv_Dsprintf_defer_0) {
		strings__Builder_free(&res);
	}
	// Defer end
	return _t1;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL void strconv_Dsprintf_panic(int idx, int len) {
	if (idx >= len) {
		Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT0, 0xfe07, {.d_i32 = idx + 1}}, {_SLIT(" % conversion specifiers, but given only "), 0xfe07, {.d_i32 = len}}, {_SLIT(" args"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
}

VV_LOCAL_SYMBOL f64 strconv__fabs(f64 x) {
	if (x < 0.0) {
		return -x;
	}
	return x;
}

// Attr: [manualfree]
string strconv__format_fl_old(f64 f, strconv__BF_param p) {
bool strconv__format_fl_old_defer_0 = false;
strings__Builder res;
	{ // Unsafe block
		string s = _SLIT("");
		string fs = strconv__f64_to_str_lnd1((f >= 0.0 ? (f) : (-f)), p.len1);
		if (string_at(fs, 0) == '[') {
			string_free(&s);
			return fs;
		}
		if (p.rm_tail_zero) {
			string tmp = fs;
			fs = strconv__remove_tail_zeros_old(fs);
			string_free(&tmp);
		}
		res = strings__new_builder((p.len0 > fs.len ? (p.len0) : (fs.len)));
		strconv__format_fl_old_defer_0 = true;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					strings__Builder_write_b(&res, '+');
					sign_len_diff = -1;
				}
			} else {
				strings__Builder_write_b(&res, '-');
				sign_len_diff = -1;
			}
			string tmp = s;
			s = string_clone(fs);
			string_free(&tmp);
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					string tmp = s;
					s = string__plus(_SLIT("+"), fs);
					string_free(&tmp);
				} else {
					string tmp = s;
					s = string_clone(fs);
					string_free(&tmp);
				}
			} else {
				string tmp = s;
				s = string__plus(_SLIT("-"), fs);
				string_free(&tmp);
			}
		}
		int dif = p.len0 - s.len + sign_len_diff;
		if (p.allign == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				strings__Builder_write_b(&res, p.pad_ch);
			}
		}
		strings__Builder_write_string(&res, s);
		if (p.allign == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				strings__Builder_write_b(&res, p.pad_ch);
			}
		}
		string_free(&s);
		string_free(&fs);
		string _t2 = strings__Builder_str(&res);
		// Defer begin
		if (strconv__format_fl_old_defer_0) {
			strings__Builder_free(&res);
		}
		// Defer end
		return _t2;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [manualfree]
string strconv__format_es_old(f64 f, strconv__BF_param p) {
bool strconv__format_es_old_defer_0 = false;
strings__Builder res;
	{ // Unsafe block
		string s = _SLIT("");
		string fs = strconv__f64_to_str_pad((f > 0 ? (f) : (-f)), p.len1);
		if (p.rm_tail_zero) {
			fs = strconv__remove_tail_zeros_old(fs);
		}
		res = strings__new_builder((p.len0 > fs.len ? (p.len0) : (fs.len)));
		strconv__format_es_old_defer_0 = true;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					strings__Builder_write_b(&res, '+');
					sign_len_diff = -1;
				}
			} else {
				strings__Builder_write_b(&res, '-');
				sign_len_diff = -1;
			}
			string tmp = s;
			s = string_clone(fs);
			string_free(&tmp);
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					string tmp = s;
					s = string__plus(_SLIT("+"), fs);
					string_free(&tmp);
				} else {
					string tmp = s;
					s = string_clone(fs);
					string_free(&tmp);
				}
			} else {
				string tmp = s;
				s = string__plus(_SLIT("-"), fs);
				string_free(&tmp);
			}
		}
		int dif = p.len0 - s.len + sign_len_diff;
		if (p.allign == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				strings__Builder_write_b(&res, p.pad_ch);
			}
		}
		strings__Builder_write_string(&res, s);
		if (p.allign == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				strings__Builder_write_b(&res, p.pad_ch);
			}
		}
		string_free(&s);
		string_free(&fs);
		string _t1 = strings__Builder_str(&res);
		// Defer begin
		if (strconv__format_es_old_defer_0) {
			strings__Builder_free(&res);
		}
		// Defer end
		return _t1;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

string strconv__remove_tail_zeros_old(string s) {
	int i = 0;
	int last_zero_start = -1;
	int dot_pos = -1;
	bool in_decimal = false;
	byte prev_ch = ((byte)(0));
	for (;;) {
		if (!(i < s.len)) break;
		byte ch = s.str[i];
		if (ch == '.') {
			in_decimal = true;
			dot_pos = i;
		} else if (in_decimal) {
			if (ch == '0' && prev_ch != '0') {
				last_zero_start = i;
			} else if (ch >= '1' && ch <= '9') {
				last_zero_start = -1;
			} else if (ch == 'e') {
				break;
			}
		}
		prev_ch = ch;
		i++;
	}
	string tmp = _SLIT("");
	if (last_zero_start > 0) {
		if (last_zero_start == dot_pos + 1) {
			tmp = string__plus(string_substr(s, 0, dot_pos), string_substr(s, i, s.len));
		} else {
			tmp = string__plus(string_substr(s, 0, last_zero_start), string_substr(s, i, s.len));
		}
	} else {
		tmp = s;
	}
	if (tmp.str[tmp.len - 1] == '.') {
		return string_substr(tmp, 0, tmp.len - 1);
	}
	return tmp;
}

string strconv__format_dec_old(u64 d, strconv__BF_param p) {
bool strconv__format_dec_old_defer_0 = false;
strings__Builder res;
	string s = _SLIT("");
	res = strings__new_builder(20);
	strconv__format_dec_old_defer_0 = true;
	int sign_len_diff = 0;
	if (p.pad_ch == '0') {
		if (p.positive) {
			if (p.sign_flag) {
				strings__Builder_write_b(&res, '+');
				sign_len_diff = -1;
			}
		} else {
			strings__Builder_write_b(&res, '-');
			sign_len_diff = -1;
		}
		s = u64_str(d);
	} else {
		if (p.positive) {
			if (p.sign_flag) {
				s = string__plus(_SLIT("+"), u64_str(d));
			} else {
				s = u64_str(d);
			}
		} else {
			s = string__plus(_SLIT("-"), u64_str(d));
		}
	}
	int dif = p.len0 - s.len + sign_len_diff;
	if (p.allign == strconv__Align_text__right) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(&res, p.pad_ch);
		}
	}
	strings__Builder_write_string(&res, s);
	if (p.allign == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_b(&res, p.pad_ch);
		}
	}
	string _t1 = strings__Builder_str(&res);
	// Defer begin
	if (strconv__format_dec_old_defer_0) {
		strings__Builder_free(&res);
	}
	// Defer end
	return _t1;
}

VV_LOCAL_SYMBOL array __new_array(int mylen, int cap, int elm_size) {
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array arr = (array){.element_size = elm_size,.data = vcalloc(cap_ * elm_size),.offset = 0,.len = mylen,.cap = cap_,.flags = 0,};
	return arr;
}

VV_LOCAL_SYMBOL array __new_array_with_default(int mylen, int cap, int elm_size, voidptr val) {
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array arr = (array){.element_size = elm_size,.data = 0,.offset = 0,.len = mylen,.cap = cap_,.flags = 0,};
	if (cap_ > 0 && mylen == 0) {
		arr.data = Dmalloc(cap_ * elm_size);
	} else {
		arr.data = vcalloc(cap_ * elm_size);
	}
	if (val != 0) {
		for (int i = 0; i < arr.len; ++i) {
			array_set_unsafe(&arr, i, val);
		}
	}
	return arr;
}

VV_LOCAL_SYMBOL array __new_array_with_array_default(int mylen, int cap, int elm_size, array val) {
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array arr = (array){.element_size = elm_size,.data = Dmalloc(cap_ * elm_size),.offset = 0,.len = mylen,.cap = cap_,.flags = 0,};
	for (int i = 0; i < arr.len; ++i) {
		array val_clone = array_clone_to_depth(&val, 1);
		array_set_unsafe(&arr, i, &val_clone);
	}
	return arr;
}

VV_LOCAL_SYMBOL array new_array_from_c_array(int len, int cap, int elm_size, voidptr c_array) {
	int cap_ = (cap < len ? (len) : (cap));
	array arr = (array){.element_size = elm_size,.data = vcalloc(cap_ * elm_size),.offset = 0,.len = len,.cap = cap_,.flags = 0,};
	vmemcpy(arr.data, c_array, len * elm_size);
	return arr;
}

VV_LOCAL_SYMBOL array new_array_from_c_array_no_alloc(int len, int cap, int elm_size, voidptr c_array) {
	array arr = (array){.element_size = elm_size,.data = c_array,.offset = 0,.len = len,.cap = cap,.flags = 0,};
	return arr;
}

VV_LOCAL_SYMBOL void array_ensure_cap(array* a, int required) {
	if (required <= a->cap) {
		return;
	}
	int cap = (a->cap > 0 ? (a->cap) : (2));
	for (;;) {
		if (!(required > cap)) break;
		cap *= 2;
	}
	int new_size = cap * a->element_size;
	byte* new_data = vcalloc(new_size);
	if (a->data != ((voidptr)(0))) {
		vmemcpy(new_data, a->data, a->len * a->element_size);
		if (ArrayFlags_has(&a->flags, ArrayFlags__noslices)) {
			Dfree(a->data);
		}
	}
	a->data = new_data;
	a->offset = 0;
	a->cap = cap;
}

array array_repeat(array a, int count) {
	return array_repeat_to_depth(a, count, 0);
}

// Attr: [unsafe]
array array_repeat_to_depth(array a, int count, int depth) {
	if (count < 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("array.repeat: count is negative: "), 0xfe07, {.d_i32 = count}}, {_SLIT0, 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	int size = count * a.len * a.element_size;
	if (size == 0) {
		size = a.element_size;
	}
	array arr = (array){.element_size = a.element_size,.data = vcalloc(size),.offset = 0,.len = count * a.len,.cap = count * a.len,.flags = 0,};
	if (a.len > 0) {
		for (int i = 0; i < count; ++i) {
			if (depth > 0) {
				array ary_clone = array_clone_to_depth(&a, depth);
				vmemcpy(array_get_unsafe(arr, i * a.len), ((byte*)(ary_clone.data)), a.len * a.element_size);
			} else {
				vmemcpy(array_get_unsafe(arr, i * a.len), ((byte*)(a.data)), a.len * a.element_size);
			}
		}
	}
	return arr;
}

void array_sort_with_compare(array* a, int (*callback)(voidptr , voidptr )) {
	#if defined(_VFREESTANDING)
	{
	}
	#else
	{
		vqsort(a->data, ((usize)(a->len)), ((usize)(a->element_size)), (voidptr)callback);
	}
	#endif
}

void array_insert(array* a, int i, voidptr val) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i > a->len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.insert: index out of range (i == "), 0xfe07, {.d_i32 = i}}, {_SLIT(", a.len == "), 0xfe07, {.d_i32 = a->len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	array_ensure_cap(a, a->len + 1);
	{ // Unsafe block
		vmemmove(array_get_unsafe(/*rec*/*a, i + 1), array_get_unsafe(/*rec*/*a, i), (a->len - i) * a->element_size);
		array_set_unsafe(a, i, val);
	}
	a->len++;
}

// Attr: [unsafe]
void array_insert_many(array* a, int i, voidptr val, int size) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i > a->len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.insert_many: index out of range (i == "), 0xfe07, {.d_i32 = i}}, {_SLIT(", a.len == "), 0xfe07, {.d_i32 = a->len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	array_ensure_cap(a, a->len + size);
	int elem_size = a->element_size;
	{ // Unsafe block
		voidptr iptr = array_get_unsafe(/*rec*/*a, i);
		vmemmove(array_get_unsafe(/*rec*/*a, i + size), iptr, (a->len - i) * elem_size);
		vmemcpy(iptr, val, size * elem_size);
	}
	a->len += size;
}

void array_prepend(array* a, voidptr val) {
	array_insert(a, 0, val);
}

// Attr: [unsafe]
void array_prepend_many(array* a, voidptr val, int size) {
	array_insert_many(a, 0, val, size);
}

void array_delete(array* a, int i) {
	array_delete_many(a, i, 1);
}

void array_delete_many(array* a, int i, int size) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i + size > a->len) {
			string endidx = (size > 1 ? ( str_intp(2, _MOV((StrIntpData[]){{_SLIT(".."), 0xfe07, {.d_i32 = i + size}}, {_SLIT0, 0, { .d_c = 0 }}}))) : (_SLIT("")));
			Dpanic( str_intp(4, _MOV((StrIntpData[]){{_SLIT("array.delete: index out of range (i == "), 0xfe07, {.d_i32 = i}}, {_SLIT0, 0xfe10, {.d_s = endidx}}, {_SLIT(", a.len == "), 0xfe07, {.d_i32 = a->len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	voidptr old_data = a->data;
	int new_size = a->len - size;
	int new_cap = (new_size == 0 ? (1) : (new_size));
	a->data = vcalloc(new_cap * a->element_size);
	vmemcpy(a->data, old_data, i * a->element_size);
	vmemcpy(((byte*)(a->data)) + i * a->element_size, ((byte*)(old_data)) + (i + size) * a->element_size, (a->len - i - size) * a->element_size);
	if (ArrayFlags_has(&a->flags, ArrayFlags__noslices)) {
		Dfree(old_data);
	}
	a->len = new_size;
	a->cap = new_cap;
}

void array_clear(array* a) {
	a->len = 0;
}

void array_trim(array* a, int index) {
	if (index < a->len) {
		a->len = index;
	}
}

// Attr: [inline]
// Attr: [unsafe]
inline VV_LOCAL_SYMBOL voidptr array_get_unsafe(array a, int i) {
	{ // Unsafe block
		return ((byte*)(a.data)) + i * a.element_size;
	}
	return 0;
}

VV_LOCAL_SYMBOL voidptr array_get(array a, int i) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i >= a.len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.get: index out of range (i == "), 0xfe07, {.d_i32 = i}}, {_SLIT(", a.len == "), 0xfe07, {.d_i32 = a.len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return ((byte*)(a.data)) + i * a.element_size;
	}
	return 0;
}

VV_LOCAL_SYMBOL voidptr array_get_with_check(array a, int i) {
	if (i < 0 || i >= a.len) {
		return 0;
	}
	{ // Unsafe block
		return ((byte*)(a.data)) + i * a.element_size;
	}
	return 0;
}

voidptr array_first(array a) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (a.len == 0) {
			Dpanic(_SLIT("array.first: array is empty"));
			VUNREACHABLE();
		}
	}
	#endif
	return a.data;
}

voidptr array_last(array a) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (a.len == 0) {
			Dpanic(_SLIT("array.last: array is empty"));
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return ((byte*)(a.data)) + (a.len - 1) * a.element_size;
	}
	return 0;
}

voidptr array_pop(array* a) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (a->len == 0) {
			Dpanic(_SLIT("array.pop: array is empty"));
			VUNREACHABLE();
		}
	}
	#endif
	int new_len = a->len - 1;
	byte* last_elem = ((byte*)(a->data)) + new_len * a->element_size;
	a->len = new_len;
	return memdup(last_elem, a->element_size);
}

void array_delete_last(array* a) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (a->len == 0) {
			Dpanic(_SLIT("array.pop: array is empty"));
			VUNREACHABLE();
		}
	}
	#endif
	a->len--;
}

VV_LOCAL_SYMBOL array array_slice(array a, int start, int _end) {
	int end = _end;
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (start > end) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.slice: invalid slice index ("), 0xfe07, {.d_i32 = start}}, {_SLIT(" > "), 0xfe07, {.d_i32 = end}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
		if (end > a.len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.slice: slice bounds out of range ("), 0xfe07, {.d_i32 = end}}, {_SLIT(" >= "), 0xfe07, {.d_i32 = a.len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
		if (start < 0) {
			Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("array.slice: slice bounds out of range ("), 0xfe07, {.d_i32 = start}}, {_SLIT(" < 0)"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	int offset = start * a.element_size;
	byte* data = ((byte*)(a.data)) + offset;
	int l = end - start;
	array res = (array){.element_size = a.element_size,.data = data,.offset = a.offset + offset,.len = l,.cap = l,.flags = 0,};
	return res;
}

VV_LOCAL_SYMBOL array array_slice2(array a, int start, int _end, bool end_max) {
	int end = (end_max ? (a.len) : (_end));
	return array_slice(a, start, end);
}

VV_LOCAL_SYMBOL array array_clone_static_to_depth(array a, int depth) {
	return array_clone_to_depth(&a, depth);
}

array array_clone(array* a) {
	return array_clone_to_depth(a, 0);
}

// Attr: [unsafe]
array array_clone_to_depth(array* a, int depth) {
	int size = a->cap * a->element_size;
	if (size == 0) {
		size++;
	}
	array arr = (array){.element_size = a->element_size,.data = vcalloc(size),.offset = 0,.len = a->len,.cap = a->cap,.flags = 0,};
	if (depth > 0 && _us32_eq(sizeof(array),a->element_size) && a->len >= 0 && a->cap >= a->len) {
		for (int i = 0; i < a->len; ++i) {
			array ar = (array){.element_size = 0,.data = 0,.offset = 0,.len = 0,.cap = 0,.flags = 0,};
			vmemcpy(&ar, array_get_unsafe(/*rec*/*a, i), ((int)(sizeof(array))));
			array ar_clone = array_clone_to_depth(&ar, depth - 1);
			array_set_unsafe(&arr, i, &ar_clone);
		}
		return arr;
	} else {
		if (!isnil(a->data)) {
			vmemcpy(((byte*)(arr.data)), a->data, a->cap * a->element_size);
		}
		return arr;
	}
	return (array){.element_size = 0,.data = 0,.offset = 0,.len = 0,.cap = 0,};
}

// Attr: [inline]
// Attr: [unsafe]
inline VV_LOCAL_SYMBOL void array_set_unsafe(array* a, int i, voidptr val) {
	vmemcpy(((byte*)(a->data)) + a->element_size * i, val, a->element_size);
}

VV_LOCAL_SYMBOL void array_set(array* a, int i, voidptr val) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i >= a->len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("array.set: index out of range (i == "), 0xfe07, {.d_i32 = i}}, {_SLIT(", a.len == "), 0xfe07, {.d_i32 = a->len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	vmemcpy(((byte*)(a->data)) + a->element_size * i, val, a->element_size);
}

VV_LOCAL_SYMBOL void array_push(array* a, voidptr val) {
	array_ensure_cap(a, a->len + 1);
	vmemmove(((byte*)(a->data)) + a->element_size * a->len, val, a->element_size);
	a->len++;
}

// Attr: [unsafe]
void array_push_many(array* a3, voidptr val, int size) {
	if (a3->data == val && !isnil(a3->data)) {
		array copy = array_clone(a3);
		array_ensure_cap(a3, a3->len + size);
		vmemcpy(array_get_unsafe(/*rec*/*a3, a3->len), copy.data, a3->element_size * size);
	} else {
		array_ensure_cap(a3, a3->len + size);
		if (!isnil(a3->data) && !isnil(val)) {
			vmemcpy(array_get_unsafe(/*rec*/*a3, a3->len), val, a3->element_size * size);
		}
	}
	a3->len += size;
}

void array_reverse_in_place(array* a) {
	if (a->len < 2) {
		return;
	}
	{ // Unsafe block
		byte* tmp_value = Dmalloc(a->element_size);
		for (int i = 0; i < a->len / 2; ++i) {
			vmemcpy(tmp_value, ((byte*)(a->data)) + i * a->element_size, a->element_size);
			vmemcpy(((byte*)(a->data)) + i * a->element_size, ((byte*)(a->data)) + (a->len - 1 - i) * a->element_size, a->element_size);
			vmemcpy(((byte*)(a->data)) + (a->len - 1 - i) * a->element_size, tmp_value, a->element_size);
		}
		Dfree(tmp_value);
	}
}

array array_reverse(array a) {
	if (a.len < 2) {
		return a;
	}
	array arr = (array){.element_size = a.element_size,.data = vcalloc(a.cap * a.element_size),.offset = 0,.len = a.len,.cap = a.cap,.flags = 0,};
	for (int i = 0; i < a.len; ++i) {
		array_set_unsafe(&arr, i, array_get_unsafe(a, a.len - 1 - i));
	}
	return arr;
}

// Attr: [unsafe]
void array_free(array* a) {
	byte* mblock_ptr = ((byte*)(((u64)(a->data)) - ((u64)(a->offset))));
	Dfree(mblock_ptr);
}

array array_filter(array a, bool (*predicate)(voidptr ));

bool array_any(array a, bool (*predicate)(voidptr ));

bool array_all(array a, bool (*predicate)(voidptr ));

array array_map(array a, voidptr (*callback)(voidptr ));

void array_sort(array* a, int (*callback)(voidptr , voidptr ));

bool array_contains(array a, voidptr val);

int array_index(array a, voidptr value);

// Attr: [unsafe]
void Array_string_free(Array_string* a) {
	for (int _t1 = 0; _t1 < a->len; ++_t1) {
		string s = ((string*)a->data)[_t1];
		string_free(&s);
	}
	array_free((((array*)(a))));
}

// Attr: [manualfree]
string Array_string_str(Array_string a) {
	int sb_len = 4;
	if (a.len > 0) {
		sb_len += (*(string*)/*ee elem_typ */array_get(a, 0)).len;
		sb_len *= a.len;
	}
	sb_len += 2;
	strings__Builder sb = strings__new_builder(sb_len);
	strings__Builder_write_b(&sb, '[');
	for (int i = 0; i < a.len; ++i) {
		string val = (*(string*)/*ee elem_typ */array_get(a, i));
		strings__Builder_write_b(&sb, '\'');
		strings__Builder_write_string(&sb, val);
		strings__Builder_write_b(&sb, '\'');
		if (i < a.len - 1) {
			strings__Builder_write_string(&sb, _SLIT(", "));
		}
	}
	strings__Builder_write_b(&sb, ']');
	string res = strings__Builder_str(&sb);
	strings__Builder_free(&sb);
	return res;
}

string Array_byte_hex(Array_byte b) {
	byte* hex = Dmalloc(b.len * 2 + 1);
	int dst_i = 0;
	for (int _t1 = 0; _t1 < b.len; ++_t1) {
		byte i = ((byte*)b.data)[_t1];
		byte n0 = i >> 4;
		{ // Unsafe block
			hex[dst_i] = (n0 < 10 ? (n0 + '0') : (n0 + ((byte)(87))));
			dst_i++;
		}
		byte n1 = (i & 0xF);
		{ // Unsafe block
			hex[dst_i] = (n1 < 10 ? (n1 + '0') : (n1 + ((byte)(87))));
			dst_i++;
		}
	}
	{ // Unsafe block
		hex[dst_i] = 0;
		return tos(hex, dst_i);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

int copy(Array_byte dst, Array_byte src) {
	int min = (dst.len < src.len ? (dst.len) : (src.len));
	if (min > 0) {
		vmemcpy(((byte*)(dst.data)), src.data, min);
	}
	return min;
}

int Array_int_reduce(Array_int a, int (*iter)(int , int ), int accum_start) {
	int accum_ = accum_start;
	for (int _t1 = 0; _t1 < a.len; ++_t1) {
		int i = ((int*)a.data)[_t1];
		accum_ = iter(accum_, i);
	}
	return accum_;
}

void array_grow_cap(array* a, int amount) {
	array_ensure_cap(a, a->cap + amount);
}

// Attr: [unsafe]
void array_grow_len(array* a, int amount) {
	array_ensure_cap(a, a->len + amount);
	a->len += amount;
}

// Attr: [unsafe]
Array_voidptr array_pointers(array a) {
	Array_voidptr res = __new_array_with_default(0, 0, sizeof(voidptr), 0);
	for (int i = 0; i < a.len; ++i) {
		array_push((array*)&res, _MOV((voidptr[]){ array_get_unsafe(a, i) }));
	}
	return res;
}

// Attr: [unsafe]
Array_byte voidptr_vbytes(voidptr data, int len) {
	array res = (array){.element_size = 1,.data = data,.offset = 0,.len = len,.cap = len,.flags = 0,};
	return res;
}

// Attr: [unsafe]
Array_byte byte_vbytes(byte* data, int len) {
	return voidptr_vbytes(((voidptr)(data)), len);
}

// Attr: [inline]
inline bool ArrayFlags_is_empty(ArrayFlags* e) {
	return ((int)(*e)) == 0;
}

// Attr: [inline]
inline bool ArrayFlags_has(ArrayFlags* e, ArrayFlags flag) {
	return ((((int)(*e)) & (((int)(flag))))) != 0;
}

// Attr: [inline]
inline bool ArrayFlags_all(ArrayFlags* e, ArrayFlags flag) {
	return ((((int)(*e)) & (((int)(flag))))) == ((int)(flag));
}

// Attr: [inline]
inline void ArrayFlags_set(ArrayFlags* e, ArrayFlags flag) {
	{ // Unsafe block
		*e = ((ArrayFlags)((((int)(*e)) | (((int)(flag))))));
	}
}

// Attr: [inline]
inline void ArrayFlags_clear(ArrayFlags* e, ArrayFlags flag) {
	{ // Unsafe block
		*e = ((ArrayFlags)((((int)(*e)) & ~(((int)(flag))))));
	}
}

// Attr: [inline]
inline void ArrayFlags_toggle(ArrayFlags* e, ArrayFlags flag) {
	{ // Unsafe block
		*e = ((ArrayFlags)((((int)(*e)) ^ (((int)(flag))))));
	}
}

VV_LOCAL_SYMBOL array __new_array_noscan(int mylen, int cap, int elm_size) {
	return (array){.element_size = 0,.data = 0,.offset = 0,.len = 0,.cap = 0,.flags = 0,};
}

// TypeDecl
// Attr: [noreturn]
VNORETURN VV_LOCAL_SYMBOL void vhalt(void) {
	for (;;) {
	}
	while(1);
}

// Attr: [noreturn]
VNORETURN void Dexit(int code) {
	exit(code);
	VUNREACHABLE();
	while(1);
}

VV_LOCAL_SYMBOL string vcommithash(void) {
	return tos5(((char*)("1")));
}

// Attr: [noreturn]
VNORETURN VV_LOCAL_SYMBOL void panic_debug(int line_no, string file, string mod, string fn_name, string s) {
	#if defined(_VFREESTANDING)
	{
	}
	#else
	{
		eprintln(_SLIT("================ gnu c panic ================"));
		eprintln( str_intp(2, _MOV((StrIntpData[]){{_SLIT("   module: "), 0xfe10, {.d_s = mod}}, {_SLIT0, 0, { .d_c = 0 }}})));
		eprintln( str_intp(2, _MOV((StrIntpData[]){{_SLIT(" function: "), 0xfe10, {.d_s = fn_name}}, {_SLIT("()"), 0, { .d_c = 0 }}})));
		eprintln( str_intp(2, _MOV((StrIntpData[]){{_SLIT("  message: "), 0xfe10, {.d_s = s}}, {_SLIT0, 0, { .d_c = 0 }}})));
		eprintln( str_intp(3, _MOV((StrIntpData[]){{_SLIT("     file: "), 0xfe10, {.d_s = file}}, {_SLIT(":"), 0xfe07, {.d_i32 = line_no}}, {_SLIT0, 0, { .d_c = 0 }}})));
		eprintln(_SLIT("========================================="));
		#if defined(CUSTOM_DEFINE_exit_after_panic_message)
		{
		}
		#elif defined(CUSTOM_DEFINE_no_backtrace)
		{
		}
		#else
		{
			#if defined(__TINYC__)
			{
				#if defined(CUSTOM_DEFINE_panics_break_into_debugger)
				{
				}
				#else
				{
					tcc_backtrace("Backtrace");
				}
				#endif
				exit(1);
				VUNREACHABLE();
			}
			#endif
			print_backtrace_skipping_top_frames(1);
			exit(1);
			VUNREACHABLE();
		}
		#endif
	}
	#endif
	vhalt();
	VUNREACHABLE();
	while(1);
}

// Attr: [noreturn]
VNORETURN void panic_optional_not_set(string s) {
	Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("optional not set ("), 0xfe10, {.d_s = s}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
	VUNREACHABLE();
	while(1);
}

// Attr: [noreturn]
VNORETURN void Dpanic(string s) {
	#if defined(_VFREESTANDING)
	{
	}
	#else
	{
		eprint(_SLIT("gnu c panic: "));
		eprintln(s);
		#if defined(CUSTOM_DEFINE_exit_after_panic_message)
		{
		}
		#elif defined(CUSTOM_DEFINE_no_backtrace)
		{
		}
		#else
		{
			#if defined(__TINYC__)
			{
				#if defined(CUSTOM_DEFINE_panics_break_into_debugger)
				{
				}
				#else
				{
					tcc_backtrace("Backtrace");
				}
				#endif
				exit(1);
				VUNREACHABLE();
			}
			#endif
			print_backtrace_skipping_top_frames(1);
			exit(1);
			VUNREACHABLE();
		}
		#endif
	}
	#endif
	vhalt();
	VUNREACHABLE();
	while(1);
}

string c_error_number_str(int errnum) {
	string err_msg = _SLIT("");
	#if defined(_VFREESTANDING)
	{
	}
	#else
	{
		#if !defined(__vinix__)
		{
			char* c_msg = strerror(errnum);
			err_msg = (string){.str = ((byte*)(c_msg)), .len = strlen(c_msg), .is_lit = 1};
		}
		#endif
	}
	#endif
	return err_msg;
}

// Attr: [noreturn]
VNORETURN void panic_error_number(string basestr, int errnum) {
	Dpanic(string__plus(basestr, c_error_number_str(errnum)));
	VUNREACHABLE();
	while(1);
}

void eprintln(string s) {
	if (s.str == 0) {
		eprintln(_SLIT("eprintln(NIL)"));
		return;
	}
	#if defined(_VFREESTANDING)
	{
	}
	#elif defined(__TARGET_IOS__)
	{
	}
	#else
	{
		fflush(stdout);
		fflush(stderr);
		_writeln_to_fd(2, s);
		fflush(stderr);
	}
	#endif
}

void eprint(string s) {
	if (s.str == 0) {
		eprint(_SLIT("eprint(NIL)"));
		return;
	}
	#if defined(_VFREESTANDING)
	{
	}
	#elif defined(__TARGET_IOS__)
	{
	}
	#else
	{
		fflush(stdout);
		fflush(stderr);
		_write_buf_to_fd(2, s.str, s.len);
		fflush(stderr);
	}
	#endif
}

// Attr: [manualfree]
void print(string s) {
	#if defined(__TARGET_IOS__)
	{
	}
	#elif defined(_VFREESTANDING)
	{
	}
	#else
	{
		_write_buf_to_fd(1, s.str, s.len);
	}
	#endif
}

// Attr: [manualfree]
void println(string s) {
	if (s.str == 0) {
		println(_SLIT("println(NIL)"));
		return;
	}
	#if defined(__TARGET_IOS__)
	{
	}
	#elif defined(_VFREESTANDING)
	{
	}
	#else
	{
		_writeln_to_fd(1, s);
	}
	#endif
}

// Attr: [manualfree]
VV_LOCAL_SYMBOL void _writeln_to_fd(int fd, string s) {
bool _writeln_to_fd_defer_0 = false;
byte* buf;
	{ // Unsafe block
		int buf_len = s.len + 1;
		buf = Dmalloc(buf_len);
		_writeln_to_fd_defer_0 = true;
		memcpy(buf, s.str, s.len);
		buf[s.len] = '\n';
		_write_buf_to_fd(fd, buf, buf_len);
	}
// Defer begin
if (_writeln_to_fd_defer_0) {
	Dfree(buf);
}
// Defer end
}

// Attr: [manualfree]
VV_LOCAL_SYMBOL void _write_buf_to_fd(int fd, byte* buf, int buf_len) {
	if (buf_len <= 0) {
		return;
	}
	{ // Unsafe block
		byte* ptr = buf;
		int remaining_bytes = buf_len;
		for (;;) {
			if (!(remaining_bytes > 0)) break;
			int x = write(fd, ptr, remaining_bytes);
			ptr += x;
			remaining_bytes -= x;
		}
	}
}

// Attr: [unsafe]
byte* Dmalloc(int n) {
	if (n <= 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("malloc("), 0xfe07, {.d_i32 = n}}, {_SLIT(" <= 0)"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	byte* res = ((byte*)(0));
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#elif defined(_VFREESTANDING)
	{
	}
	#else
	{
		res = malloc(n);
	}
	#endif
	if (res == 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("malloc("), 0xfe07, {.d_i32 = n}}, {_SLIT(") failed"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	return res;
}

// Attr: [unsafe]
byte* malloc_noscan(int n) {
	if (n <= 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("malloc_noscan("), 0xfe07, {.d_i32 = n}}, {_SLIT(" <= 0)"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	byte* res = ((byte*)(0));
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#elif defined(_VFREESTANDING)
	{
	}
	#else
	{
		res = malloc(n);
	}
	#endif
	if (res == 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("malloc_noscan("), 0xfe07, {.d_i32 = n}}, {_SLIT(") failed"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	return res;
}

// Attr: [unsafe]
byte* v_realloc(byte* b, int n) {
	byte* new_ptr = ((byte*)(0));
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#else
	{
		new_ptr = realloc(b, n);
	}
	#endif
	if (new_ptr == 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("realloc("), 0xfe07, {.d_i32 = n}}, {_SLIT(") failed"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	return new_ptr;
}

// Attr: [unsafe]
byte* realloc_data(byte* old_data, int old_size, int new_size) {
	byte* nptr = ((byte*)(0));
	#if defined(_VGCBOEHM)
	{
	}
	#else
	{
		nptr = realloc(old_data, new_size);
	}
	#endif
	if (nptr == 0) {
		Dpanic( str_intp(4, _MOV((StrIntpData[]){{_SLIT("realloc_data("), 0xfe11, {.d_p = (void*)(old_data)}}, {_SLIT(", "), 0xfe07, {.d_i32 = old_size}}, {_SLIT(", "), 0xfe07, {.d_i32 = new_size}}, {_SLIT(") failed"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	return nptr;
}

byte* vcalloc(int n) {
	if (n < 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("calloc("), 0xfe07, {.d_i32 = n}}, {_SLIT(" < 0)"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	} else if (n == 0) {
		return ((byte*)(0));
	}
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#else
	{
		return calloc(1, n);
	}
	#endif
	return 0;
}

byte* vcalloc_noscan(int n) {
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#else
	{
		return vcalloc(n);
	}
	#endif
	return 0;
}

// Attr: [unsafe]
void Dfree(voidptr ptr) {
	#if defined(_VPREALLOC)
	{
	}
	#elif defined(_VGCBOEHM)
	{
	}
	#else
	{
		free(ptr);
	}
	#endif
}

// Attr: [unsafe]
voidptr memdup(voidptr src, int sz) {
	if (sz == 0) {
		return vcalloc(1);
	}
	{ // Unsafe block
		byte* mem = Dmalloc(sz);
		return memcpy(mem, src, sz);
	}
	return 0;
}

// Attr: [unsafe]
voidptr memdup_noscan(voidptr src, int sz) {
	if (sz == 0) {
		return vcalloc_noscan(1);
	}
	{ // Unsafe block
		byte* mem = malloc_noscan(sz);
		return memcpy(mem, src, sz);
	}
	return 0;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL int v_fixed_index(int i, int len) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (i < 0 || i >= len) {
			string s =  str_intp(3, _MOV((StrIntpData[]){{_SLIT("fixed array index out of range (index: "), 0xfe07, {.d_i32 = i}}, {_SLIT(", len: "), 0xfe07, {.d_i32 = len}}, {_SLIT(")"), 0, { .d_c = 0 }}}));
			Dpanic(s);
			VUNREACHABLE();
		}
	}
	#endif
	return i;
}

void print_backtrace(void) {
	#if !defined(CUSTOM_DEFINE_no_backtrace)
	{
		#if defined(_VFREESTANDING)
		{
		}
		#else
		{
			#if defined(__TINYC__)
			{
				tcc_backtrace("Backtrace");
			}
			#else
			{
			}
			#endif
		}
		#endif
	}
	#endif
}

// Attr: [inline]
inline bool isnil(voidptr v) {
	return v == 0;
}

VV_LOCAL_SYMBOL voidptr __as_cast(voidptr obj, int obj_type, int expected_type) {
	if (obj_type != expected_type) {
		string obj_name = string_clone((*(VCastTypeIndexName*)/*ee elem_typ */array_get(as_cast_type_indexes, 0)).tname);
		string expected_name = string_clone((*(VCastTypeIndexName*)/*ee elem_typ */array_get(as_cast_type_indexes, 0)).tname);
		for (int _t1 = 0; _t1 < as_cast_type_indexes.len; ++_t1) {
			VCastTypeIndexName x = ((VCastTypeIndexName*)as_cast_type_indexes.data)[_t1];
			if (x.tindex == obj_type) {
				obj_name = string_clone(x.tname);
			}
			if (x.tindex == expected_type) {
				expected_name = string_clone(x.tname);
			}
		}
		Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("as cast: cannot cast `"), 0xfe10, {.d_s = obj_name}}, {_SLIT("` to `"), 0xfe10, {.d_s = expected_name}}, {_SLIT("`"), 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	}
	return obj;
}

// Attr: [manualfree]
// Attr: [unsafe]
void VAssertMetaInfo_free(VAssertMetaInfo* ami) {
	{ // Unsafe block
		string_free(&ami->fpath);
		string_free(&ami->fn_name);
		string_free(&ami->src);
		string_free(&ami->op);
		string_free(&ami->llabel);
		string_free(&ami->rlabel);
		string_free(&ami->lvalue);
		string_free(&ami->rvalue);
	}
}

VV_LOCAL_SYMBOL void __print_assert_failure(VAssertMetaInfo* i) {
	eprintln( str_intp(5, _MOV((StrIntpData[]){{_SLIT0, 0xfe10, {.d_s = i->fpath}}, {_SLIT(":"), 0xfe07, {.d_i32 = i->line_nr + 1}}, {_SLIT(": FAIL: fn "), 0xfe10, {.d_s = i->fn_name}}, {_SLIT(": assert "), 0xfe10, {.d_s = i->src}}, {_SLIT0, 0, { .d_c = 0 }}})));
	if (i->op.len > 0 && !string__eq(i->op, _SLIT("call"))) {
		eprintln( str_intp(3, _MOV((StrIntpData[]){{_SLIT("   left value: "), 0xfe10, {.d_s = i->llabel}}, {_SLIT(" = "), 0xfe10, {.d_s = i->lvalue}}, {_SLIT0, 0, { .d_c = 0 }}})));
		if (string__eq(i->rlabel, i->rvalue)) {
			eprintln( str_intp(2, _MOV((StrIntpData[]){{_SLIT("  right value: "), 0xfe10, {.d_s = i->rlabel}}, {_SLIT0, 0, { .d_c = 0 }}})));
		} else {
			eprintln( str_intp(3, _MOV((StrIntpData[]){{_SLIT("  right value: "), 0xfe10, {.d_s = i->rlabel}}, {_SLIT(" = "), 0xfe10, {.d_s = i->rvalue}}, {_SLIT0, 0, { .d_c = 0 }}})));
		}
	}
}

// Attr: [used]
VV_LOCAL_SYMBOL void v_segmentation_fault_handler(int signal) {
	eprintln(_SLIT("signal 11: segmentation fault"));
	print_backtrace();
	Dexit(128 + 11);
	VUNREACHABLE();
}

VV_LOCAL_SYMBOL void builtin_init(void) {
}

VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames(int xskipframes) {
	#if defined(CUSTOM_DEFINE_no_backtrace)
	{
	}
	#else
	{
		int skipframes = xskipframes + 2;
		#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
		{
		}
		#elif defined(__linux__)
		{
			return print_backtrace_skipping_top_frames_linux(skipframes);
		}
		#else
		{
		}
		#endif
	}
	#endif
	return false;
}

VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames_bsd(int skipframes) {
	#if defined(CUSTOM_DEFINE_no_backtrace)
	{
	}
	#else
	{
		return true;
	}
	#endif
	return 0;
}

VV_LOCAL_SYMBOL bool print_backtrace_skipping_top_frames_linux(int skipframes) {
	#if defined(CUSTOM_DEFINE_no_backtrace)
	{
	}
	#else
	{
		#if defined(__linux__) && !defined(_VFREESTANDING)
		{
			#if defined(__TINYC__)
			{
				tcc_backtrace("Backtrace");
				return false;
			}
			#endif
			Array_fixed_voidptr_100 buffer = {0};
			int nr_ptrs = backtrace(&buffer[0], 100);
			if (nr_ptrs < 2) {
				eprintln(_SLIT("C.backtrace returned less than 2 frames"));
				return false;
			}
			int nr_actual_frames = nr_ptrs - skipframes;
			Array_string sframes = __new_array_with_default(0, 0, sizeof(string), 0);
			char** csymbols = backtrace_symbols(((voidptr)(&buffer[v_fixed_index(skipframes, 100)])), nr_actual_frames);
			for (int i = 0; i < nr_actual_frames; ++i) {
				array_push((array*)&sframes, _MOV((string[]){ tos2(((byte*)(csymbols[i]))) }));
			}
			for (int _t4 = 0; _t4 < sframes.len; ++_t4) {
				string sframe = ((string*)sframes.data)[_t4];
				string executable = string_all_before(sframe, _SLIT("("));
				string addr = string_all_before(string_all_after(sframe, _SLIT("[")), _SLIT("]"));
				string beforeaddr = string_all_before(sframe, _SLIT("["));
				string cmd =  str_intp(3, _MOV((StrIntpData[]){{_SLIT("addr2line -e "), 0xfe10, {.d_s = executable}}, {_SLIT(" "), 0xfe10, {.d_s = addr}}, {_SLIT0, 0, { .d_c = 0 }}}));
				voidptr f = popen(((char*)(cmd.str)), "r");
				if (isnil(f)) {
					eprintln(sframe);
					continue;
				}
				Array_fixed_byte_1000 buf = {0};
				string output = _SLIT("");
				{ // Unsafe block
					byte* bp = &buf[0];
					for (;;) {
						if (!(fgets(((char*)(bp)), 1000, f) != 0)) break;
						output = /*f*/string__plus(output, tos(bp, vstrlen(bp)));
					}
				}
				output = string__plus(string_trim_space(output), _SLIT(":"));
				if (pclose(f) != 0) {
					eprintln(sframe);
					continue;
				}
				if (string__eq(output, _SLIT("??:0:")) || string__eq(output, _SLIT("??:?:"))) {
					output = _SLIT("");
				}
				output = string_replace(output, _SLIT(" (discriminator"), _SLIT(": (d."));
				eprintln( str_intp(4, _MOV((StrIntpData[]){{_SLIT0, 0x6efe10, {.d_s = output}}, {_SLIT(" | "), 0x1cfe30, {.d_s = addr}}, {_SLIT(" | "), 0xfe10, {.d_s = beforeaddr}}, {_SLIT0, 0, { .d_c = 0 }}})));
			}
		}
		#endif
	}
	#endif
	return true;
}

VV_LOCAL_SYMBOL void break_if_debugger_attached(void) {
	{ // Unsafe block
		voidptr* ptr = ((voidptr*)(0));
		*ptr = ((voidptr)(0));
	}
}

string winapi_lasterr_str(void) {
	return _SLIT("");
}

// Attr: [noreturn]
VNORETURN void panic_lasterr(void) {
	while(1);
}

void gc_check_leaks(void) {
}

// Attr: [trusted]
// Attr: [noreturn]
// Attr: [trusted]
// Attr: [trusted]
int proc_pidpath(int , voidptr , int );

// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [trusted]
// Attr: [inline]
// Attr: [unsafe]
inline int vstrlen(byte* s) {
	return strlen(((char*)(s)));
}

// Attr: [inline]
// Attr: [unsafe]
inline int vstrlen_char(char* s) {
	return strlen(s);
}

// Attr: [inline]
// Attr: [unsafe]
inline voidptr vmemcpy(voidptr dest, const voidptr const_src, int n) {
	{ // Unsafe block
		return memcpy(dest, const_src, n);
	}
	return 0;
}

// Attr: [inline]
// Attr: [unsafe]
inline voidptr vmemmove(voidptr dest, const voidptr const_src, int n) {
	{ // Unsafe block
		return memmove(dest, const_src, n);
	}
	return 0;
}

// Attr: [inline]
// Attr: [unsafe]
inline int vmemcmp(const voidptr const_s1, const voidptr const_s2, int n) {
	{ // Unsafe block
		return memcmp(const_s1, const_s2, n);
	}
	return 0;
}

// Attr: [inline]
// Attr: [unsafe]
inline voidptr vmemset(voidptr s, int c, int n) {
	{ // Unsafe block
		return memset(s, c, n);
	}
	return 0;
}

// TypeDecl
// Attr: [inline]
// Attr: [unsafe]
inline VV_LOCAL_SYMBOL void vqsort(voidptr base, usize nmemb, usize size, int (*sort_cb)(const voidptr const_a, const voidptr const_b)) {
	qsort(base, nmemb, size, ((voidptr)(sort_cb)));
}

void chan_close(chan ch) {
}

ChanState chan_try_pop(chan ch, voidptr obj) {
	return ChanState__success;
}

ChanState chan_try_push(chan ch, voidptr obj) {
	return ChanState__success;
}

// Attr: [inline]
inline string f64_str(f64 x) {
	{ // Unsafe block
		strconv__Float64u f = (strconv__Float64u){.f = x,};
		if (f.u == _const_strconv__double_minus_zero) {
			return _SLIT("-0");
		}
		if (f.u == _const_strconv__double_plus_zero) {
			return _SLIT("0");
		}
	}
	f64 abs_x = f64_abs(x);
	if (abs_x >= 0.0001 && abs_x < 1.0e6) {
		return strconv__f64_to_str_l(x);
	} else {
		return strconv__ftoa_64(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string f64_strg(f64 x) {
	if (x == 0) {
		return _SLIT("0");
	}
	f64 abs_x = f64_abs(x);
	if (abs_x >= 0.0001 && abs_x < 1.0e6) {
		return strconv__f64_to_str_l_no_dot(x);
	} else {
		return strconv__ftoa_64(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string float_literal_str(float_literal d) {
	return f64_str(((f64)(d)));
}

// Attr: [inline]
inline string f64_strsci(f64 x, int digit_num) {
	int n_digit = digit_num;
	if (n_digit < 1) {
		n_digit = 1;
	} else if (n_digit > 17) {
		n_digit = 17;
	}
	return strconv__f64_to_str(x, n_digit);
}

// Attr: [inline]
inline string f64_strlong(f64 x) {
	return strconv__f64_to_str_l(x);
}

// Attr: [inline]
inline string f32_str(f32 x) {
	{ // Unsafe block
		strconv__Float32u f = (strconv__Float32u){.f = x,};
		if (f.u == _const_strconv__single_minus_zero) {
			return _SLIT("-0");
		}
		if (f.u == _const_strconv__single_plus_zero) {
			return _SLIT("0");
		}
	}
	f32 abs_x = f32_abs(x);
	if (abs_x >= 0.0001 && abs_x < 1.0e6) {
		return strconv__f32_to_str_l(x);
	} else {
		return strconv__ftoa_32(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string f32_strg(f32 x) {
	if (x == 0) {
		return _SLIT("0");
	}
	f32 abs_x = f32_abs(x);
	if (abs_x >= 0.0001 && abs_x < 1.0e6) {
		return strconv__f32_to_str_l_no_dot(x);
	} else {
		return strconv__ftoa_32(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string f32_strsci(f32 x, int digit_num) {
	int n_digit = digit_num;
	if (n_digit < 1) {
		n_digit = 1;
	} else if (n_digit > 8) {
		n_digit = 8;
	}
	return strconv__f32_to_str(x, n_digit);
}

// Attr: [inline]
inline string f32_strlong(f32 x) {
	return strconv__f32_to_str_l(x);
}

// Attr: [inline]
inline f32 f32_abs(f32 a) {
	return (a < 0 ? (-a) : (a));
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL f64 f64_abs(f64 a) {
	return (a < 0 ? (-a) : (a));
}

// Attr: [inline]
inline f32 f32_max(f32 a, f32 b) {
	return (a > b ? (a) : (b));
}

// Attr: [inline]
inline f32 f32_min(f32 a, f32 b) {
	return (a < b ? (a) : (b));
}

// Attr: [inline]
inline f64 f64_max(f64 a, f64 b) {
	return (a > b ? (a) : (b));
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL f64 f64_min(f64 a, f64 b) {
	return (a < b ? (a) : (b));
}

// Attr: [inline]
inline bool f32_eq_epsilon(f32 a, f32 b) {
	f32 hi = f32_max(f32_abs(a), f32_abs(b));
	f32 delta = f32_abs(a - b);
	if (hi > ((f32)(1.0))) {
		return delta <= hi * (4 * ((f32)(FLT_EPSILON)));
	} else {
		return (1 / (4 * ((f32)(FLT_EPSILON)))) * delta <= hi;
	}
	return 0;
}

// Attr: [inline]
inline bool f64_eq_epsilon(f64 a, f64 b) {
	f64 hi = f64_max(f64_abs(a), f64_abs(b));
	f64 delta = f64_abs(a - b);
	if (hi > 1.0) {
		return delta <= hi * (4 * ((f64)(DBL_EPSILON)));
	} else {
		return (1 / (4 * ((f64)(DBL_EPSILON)))) * delta <= hi;
	}
	return 0;
}

VV_LOCAL_SYMBOL void float_test(void) {
}

// TypeDecl
// TypeDecl
string ptr_str(voidptr ptr) {
	string buf1 = u64_hex(((u64)(ptr)));
	return buf1;
}

string isize_str(isize x) {
	return i64_str(((i64)(x)));
}

string usize_str(usize x) {
	return u64_str(((u64)(x)));
}

string char_str(char* cptr) {
	return u64_hex(((u64)(cptr)));
}

// Attr: [direct_array_access]
// Attr: [inline]
inline VV_LOCAL_SYMBOL string int_str_l(int nn, int max) {
	{ // Unsafe block
		i64 n = ((i64)(nn));
		int d = 0;
		if (n == 0) {
			return _SLIT("0");
		}
		bool is_neg = false;
		if (n < 0) {
			n = -n;
			is_neg = true;
		}
		int index = max;
		byte* buf = malloc_noscan(max + 1);
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			int n1 = ((int)(n / 100));
			d = ((int)(((u32)(((int)(n)) - (n1 * 100))) << 1U));
			n = n1;
			buf[index] = _const_digit_pairs.str[d];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[d];
			index--;
		}
		index++;
		if (d < 20) {
			index++;
		}
		if (is_neg) {
			index--;
			buf[index] = '-';
		}
		int diff = max - index;
		vmemmove(buf, buf + index, diff + 1);
		return tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

string i8_str(i8 n) {
	return int_str_l(((int)(n)), 5);
}

string i16_str(i16 n) {
	return int_str_l(((int)(n)), 7);
}

string u16_str(u16 n) {
	return int_str_l(((int)(n)), 7);
}

string int_str(int n) {
	return int_str_l(n, 12);
}

// Attr: [direct_array_access]
// Attr: [inline]
inline string u32_str(u32 nn) {
	{ // Unsafe block
		u32 n = nn;
		u32 d = ((u32)(0U));
		if (n == 0U) {
			return _SLIT("0");
		}
		int max = 12;
		byte* buf = malloc_noscan(max + 1);
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0U)) break;
			u32 n1 = n / ((u32)(100U));
			d = ((n - (n1 * ((u32)(100U)))) << ((u32)(1U)));
			n = n1;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
		}
		index++;
		if (d < ((u32)(20U))) {
			index++;
		}
		int diff = max - index;
		vmemmove(buf, buf + index, diff + 1);
		return tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline string int_literal_str(int_literal n) {
	return i64_str(((i64)(n)));
}

// Attr: [direct_array_access]
// Attr: [inline]
inline string i64_str(i64 nn) {
	{ // Unsafe block
		i64 n = nn;
		i64 d = ((i64)(0));
		if (n == 0) {
			return _SLIT("0");
		}
		int max = 20;
		byte* buf = malloc_noscan(max + 1);
		bool is_neg = false;
		if (n < 0) {
			n = -n;
			is_neg = true;
		}
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			i64 n1 = n / ((i64)(100));
			d = (((u32)(n - (n1 * ((i64)(100))))) << ((i64)(1)));
			n = n1;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
		}
		index++;
		if (d < ((i64)(20))) {
			index++;
		}
		if (is_neg) {
			index--;
			buf[index] = '-';
		}
		int diff = max - index;
		vmemmove(buf, buf + index, diff + 1);
		return tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
// Attr: [inline]
inline string u64_str(u64 nn) {
	{ // Unsafe block
		u64 n = nn;
		u64 d = ((u64)(0U));
		if (n == 0U) {
			return _SLIT("0");
		}
		int max = 20;
		byte* buf = malloc_noscan(max + 1);
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0U)) break;
			u64 n1 = n / 100U;
			d = ((n - (n1 * 100U)) << 1U);
			n = n1;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ d];
			index--;
		}
		index++;
		if (d < 20U) {
			index++;
		}
		int diff = max - index;
		vmemmove(buf, buf + index, diff + 1);
		return tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

string bool_str(bool b) {
	if (b) {
		return _SLIT("true");
	}
	return _SLIT("false");
}

// Attr: [direct_array_access]
// Attr: [inline]
inline VV_LOCAL_SYMBOL string u64_to_hex(u64 nn, byte len) {
	u64 n = nn;
	Array_fixed_byte_17 buf = {0};
	buf[len] = 0;
	int i = 0;
	for (i = len - 1; i >= 0; i--) {
		byte d = ((byte)((n & 0xFU)));
		buf[i] = (d < 10 ? (d + '0') : (d + 87));
		n = n >> 4U;
	}
	return tos(memdup(&buf[0], len + 1), len);
}

// Attr: [direct_array_access]
// Attr: [inline]
inline VV_LOCAL_SYMBOL string u64_to_hex_no_leading_zeros(u64 nn, byte len) {
	u64 n = nn;
	Array_fixed_byte_17 buf = {0};
	buf[len] = 0;
	int i = 0;
	for (i = len - 1; i >= 0; i--) {
		byte d = ((byte)((n & 0xFU)));
		buf[i] = (d < 10 ? (d + '0') : (d + 87));
		n = n >> 4U;
		if (n == 0U) {
			break;
		}
	}
	int res_len = len - i;
	return tos(memdup(&buf[i], res_len + 1), res_len);
}

string byte_hex(byte nn) {
	if (nn == 0) {
		return _SLIT("00");
	}
	return u64_to_hex(nn, 2);
}

string i8_hex(i8 nn) {
	if (nn == 0) {
		return _SLIT("00");
	}
	return u64_to_hex(((u64)(nn)), 2);
}

string u16_hex(u16 nn) {
	if (nn == 0U) {
		return _SLIT("0");
	}
	return u64_to_hex_no_leading_zeros(nn, 4);
}

string i16_hex(i16 nn) {
	return u16_hex(((u16)(nn)));
}

string u32_hex(u32 nn) {
	if (nn == 0U) {
		return _SLIT("0");
	}
	return u64_to_hex_no_leading_zeros(nn, 8);
}

string int_hex(int nn) {
	return u32_hex(((u32)(nn)));
}

string int_hex2(int n) {
	return string__plus(_SLIT("0x"), int_hex(n));
}

string u64_hex(u64 nn) {
	if (nn == 0U) {
		return _SLIT("0");
	}
	return u64_to_hex_no_leading_zeros(nn, 16);
}

string i64_hex(i64 nn) {
	return u64_hex(((u64)(nn)));
}

string int_literal_hex(int_literal nn) {
	return u64_hex(((u64)(nn)));
}

string voidptr_str(voidptr nn) {
	return u64_hex(((u64)(nn)));
}

string byteptr_str(byteptr nn) {
	return u64_hex(((u64)(nn)));
}

string byte_hex_full(byte nn) {
	return u64_to_hex(((u64)(nn)), 2);
}

string i8_hex_full(i8 nn) {
	return u64_to_hex(((u64)(nn)), 2);
}

string u16_hex_full(u16 nn) {
	return u64_to_hex(((u64)(nn)), 4);
}

string i16_hex_full(i16 nn) {
	return u64_to_hex(((u64)(nn)), 4);
}

string u32_hex_full(u32 nn) {
	return u64_to_hex(((u64)(nn)), 8);
}

string int_hex_full(int nn) {
	return u64_to_hex(((u64)(nn)), 8);
}

string i64_hex_full(i64 nn) {
	return u64_to_hex(((u64)(nn)), 16);
}

string voidptr_hex_full(voidptr nn) {
	return u64_to_hex(((u64)(nn)), 16);
}

string int_literal_hex_full(int_literal nn) {
	return u64_to_hex(((u64)(nn)), 16);
}

string u64_hex_full(u64 nn) {
	return u64_to_hex(nn, 16);
}

string byte_str(byte b) {
	return int_str_l(((int)(b)), 7);
}

string byte_ascii_str(byte b) {
	string str = (string){.str = malloc_noscan(2), .len = 1};
	{ // Unsafe block
		str.str[0] = b;
		str.str[1] = 0;
	}
	return str;
}

string byte_str_escaped(byte b) {
	string _t1 = (string){.str=(byteptr)"", .is_lit=1};
	
	if (b == (0)) {
		_t1 = _SLIT("`\\0`");
	}
	else if (b == (7)) {
		_t1 = _SLIT("`\\a`");
	}
	else if (b == (8)) {
		_t1 = _SLIT("`\\b`");
	}
	else if (b == (9)) {
		_t1 = _SLIT("`\\t`");
	}
	else if (b == (10)) {
		_t1 = _SLIT("`\\n`");
	}
	else if (b == (11)) {
		_t1 = _SLIT("`\\v`");
	}
	else if (b == (12)) {
		_t1 = _SLIT("`\\f`");
	}
	else if (b == (13)) {
		_t1 = _SLIT("`\\r`");
	}
	else if (b == (27)) {
		_t1 = _SLIT("`\\e`");
	}
	else if ((b >= 32 && b <= 126)) {
		_t1 = byte_ascii_str(b);
	}
	else {
		_t1 = string__plus(_SLIT("0x"), byte_hex(b));
	}string str = _t1;
	return str;
}

// Attr: [inline]
inline bool byte_is_capital(byte c) {
	return c >= 'A' && c <= 'Z';
}

Array_byte Array_byte_clone(Array_byte b) {
	Array_byte res = __new_array_with_default(b.len, 0, sizeof(byte), 0);
	for (int i = 0; i < b.len; ++i) {
		array_set(&res, i, &(byte[]) { (*(byte*)/*ee elem_typ */array_get(b, i)) });
	}
	return res;
}

string Array_byte_bytestr(Array_byte b) {
	{ // Unsafe block
		byte* buf = malloc_noscan(b.len + 1);
		vmemcpy(buf, b.data, b.len);
		buf[b.len] = 0;
		return tos(buf, b.len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

string byte_repeat(byte b, int count) {
	if (count < 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("byte.repeat: count is negative: "), 0xfe07, {.d_i32 = count}}, {_SLIT0, 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	} else if (count == 0) {
		return _SLIT("");
	} else if (count == 1) {
		return byte_ascii_str(b);
	}
	byte* ret = malloc_noscan(count + 1);
	for (int i = 0; i < count; ++i) {
		{ // Unsafe block
			ret[i] = b;
		}
	}
	int new_len = count;
	{ // Unsafe block
		ret[new_len] = 0;
	}
	return byte_vstring_with_len(ret, new_len);
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL bool fast_string_eq(string a, string b) {
	if (a.len != b.len) {
		return false;
	}
	{ // Unsafe block
		return memcmp(a.str, b.str, b.len) == 0;
	}
	return 0;
}

VV_LOCAL_SYMBOL u64 map_hash_string(voidptr pkey) {
	string key = *((string*)(pkey));
	return wyhash(key.str, ((u64)(key.len)), 0U, ((u64*)(_wyp)));
}

VV_LOCAL_SYMBOL u64 map_hash_int_1(voidptr pkey) {
	return wyhash64(*((byte*)(pkey)), 0U);
}

VV_LOCAL_SYMBOL u64 map_hash_int_2(voidptr pkey) {
	return wyhash64(*((u16*)(pkey)), 0U);
}

VV_LOCAL_SYMBOL u64 map_hash_int_4(voidptr pkey) {
	return wyhash64(*((u32*)(pkey)), 0U);
}

VV_LOCAL_SYMBOL u64 map_hash_int_8(voidptr pkey) {
	return wyhash64(*((u64*)(pkey)), 0U);
}

VV_LOCAL_SYMBOL void DenseArray_zeros_to_end(DenseArray* d) {
	byte* tmp_value = Dmalloc(d->value_bytes);
	byte* tmp_key = Dmalloc(d->key_bytes);
	int count = 0;
	for (int i = 0; i < d->len; ++i) {
		if (DenseArray_has_index(d, i)) {
			{ // Unsafe block
				if (count != i) {
					memcpy(tmp_key, DenseArray_key(d, count), d->key_bytes);
					memcpy(DenseArray_key(d, count), DenseArray_key(d, i), d->key_bytes);
					memcpy(DenseArray_key(d, i), tmp_key, d->key_bytes);
					memcpy(tmp_value, DenseArray_value(d, count), d->value_bytes);
					memcpy(DenseArray_value(d, count), DenseArray_value(d, i), d->value_bytes);
					memcpy(DenseArray_value(d, i), tmp_value, d->value_bytes);
				}
			}
			count++;
		}
	}
	{ // Unsafe block
		Dfree(tmp_value);
		Dfree(tmp_key);
		d->deletes = 0U;
		Dfree(d->all_deleted);
	}
	d->len = count;
	int old_cap = d->cap;
	d->cap = (count < 8 ? (8) : (count));
	{ // Unsafe block
		d->values = realloc_data(d->values, d->value_bytes * old_cap, d->value_bytes * d->cap);
		d->keys = realloc_data(d->keys, d->key_bytes * old_cap, d->key_bytes * d->cap);
	}
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL DenseArray new_dense_array(int key_bytes, int value_bytes) {
	int cap = 8;
	return (DenseArray){
		.key_bytes = key_bytes,
		.value_bytes = value_bytes,
		.cap = cap,
		.len = 0,
		.deletes = 0U,
		.all_deleted = 0,
		.values = Dmalloc(cap * value_bytes),
		.keys = Dmalloc(cap * key_bytes),
	};
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL voidptr DenseArray_key(DenseArray* d, int i) {
	return d->keys + i * d->key_bytes;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL voidptr DenseArray_value(DenseArray* d, int i) {
	return d->values + i * d->value_bytes;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL bool DenseArray_has_index(DenseArray* d, int i) {
	return d->deletes == 0U || d->all_deleted[i] == 0;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL int DenseArray_expand(DenseArray* d) {
	int old_cap = d->cap;
	int old_value_size = d->value_bytes * old_cap;
	int old_key_size = d->key_bytes * old_cap;
	if (d->cap == d->len) {
		d->cap += d->cap >> 3;
		{ // Unsafe block
			d->keys = realloc_data(d->keys, old_key_size, d->key_bytes * d->cap);
			d->values = realloc_data(d->values, old_value_size, d->value_bytes * d->cap);
			if (d->deletes != 0U) {
				d->all_deleted = realloc_data(d->all_deleted, old_cap, d->cap);
				vmemset(d->all_deleted + d->len, 0, d->cap - d->len);
			}
		}
	}
	int push_index = d->len;
	{ // Unsafe block
		if (d->deletes != 0U) {
			d->all_deleted[push_index] = 0;
		}
	}
	d->len++;
	return push_index;
}

// TypeDecl
// TypeDecl
// TypeDecl
// TypeDecl
VV_LOCAL_SYMBOL bool map_eq_string(voidptr a, voidptr b) {
	return fast_string_eq(*((string*)(a)), *((string*)(b)));
}

VV_LOCAL_SYMBOL bool map_eq_int_1(voidptr a, voidptr b) {
	return *((byte*)(a)) == *((byte*)(b));
}

VV_LOCAL_SYMBOL bool map_eq_int_2(voidptr a, voidptr b) {
	return *((u16*)(a)) == *((u16*)(b));
}

VV_LOCAL_SYMBOL bool map_eq_int_4(voidptr a, voidptr b) {
	return *((u32*)(a)) == *((u32*)(b));
}

VV_LOCAL_SYMBOL bool map_eq_int_8(voidptr a, voidptr b) {
	return *((u64*)(a)) == *((u64*)(b));
}

VV_LOCAL_SYMBOL void map_clone_string(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		string s = *((string*)(pkey));
		(*((string*)(dest))) = string_clone(s);
	}
}

VV_LOCAL_SYMBOL void map_clone_int_1(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((byte*)(dest)) = *((byte*)(pkey));
	}
}

VV_LOCAL_SYMBOL void map_clone_int_2(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u16*)(dest)) = *((u16*)(pkey));
	}
}

VV_LOCAL_SYMBOL void map_clone_int_4(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u32*)(dest)) = *((u32*)(pkey));
	}
}

VV_LOCAL_SYMBOL void map_clone_int_8(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u64*)(dest)) = *((u64*)(pkey));
	}
}

VV_LOCAL_SYMBOL void map_free_string(voidptr pkey) {
	string_free(ADDR(string, (*((string*)(pkey)))));
}

VV_LOCAL_SYMBOL void map_free_nop(voidptr _d1) {
}

VV_LOCAL_SYMBOL map new_map(int key_bytes, int value_bytes, u64 (*hash_fn)(voidptr ), bool (*key_eq_fn)(voidptr , voidptr ), void (*clone_fn)(voidptr , voidptr ), void (*free_fn)(voidptr )) {
	int metasize = ((int)(sizeof(u32) * (_const_init_capicity + _const_extra_metas_inc)));
	bool has_string_keys = _us32_lt(sizeof(voidptr),key_bytes);
	return (map){
		.key_bytes = key_bytes,
		.value_bytes = value_bytes,
		.even_index = _const_init_even_index,
		.cached_hashbits = _const_max_cached_hashbits,
		.shift = _const_init_log_capicity,
		.key_values = new_dense_array(key_bytes, value_bytes),
		.metas = ((u32*)(vcalloc_noscan(metasize))),
		.extra_metas = _const_extra_metas_inc,
		.has_string_keys = has_string_keys,
		.hash_fn = (voidptr)hash_fn,
		.key_eq_fn = (voidptr)key_eq_fn,
		.clone_fn = (voidptr)clone_fn,
		.free_fn = (voidptr)free_fn,
		.len = 0,
	};
}

VV_LOCAL_SYMBOL map new_map_init(u64 (*hash_fn)(voidptr ), bool (*key_eq_fn)(voidptr , voidptr ), void (*clone_fn)(voidptr , voidptr ), void (*free_fn)(voidptr ), int n, int key_bytes, int value_bytes, voidptr keys, voidptr values) {
	map out = new_map(key_bytes, value_bytes, (voidptr)hash_fn, (voidptr)key_eq_fn, (voidptr)clone_fn, (voidptr)free_fn);
	byte* pkey = ((byte*)(keys));
	byte* pval = ((byte*)(values));
	for (int _t1 = 0; _t1 < n; ++_t1) {
		{ // Unsafe block
			map_set(&out, pkey, pval);
			pkey = pkey + key_bytes;
			pval = pval + value_bytes;
		}
	}
	return out;
}

map map_move(map* m) {
	map r = *m;
	vmemset(m, 0, ((int)(sizeof(map))));
	return r;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL multi_return_u32_u32 map_key_to_index(map* m, voidptr pkey) {
	u64 hash = m->hash_fn(pkey);
	u64 index = (hash & m->even_index);
	u64 meta = ((((hash >> m->shift) & _const_hash_mask)) | _const_probe_inc);
	return (multi_return_u32_u32){.arg0=((u32)(index)), .arg1=((u32)(meta))};
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL multi_return_u32_u32 map_meta_less(map* m, u32 _index, u32 _metas) {
	u32 index = _index;
	u32 meta = _metas;
	for (;;) {
		if (!(meta < m->metas[index])) break;
		index += 2U;
		meta += _const_probe_inc;
	}
	return (multi_return_u32_u32){.arg0=index, .arg1=meta};
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL void map_meta_greater(map* m, u32 _index, u32 _metas, u32 kvi) {
	u32 meta = _metas;
	u32 index = _index;
	u32 kv_index = kvi;
	for (;;) {
		if (!(m->metas[index] != 0U)) break;
		if (meta > m->metas[index]) {
			{ // Unsafe block
				u32 tmp_meta = m->metas[index];
				m->metas[index] = meta;
				meta = tmp_meta;
				u32 tmp_index = m->metas[index + 1U];
				m->metas[index + 1U] = kv_index;
				kv_index = tmp_index;
			}
		}
		index += 2U;
		meta += _const_probe_inc;
	}
	{ // Unsafe block
		m->metas[index] = meta;
		m->metas[index + 1U] = kv_index;
	}
	u32 probe_count = (meta >> _const_hashbits) - 1U;
	map_ensure_extra_metas(m, probe_count);
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL void map_ensure_extra_metas(map* m, u32 probe_count) {
	if ((probe_count << 1U) == m->extra_metas) {
		u32 size_of_u32 = sizeof(u32);
		u32 old_mem_size = (m->even_index + 2U + m->extra_metas);
		m->extra_metas += _const_extra_metas_inc;
		u32 mem_size = (m->even_index + 2U + m->extra_metas);
		{ // Unsafe block
			byte* x = realloc_data(((byte*)(m->metas)), ((int)(size_of_u32 * old_mem_size)), ((int)(size_of_u32 * mem_size)));
			m->metas = ((u32*)(x));
			vmemset(m->metas + mem_size - _const_extra_metas_inc, 0, ((int)(sizeof(u32) * _const_extra_metas_inc)));
		}
		if (probe_count == 252U) {
			Dpanic(_SLIT("Probe overflow"));
			VUNREACHABLE();
		}
	}
}

VV_LOCAL_SYMBOL void map_set(map* m, voidptr key, voidptr value) {
	f32 load_factor = ((f32)(((u32)(m->len)) << 1U)) / ((f32)(m->even_index));
	if (load_factor > _const_max_load_factor) {
		map_expand(m);
	}
	multi_return_u32_u32 mr_10842 = map_key_to_index(m, key);
	u32 index = mr_10842.arg0;
	u32 meta = mr_10842.arg1;
	multi_return_u32_u32 mr_10878 = map_meta_less(m, index, meta);
	index = mr_10878.arg0;
	meta = mr_10878.arg1;
	for (;;) {
		if (!(meta == m->metas[index])) break;
		int kv_index = ((int)(m->metas[index + 1U]));
		voidptr pkey = DenseArray_key(&m->key_values, kv_index);
		if (m->key_eq_fn(key, pkey)) {
			{ // Unsafe block
				voidptr pval = DenseArray_value(&m->key_values, kv_index);
				vmemcpy(pval, value, m->value_bytes);
			}
			return;
		}
		index += 2U;
		meta += _const_probe_inc;
	}
	int kv_index = DenseArray_expand(&m->key_values);
	{ // Unsafe block
		voidptr pkey = DenseArray_key(&m->key_values, kv_index);
		voidptr pvalue = DenseArray_value(&m->key_values, kv_index);
		m->clone_fn(pkey, key);
		vmemcpy(((byte*)(pvalue)), value, m->value_bytes);
	}
	map_meta_greater(m, index, meta, ((u32)(kv_index)));
	m->len++;
}

VV_LOCAL_SYMBOL void map_expand(map* m) {
	u32 old_cap = m->even_index;
	m->even_index = ((m->even_index + 2U) << 1U) - 2U;
	if (m->cached_hashbits == 0) {
		m->shift += _const_max_cached_hashbits;
		m->cached_hashbits = _const_max_cached_hashbits;
		map_rehash(m);
	} else {
		map_cached_rehash(m, old_cap);
		m->cached_hashbits--;
	}
}

VV_LOCAL_SYMBOL void map_rehash(map* m) {
	u32 meta_bytes = sizeof(u32) * (m->even_index + 2U + m->extra_metas);
	{ // Unsafe block
		byte* x = v_realloc(((byte*)(m->metas)), ((int)(meta_bytes)));
		m->metas = ((u32*)(x));
		vmemset(m->metas, 0, ((int)(meta_bytes)));
	}
	for (int i = 0; i < m->key_values.len; i++) {
		if (!DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		voidptr pkey = DenseArray_key(&m->key_values, i);
		multi_return_u32_u32 mr_12545 = map_key_to_index(m, pkey);
		u32 index = mr_12545.arg0;
		u32 meta = mr_12545.arg1;
		multi_return_u32_u32 mr_12583 = map_meta_less(m, index, meta);
		index = mr_12583.arg0;
		meta = mr_12583.arg1;
		map_meta_greater(m, index, meta, ((u32)(i)));
	}
}

VV_LOCAL_SYMBOL void map_cached_rehash(map* m, u32 old_cap) {
	u32* old_metas = m->metas;
	int metasize = ((int)(sizeof(u32) * (m->even_index + 2U + m->extra_metas)));
	m->metas = ((u32*)(vcalloc(metasize)));
	u32 old_extra_metas = m->extra_metas;
	for (u32 i = ((u32)(0U)); i <= old_cap + old_extra_metas; i += 2U) {
		if (old_metas[i] == 0U) {
			continue;
		}
		u32 old_meta = old_metas[i];
		u32 old_probe_count = ((old_meta >> _const_hashbits) - 1U) << 1U;
		u32 old_index = ((i - old_probe_count) & (m->even_index >> 1U));
		u32 index = (((old_index | (old_meta << m->shift))) & m->even_index);
		u32 meta = (((old_meta & _const_hash_mask)) | _const_probe_inc);
		multi_return_u32_u32 mr_13382 = map_meta_less(m, index, meta);
		index = mr_13382.arg0;
		meta = mr_13382.arg1;
		u32 kv_index = old_metas[i + 1U];
		map_meta_greater(m, index, meta, kv_index);
	}
	Dfree(old_metas);
}

VV_LOCAL_SYMBOL voidptr map_get_and_set(map* m, voidptr key, voidptr zero) {
	for (;;) {
		multi_return_u32_u32 mr_13830 = map_key_to_index(m, key);
		u32 index = mr_13830.arg0;
		u32 meta = mr_13830.arg1;
		for (;;) {
			if (meta == m->metas[index]) {
				int kv_index = ((int)(m->metas[index + 1U]));
				voidptr pkey = DenseArray_key(&m->key_values, kv_index);
				if (m->key_eq_fn(key, pkey)) {
					voidptr pval = DenseArray_value(&m->key_values, kv_index);
					return ((byte*)(pval));
				}
			}
			index += 2U;
			meta += _const_probe_inc;
			if (meta > m->metas[index]) {
				break;
			}
		}
		map_set(m, key, zero);
	}
	return ((voidptr)(0));
}

VV_LOCAL_SYMBOL voidptr map_get(map* m, voidptr key, voidptr zero) {
	multi_return_u32_u32 mr_14555 = map_key_to_index(m, key);
	u32 index = mr_14555.arg0;
	u32 meta = mr_14555.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1U]));
			voidptr pkey = DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				voidptr pval = DenseArray_value(&m->key_values, kv_index);
				return ((byte*)(pval));
			}
		}
		index += 2U;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return zero;
}

VV_LOCAL_SYMBOL voidptr map_get_check(map* m, voidptr key) {
	multi_return_u32_u32 mr_15222 = map_key_to_index(m, key);
	u32 index = mr_15222.arg0;
	u32 meta = mr_15222.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1U]));
			voidptr pkey = DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				voidptr pval = DenseArray_value(&m->key_values, kv_index);
				return ((byte*)(pval));
			}
		}
		index += 2U;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return 0;
}

VV_LOCAL_SYMBOL bool map_exists(map* m, voidptr key) {
	multi_return_u32_u32 mr_15734 = map_key_to_index(m, key);
	u32 index = mr_15734.arg0;
	u32 meta = mr_15734.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1U]));
			voidptr pkey = DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				return true;
			}
		}
		index += 2U;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return false;
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL void DenseArray_delete(DenseArray* d, int i) {
	if (d->deletes == 0U) {
		d->all_deleted = vcalloc(d->cap);
	}
	d->deletes++;
	{ // Unsafe block
		d->all_deleted[i] = 1;
	}
}

// Attr: [unsafe]
void map_delete(map* m, voidptr key) {
	multi_return_u32_u32 mr_16363 = map_key_to_index(m, key);
	u32 index = mr_16363.arg0;
	u32 meta = mr_16363.arg1;
	multi_return_u32_u32 mr_16399 = map_meta_less(m, index, meta);
	index = mr_16399.arg0;
	meta = mr_16399.arg1;
	for (;;) {
		if (!(meta == m->metas[index])) break;
		int kv_index = ((int)(m->metas[index + 1U]));
		voidptr pkey = DenseArray_key(&m->key_values, kv_index);
		if (m->key_eq_fn(key, pkey)) {
			for (;;) {
				if (!((m->metas[index + 2U] >> _const_hashbits) > 1U)) break;
				{ // Unsafe block
					m->metas[index] = m->metas[index + 2U] - _const_probe_inc;
					m->metas[index + 1U] = m->metas[index + 3U];
				}
				index += 2U;
			}
			m->len--;
			DenseArray_delete(&m->key_values, kv_index);
			{ // Unsafe block
				m->metas[index] = 0U;
				m->free_fn(pkey);
				vmemset(pkey, 0, m->key_bytes);
			}
			if (m->key_values.len <= 32) {
				return;
			}
			if (_us32_ge(m->key_values.deletes,(m->key_values.len >> 1))) {
				DenseArray_zeros_to_end(&m->key_values);
				map_rehash(m);
			}
			return;
		}
		index += 2U;
		meta += _const_probe_inc;
	}
}

array map_keys(map* m) {
	array keys = __new_array(m->len, 0, m->key_bytes);
	byte* item = ((byte*)(keys.data));
	if (m->key_values.deletes == 0U) {
		for (int i = 0; i < m->key_values.len; i++) {
			{ // Unsafe block
				voidptr pkey = DenseArray_key(&m->key_values, i);
				m->clone_fn(item, pkey);
				item = item + m->key_bytes;
			}
		}
		return keys;
	}
	for (int i = 0; i < m->key_values.len; i++) {
		if (!DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		{ // Unsafe block
			voidptr pkey = DenseArray_key(&m->key_values, i);
			m->clone_fn(item, pkey);
			item = item + m->key_bytes;
		}
	}
	return keys;
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL DenseArray DenseArray_clone(DenseArray* d) {
	DenseArray res = (DenseArray){
		.key_bytes = d->key_bytes,
		.value_bytes = d->value_bytes,
		.cap = d->cap,
		.len = d->len,
		.deletes = d->deletes,
		.all_deleted = 0,
		.values = 0,
		.keys = 0,
	};
	{ // Unsafe block
		if (d->deletes != 0U) {
			res.all_deleted = memdup(d->all_deleted, d->cap);
		}
		res.keys = memdup(d->keys, d->cap * d->key_bytes);
		res.values = memdup(d->values, d->cap * d->value_bytes);
	}
	return res;
}

// Attr: [unsafe]
map map_clone(map* m) {
	int metasize = ((int)(sizeof(u32) * (m->even_index + 2U + m->extra_metas)));
	map res = (map){
		.key_bytes = m->key_bytes,
		.value_bytes = m->value_bytes,
		.even_index = m->even_index,
		.cached_hashbits = m->cached_hashbits,
		.shift = m->shift,
		.key_values = DenseArray_clone(&m->key_values),
		.metas = ((u32*)(Dmalloc(metasize))),
		.extra_metas = m->extra_metas,
		.has_string_keys = m->has_string_keys,
		.hash_fn = (voidptr)m->hash_fn,
		.key_eq_fn = (voidptr)m->key_eq_fn,
		.clone_fn = (voidptr)m->clone_fn,
		.free_fn = (voidptr)m->free_fn,
		.len = m->len,
	};
	vmemcpy(res.metas, m->metas, metasize);
	if (!m->has_string_keys) {
		return res;
	}
	for (int i = 0; i < m->key_values.len; ++i) {
		if (!DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		m->clone_fn(DenseArray_key(&res.key_values, i), DenseArray_key(&m->key_values, i));
	}
	return res;
}

// Attr: [unsafe]
void map_free(map* m) {
	Dfree(m->metas);
	if (m->key_values.deletes == 0U) {
		for (int i = 0; i < m->key_values.len; i++) {
			{ // Unsafe block
				voidptr pkey = DenseArray_key(&m->key_values, i);
				m->free_fn(pkey);
			}
		}
	} else {
		for (int i = 0; i < m->key_values.len; i++) {
			if (!DenseArray_has_index(&m->key_values, i)) {
				continue;
			}
			{ // Unsafe block
				voidptr pkey = DenseArray_key(&m->key_values, i);
				m->free_fn(pkey);
			}
		}
		Dfree(m->key_values.all_deleted);
	}
	{ // Unsafe block
		Dfree(m->key_values.keys);
		Dfree(m->key_values.values);
	}
}

// Attr: [unsafe]
void IError_free(IError* ie) {
	{ // Unsafe block
		string_free(&(*(ie->msg)));
		IError* cie = ((IError*)(ie));
		Dfree(cie->_object);
	}
}

string IError_str(IError err) {
	return ((err._typ == _IError_None___index) ? (_SLIT("none")) : (err._typ == _IError_Error_index) ? ((err._Error)->msg) : ( str_intp(3, _MOV((StrIntpData[]){{_SLIT0, 0xfe10, {.d_s = charptr_vstring_literal( /* IError */ v_typeof_interface_IError( (err)._typ ))}}, {_SLIT(": "), 0xfe10, {.d_s = (*(err.msg))}}, {_SLIT0, 0, { .d_c = 0 }}}))));
}

VV_LOCAL_SYMBOL string None___str(None__ _d1) {
	return _SLIT("none");
}

// Attr: [inline]
inline IError Derror(string message) {
	;
	return /*&IError*/I_Error_to_Interface_IError((Error*)memdup(&(Error){.msg = message,.code = 0,}, sizeof(Error)));
}

// Attr: [inline]
inline IError error_with_code(string message, int code) {
	;
	return /*&IError*/I_Error_to_Interface_IError((Error*)memdup(&(Error){.msg = message,.code = code,}, sizeof(Error)));
}

VV_LOCAL_SYMBOL void opt_ok(voidptr data, Option* option, int size) {
	{ // Unsafe block
		*option = (Option){.state = 0,.err = _const_none__,};
		vmemcpy(((byte*)(&option->err)) + sizeof(IError), data, size);
	}
}

// Attr: [unsafe]
void Error_free(Error* e) {
	string_free(&e->msg);
}

// Attr: [unsafe]
void None___free(None__* n) {
	string_free(&n->msg);
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL VMemoryBlock* vmemory_block_new(VMemoryBlock* prev, int at_least) {
	VMemoryBlock* v = ((VMemoryBlock*)(calloc(1, sizeof(VMemoryBlock))));
	if (prev != 0) {
		v->id = prev->id + 1;
	}
	v->previous = prev;
	int block_size = (at_least < _const_prealloc_block_size ? (_const_prealloc_block_size) : (at_least));
	v->start = malloc(block_size);
	v->cap = block_size;
	v->remaining = block_size;
	v->current = v->start;
	return v;
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL byte* vmemory_block_malloc(int n) {
	{ // Unsafe block
		if (g_memory_block->remaining < n) {
			g_memory_block = vmemory_block_new(g_memory_block, n);
		}
		byte* res = ((byte*)(0));
		res = g_memory_block->current;
		g_memory_block->remaining -= n;
		g_memory_block->mallocs++;
		g_memory_block->current += n;
		return res;
	}
	return 0;
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL void prealloc_vinit(void) {
	{ // Unsafe block
		g_memory_block = vmemory_block_new(((voidptr)(0)), _const_prealloc_block_size);
		#if !defined(_VFREESTANDING)
		{
			atexit((voidptr)prealloc_vcleanup);
		}
		#endif
	}
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL void prealloc_vcleanup(void) {
	{ // Unsafe block
		for (;;) {
			if (!(g_memory_block != 0)) break;
			free(g_memory_block->start);
			g_memory_block = g_memory_block->previous;
		}
	}
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL byte* prealloc_malloc(int n) {
	return vmemory_block_malloc(n);
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL byte* prealloc_realloc(byte* old_data, int old_size, int new_size) {
	byte* new_ptr = vmemory_block_malloc(new_size);
	int min_size = (old_size < new_size ? (old_size) : (new_size));
	memcpy(new_ptr, old_data, min_size);
	return new_ptr;
}

// Attr: [unsafe]
VV_LOCAL_SYMBOL byte* prealloc_calloc(int n) {
	byte* new_ptr = vmemory_block_malloc(n);
	memset(new_ptr, 0, n);
	return new_ptr;
}

string rune_str(rune c) {
	return utf32_to_str(((u32)(c)));
}

// Attr: [manualfree]
string Array_rune_string(Array_rune ra) {
	strings__Builder sb = strings__new_builder(ra.len);
	strings__Builder_write_runes(&sb, ra);
	string res = strings__Builder_str(&sb);
	strings__Builder_free(&sb);
	return res;
}

string rune_repeat(rune c, int count) {
	if (count < 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("rune.repeat: count is negative: "), 0xfe07, {.d_i32 = count}}, {_SLIT0, 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	} else if (count == 0) {
		return _SLIT("");
	} else if (count == 1) {
		return rune_str(c);
	}
	Array_fixed_byte_5 buffer = {0};
	string res = utf32_to_str_no_malloc(((u32)(c)), &buffer[0]);
	return string_repeat(res, count);
}

VV_LOCAL_SYMBOL SortedMap new_sorted_map(int n, int value_bytes) {
	return (SortedMap){.value_bytes = value_bytes,.root = new_node(),.len = 0,};
}

VV_LOCAL_SYMBOL SortedMap new_sorted_map_init(int n, int value_bytes, string* keys, voidptr values) {
	SortedMap out = new_sorted_map(n, value_bytes);
	for (int i = 0; i < n; ++i) {
		SortedMap_set(&out, keys[i], ((byte*)(values)) + i * value_bytes);
	}
	return out;
}

VV_LOCAL_SYMBOL mapnode* new_node(void) {
	return (mapnode*)memdup(&(mapnode){.children = 0,.len = 0,.keys = {0},.values = {0},}, sizeof(mapnode));
}

VV_LOCAL_SYMBOL void SortedMap_set(SortedMap* m, string key, voidptr value) {
	mapnode* node = m->root;
	int child_index = 0;
	mapnode* parent = ((mapnode*)(0));
	for (;;) {
		if (node->len == _const_max_len) {
			if (isnil(parent)) {
				parent = new_node();
				m->root = parent;
			}
			mapnode_split_child(parent, child_index, node);
			if (string__eq(key, parent->keys[v_fixed_index(child_index, 11)])) {
				vmemcpy(parent->values[v_fixed_index(child_index, 11)], value, m->value_bytes);
				return;
			}
			if (string__lt(key, parent->keys[v_fixed_index(child_index, 11)])) {
				node = ((mapnode*)(parent->children[child_index]));
			} else {
				node = ((mapnode*)(parent->children[child_index + 1]));
			}
		}
		int i = 0;
		for (;;) {
			if (!(i < node->len && string__lt(node->keys[v_fixed_index(i, 11)], key))) break;
			i++;
		}
		if (i != node->len && string__eq(key, node->keys[v_fixed_index(i, 11)])) {
			vmemcpy(node->values[v_fixed_index(i, 11)], value, m->value_bytes);
			return;
		}
		if (isnil(node->children)) {
			int j = node->len - 1;
			for (;;) {
				if (!(j >= 0 && string__lt(key, node->keys[v_fixed_index(j, 11)]))) break;
				node->keys[v_fixed_index(j + 1, 11)] = node->keys[v_fixed_index(j, 11)];
				node->values[v_fixed_index(j + 1, 11)] = node->values[v_fixed_index(j, 11)];
				j--;
			}
			node->keys[v_fixed_index(j + 1, 11)] = key;
			{ // Unsafe block
				node->values[v_fixed_index(j + 1, 11)] = Dmalloc(m->value_bytes);
				vmemcpy(node->values[v_fixed_index(j + 1, 11)], value, m->value_bytes);
			}
			node->len++;
			m->len++;
			return;
		}
		parent = node;
		child_index = i;
		node = ((mapnode*)(node->children[child_index]));
	}
}

VV_LOCAL_SYMBOL void mapnode_split_child(mapnode* n, int child_index, mapnode* y) {
	mapnode* z = new_node();
	z->len = _const_mid_index;
	y->len = _const_mid_index;
	for (int j = _const_mid_index - 1; j >= 0; j--) {
		z->keys[v_fixed_index(j, 11)] = y->keys[v_fixed_index(j + _const_degree, 11)];
		z->values[v_fixed_index(j, 11)] = y->values[v_fixed_index(j + _const_degree, 11)];
	}
	if (!isnil(y->children)) {
		z->children = ((voidptr*)(Dmalloc(((int)(_const_children_bytes)))));
		for (int jj = _const_degree - 1; jj >= 0; jj--) {
			{ // Unsafe block
				z->children[jj] = y->children[jj + _const_degree];
			}
		}
	}
	{ // Unsafe block
		if (isnil(n->children)) {
			n->children = ((voidptr*)(Dmalloc(((int)(_const_children_bytes)))));
		}
		n->children[n->len + 1] = n->children[n->len];
	}
	for (int j = n->len; j > child_index; j--) {
		n->keys[v_fixed_index(j, 11)] = n->keys[v_fixed_index(j - 1, 11)];
		n->values[v_fixed_index(j, 11)] = n->values[v_fixed_index(j - 1, 11)];
		{ // Unsafe block
			n->children[j] = n->children[j - 1];
		}
	}
	n->keys[v_fixed_index(child_index, 11)] = y->keys[v_fixed_index(_const_mid_index, 11)];
	n->values[v_fixed_index(child_index, 11)] = y->values[v_fixed_index(_const_mid_index, 11)];
	{ // Unsafe block
		n->children[child_index] = ((voidptr)(y));
		n->children[child_index + 1] = ((voidptr)(z));
	}
	n->len++;
}

VV_LOCAL_SYMBOL bool SortedMap_get(SortedMap m, string key, voidptr out) {
	mapnode* node = m.root;
	for (;;) {
		int i = node->len - 1;
		for (;;) {
			if (!(i >= 0 && string__lt(key, node->keys[v_fixed_index(i, 11)]))) break;
			i--;
		}
		if (i != -1 && string__eq(key, node->keys[v_fixed_index(i, 11)])) {
			vmemcpy(out, node->values[v_fixed_index(i, 11)], m.value_bytes);
			return true;
		}
		if (isnil(node->children)) {
			break;
		}
		node = ((mapnode*)(node->children[i + 1]));
	}
	return false;
}

VV_LOCAL_SYMBOL bool SortedMap_exists(SortedMap m, string key) {
	if (isnil(m.root)) {
		return false;
	}
	mapnode* node = m.root;
	for (;;) {
		int i = node->len - 1;
		for (;;) {
			if (!(i >= 0 && string__lt(key, node->keys[v_fixed_index(i, 11)]))) break;
			i--;
		}
		if (i != -1 && string__eq(key, node->keys[v_fixed_index(i, 11)])) {
			return true;
		}
		if (isnil(node->children)) {
			break;
		}
		node = ((mapnode*)(node->children[i + 1]));
	}
	return false;
}

VV_LOCAL_SYMBOL int mapnode_find_key(mapnode* n, string k) {
	int idx = 0;
	for (;;) {
		if (!(idx < n->len && string__lt(n->keys[v_fixed_index(idx, 11)], k))) break;
		idx++;
	}
	return idx;
}

VV_LOCAL_SYMBOL bool mapnode_remove_key(mapnode* n, string k) {
	int idx = mapnode_find_key(n, k);
	if (idx < n->len && string__eq(n->keys[v_fixed_index(idx, 11)], k)) {
		if (isnil(n->children)) {
			mapnode_remove_from_leaf(n, idx);
		} else {
			mapnode_remove_from_non_leaf(n, idx);
		}
		return true;
	} else {
		if (isnil(n->children)) {
			return false;
		}
		bool flag = (idx == n->len ? (true) : (false));
		if (((mapnode*)(n->children[idx]))->len < _const_degree) {
			mapnode_fill(n, idx);
		}
		mapnode* node = ((mapnode*)(0));
		if (flag && idx > n->len) {
			node = ((mapnode*)(n->children[idx - 1]));
		} else {
			node = ((mapnode*)(n->children[idx]));
		}
		return mapnode_remove_key(node, k);
	}
	return 0;
}

VV_LOCAL_SYMBOL void mapnode_remove_from_leaf(mapnode* n, int idx) {
	for (int i = idx + 1; i < n->len; i++) {
		n->keys[v_fixed_index(i - 1, 11)] = n->keys[v_fixed_index(i, 11)];
		n->values[v_fixed_index(i - 1, 11)] = n->values[v_fixed_index(i, 11)];
	}
	n->len--;
}

VV_LOCAL_SYMBOL void mapnode_remove_from_non_leaf(mapnode* n, int idx) {
	string k = n->keys[v_fixed_index(idx, 11)];
	if (((mapnode*)(n->children[idx]))->len >= _const_degree) {
		mapnode* current = ((mapnode*)(n->children[idx]));
		for (;;) {
			if (!(!isnil(current->children))) break;
			current = ((mapnode*)(current->children[current->len]));
		}
		string predecessor = current->keys[v_fixed_index(current->len - 1, 11)];
		n->keys[v_fixed_index(idx, 11)] = predecessor;
		n->values[v_fixed_index(idx, 11)] = current->values[v_fixed_index(current->len - 1, 11)];
		mapnode* node = ((mapnode*)(n->children[idx]));
		mapnode_remove_key(node, predecessor);
	} else if (((mapnode*)(n->children[idx + 1]))->len >= _const_degree) {
		mapnode* current = ((mapnode*)(n->children[idx + 1]));
		for (;;) {
			if (!(!isnil(current->children))) break;
			current = ((mapnode*)(current->children[0]));
		}
		string successor = current->keys[0];
		n->keys[v_fixed_index(idx, 11)] = successor;
		n->values[v_fixed_index(idx, 11)] = current->values[0];
		mapnode* node = ((mapnode*)(n->children[idx + 1]));
		mapnode_remove_key(node, successor);
	} else {
		mapnode_merge(n, idx);
		mapnode* node = ((mapnode*)(n->children[idx]));
		mapnode_remove_key(node, k);
	}
}

VV_LOCAL_SYMBOL void mapnode_fill(mapnode* n, int idx) {
	if (idx != 0 && ((mapnode*)(n->children[idx - 1]))->len >= _const_degree) {
		mapnode_borrow_from_prev(n, idx);
	} else if (idx != n->len && ((mapnode*)(n->children[idx + 1]))->len >= _const_degree) {
		mapnode_borrow_from_next(n, idx);
	} else if (idx != n->len) {
		mapnode_merge(n, idx);
	} else {
		mapnode_merge(n, idx - 1);
	}
}

VV_LOCAL_SYMBOL void mapnode_borrow_from_prev(mapnode* n, int idx) {
	mapnode* child = ((mapnode*)(n->children[idx]));
	mapnode* sibling = ((mapnode*)(n->children[idx - 1]));
	for (int i = child->len - 1; i >= 0; i--) {
		child->keys[v_fixed_index(i + 1, 11)] = child->keys[v_fixed_index(i, 11)];
		child->values[v_fixed_index(i + 1, 11)] = child->values[v_fixed_index(i, 11)];
	}
	if (!isnil(child->children)) {
		for (int i = child->len; i >= 0; i--) {
			{ // Unsafe block
				child->children[i + 1] = child->children[i];
			}
		}
	}
	child->keys[0] = n->keys[v_fixed_index(idx - 1, 11)];
	child->values[0] = n->values[v_fixed_index(idx - 1, 11)];
	if (!isnil(child->children)) {
		{ // Unsafe block
			child->children[0] = sibling->children[sibling->len];
		}
	}
	n->keys[v_fixed_index(idx - 1, 11)] = sibling->keys[v_fixed_index(sibling->len - 1, 11)];
	n->values[v_fixed_index(idx - 1, 11)] = sibling->values[v_fixed_index(sibling->len - 1, 11)];
	child->len++;
	sibling->len--;
}

VV_LOCAL_SYMBOL void mapnode_borrow_from_next(mapnode* n, int idx) {
	mapnode* child = ((mapnode*)(n->children[idx]));
	mapnode* sibling = ((mapnode*)(n->children[idx + 1]));
	child->keys[v_fixed_index(child->len, 11)] = n->keys[v_fixed_index(idx, 11)];
	child->values[v_fixed_index(child->len, 11)] = n->values[v_fixed_index(idx, 11)];
	if (!isnil(child->children)) {
		{ // Unsafe block
			child->children[child->len + 1] = sibling->children[0];
		}
	}
	n->keys[v_fixed_index(idx, 11)] = sibling->keys[0];
	n->values[v_fixed_index(idx, 11)] = sibling->values[0];
	for (int i = 1; i < sibling->len; i++) {
		sibling->keys[v_fixed_index(i - 1, 11)] = sibling->keys[v_fixed_index(i, 11)];
		sibling->values[v_fixed_index(i - 1, 11)] = sibling->values[v_fixed_index(i, 11)];
	}
	if (!isnil(sibling->children)) {
		for (int i = 1; i <= sibling->len; i++) {
			{ // Unsafe block
				sibling->children[i - 1] = sibling->children[i];
			}
		}
	}
	child->len++;
	sibling->len--;
}

VV_LOCAL_SYMBOL void mapnode_merge(mapnode* n, int idx) {
	mapnode* child = ((mapnode*)(n->children[idx]));
	mapnode* sibling = ((mapnode*)(n->children[idx + 1]));
	child->keys[v_fixed_index(_const_mid_index, 11)] = n->keys[v_fixed_index(idx, 11)];
	child->values[v_fixed_index(_const_mid_index, 11)] = n->values[v_fixed_index(idx, 11)];
	for (int i = 0; i < sibling->len; ++i) {
		child->keys[v_fixed_index(i + _const_degree, 11)] = sibling->keys[v_fixed_index(i, 11)];
		child->values[v_fixed_index(i + _const_degree, 11)] = sibling->values[v_fixed_index(i, 11)];
	}
	if (!isnil(child->children)) {
		for (int i = 0; i <= sibling->len; i++) {
			{ // Unsafe block
				child->children[i + _const_degree] = sibling->children[i];
			}
		}
	}
	for (int i = idx + 1; i < n->len; i++) {
		n->keys[v_fixed_index(i - 1, 11)] = n->keys[v_fixed_index(i, 11)];
		n->values[v_fixed_index(i - 1, 11)] = n->values[v_fixed_index(i, 11)];
	}
	for (int i = idx + 2; i <= n->len; i++) {
		{ // Unsafe block
			n->children[i - 1] = n->children[i];
		}
	}
	child->len += sibling->len + 1;
	n->len--;
}

void SortedMap_delete(SortedMap* m, string key) {
	if (m->root->len == 0) {
		return;
	}
	bool removed = mapnode_remove_key(m->root, key);
	if (removed) {
		m->len--;
	}
	if (m->root->len == 0) {
		if (isnil(m->root->children)) {
			return;
		} else {
			m->root = ((mapnode*)(m->root->children[0]));
		}
	}
}

VV_LOCAL_SYMBOL int mapnode_subkeys(mapnode* n, Array_string* keys, int at) {
	int position = at;
	if (!isnil(n->children)) {
		for (int i = 0; i < n->len; ++i) {
			mapnode* child = ((mapnode*)(n->children[i]));
			position += mapnode_subkeys(child, keys, position);
			array_set(keys, position, &(string[]) { n->keys[v_fixed_index(i, 11)] });
			position++;
		}
		mapnode* child = ((mapnode*)(n->children[n->len]));
		position += mapnode_subkeys(child, keys, position);
	} else {
		for (int i = 0; i < n->len; ++i) {
			array_set(keys, position + i, &(string[]) { n->keys[v_fixed_index(i, 11)] });
		}
		position += n->len;
	}
	return position - at;
}

Array_string SortedMap_keys(SortedMap* m) {
	Array_string keys = __new_array_with_default(m->len, 0, sizeof(string), &(string[]){_SLIT("")});
	if (isnil(m->root) || m->root->len == 0) {
		return keys;
	}
	mapnode_subkeys(m->root, &/*arr*/keys, 0);
	return keys;
}

VV_LOCAL_SYMBOL void mapnode_free(mapnode* n) {
	println(_SLIT("TODO"));
}

void SortedMap_free(SortedMap* m) {
	if (isnil(m->root)) {
		return;
	}
	mapnode_free(m->root);
}

void SortedMap_print(SortedMap m) {
	println(_SLIT("TODO"));
}

// Attr: [direct_array_access]
Array_rune string_runes(string s) {
	Array_rune runes = __new_array_with_default(0, s.len, sizeof(rune), 0);
	for (int i = 0; i < s.len; i++) {
		int char_len = utf8_char_len(s.str[i]);
		if (char_len > 1) {
			int end = (s.len - 1 >= i + char_len ? (i + char_len) : (s.len));
			string r = string_substr(s, i, end);
			array_push((array*)&runes, _MOV((rune[]){ string_utf32_code(r) }));
			i += char_len - 1;
		} else {
			array_push((array*)&runes, _MOV((rune[]){ s.str[i] }));
		}
	}
	return runes;
}

// Attr: [unsafe]
string tos(byte* s, int len) {
	if (s == 0) {
		Dpanic(_SLIT("tos(): nil string"));
		VUNREACHABLE();
	}
	return (string){.str = s, .len = len};
}

// Attr: [unsafe]
string tos_clone(byte* s) {
	return string_clone(tos2(s));
}

// Attr: [unsafe]
string tos2(byte* s) {
	if (s == 0) {
		Dpanic(_SLIT("tos2: nil string"));
		VUNREACHABLE();
	}
	return (string){.str = s, .len = vstrlen(s)};
}

// Attr: [unsafe]
string tos3(char* s) {
	if (s == 0) {
		Dpanic(_SLIT("tos3: nil string"));
		VUNREACHABLE();
	}
	return (string){.str = ((byte*)(s)), .len = vstrlen_char(s)};
}

// Attr: [unsafe]
string tos4(byte* s) {
	if (s == 0) {
		return _SLIT("");
	}
	return tos2(s);
}

// Attr: [unsafe]
string tos5(char* s) {
	if (s == 0) {
		return _SLIT("");
	}
	return tos3(s);
}

// Attr: [unsafe]
string byte_vstring(byte* bp) {
	return (string){.str = bp, .len = vstrlen(bp)};
}

// Attr: [unsafe]
string byte_vstring_with_len(byte* bp, int len) {
	return (string){.str = bp, .len = len, .is_lit = 0};
}

// Attr: [unsafe]
string char_vstring(char* cp) {
	return (string){.str = ((byte*)(cp)), .len = vstrlen_char(cp), .is_lit = 0};
}

// Attr: [unsafe]
string char_vstring_with_len(char* cp, int len) {
	return (string){.str = ((byte*)(cp)), .len = len, .is_lit = 0};
}

// Attr: [unsafe]
string byte_vstring_literal(byte* bp) {
	return (string){.str = bp, .len = vstrlen(bp), .is_lit = 1};
}

// Attr: [unsafe]
string byte_vstring_literal_with_len(byte* bp, int len) {
	return (string){.str = bp, .len = len, .is_lit = 1};
}

// Attr: [unsafe]
string char_vstring_literal(char* cp) {
	return (string){.str = ((byte*)(cp)), .len = vstrlen_char(cp), .is_lit = 1};
}

// Attr: [unsafe]
string char_vstring_literal_with_len(char* cp, int len) {
	return (string){.str = ((byte*)(cp)), .len = len, .is_lit = 1};
}

VV_LOCAL_SYMBOL string string_clone_static(string a) {
	return string_clone(a);
}

string string_clone(string a) {
	if (a.len == 0) {
		return _SLIT("");
	}
	string b = (string){.str = malloc_noscan(a.len + 1), .len = a.len};
	{ // Unsafe block
		vmemcpy(b.str, a.str, a.len);
		b.str[a.len] = 0;
	}
	return b;
}

// Attr: [unsafe]
string cstring_to_vstring(char* cstr) {
	return tos_clone(((byte*)(cstr)));
}

string string_replace_once(string s, string rep, string with) {
	int idx = string_index_(s, rep);
	if (idx == -1) {
		return string_clone(s);
	}
	return string__plus(string__plus(string_substr(s, 0, idx), with), string_substr(s, idx + rep.len, s.len));
}

// Attr: [direct_array_access]
string string_replace(string s, string rep, string with) {
bool string_replace_defer_0 = false;
Array_int idxs;
	if (s.len == 0 || rep.len == 0 || rep.len > s.len) {
		return string_clone(s);
	}
	if (!string_contains(s, rep)) {
		return string_clone(s);
	}
	idxs = __new_array_with_default(0, s.len / rep.len, sizeof(int), 0);
	string_replace_defer_0 = true;
	int idx = 0;
	for (;;) {
		idx = string_index_after(s, rep, idx);
		if (idx == -1) {
			break;
		}
		array_push((array*)&idxs, _MOV((int[]){ idx }));
		idx += rep.len;
	}
	if (idxs.len == 0) {
		string _t4 = string_clone(s);
		// Defer begin
		if (string_replace_defer_0) {
			array_free(&idxs);
		}
		// Defer end
		return _t4;
	}
	int new_len = s.len + idxs.len * (with.len - rep.len);
	byte* b = malloc_noscan(new_len + 1);
	int b_i = 0;
	int s_idx = 0;
	for (int _t5 = 0; _t5 < idxs.len; ++_t5) {
		int rep_pos = ((int*)idxs.data)[_t5];
		for (int i = s_idx; i < rep_pos; ++i) {
			{ // Unsafe block
				b[b_i] = s.str[ i];
			}
			b_i++;
		}
		s_idx = rep_pos + rep.len;
		for (int i = 0; i < with.len; ++i) {
			{ // Unsafe block
				b[b_i] = with.str[ i];
			}
			b_i++;
		}
	}
	if (s_idx < s.len) {
		for (int i = s_idx; i < s.len; ++i) {
			{ // Unsafe block
				b[b_i] = s.str[ i];
			}
			b_i++;
		}
	}
	{ // Unsafe block
		b[new_len] = 0;
		string _t6 = tos(b, new_len);
		// Defer begin
		if (string_replace_defer_0) {
			array_free(&idxs);
		}
		// Defer end
		return _t6;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
string string_replace_each(string s, Array_string vals) {
	if (s.len == 0 || vals.len == 0) {
		return string_clone(s);
	}
	if (vals.len % 2 != 0) {
		eprintln(_SLIT("string.replace_each(): odd number of strings"));
		return string_clone(s);
	}
	int new_len = s.len;
	Array_RepIndex idxs = __new_array_with_default(0, 6, sizeof(RepIndex), 0);
	int idx = 0;
	string s_ = string_clone(s);
	for (int rep_i = 0; rep_i < vals.len; rep_i += 2) {
		string rep = ((string*)vals.data)[rep_i];
		string with = ((string*)vals.data)[rep_i + 1];
		for (;;) {
			idx = string_index_after(s_, rep, idx);
			if (idx == -1) {
				break;
			}
			for (int i = 0; i < rep.len; ++i) {
				{ // Unsafe block
					s_.str[idx + i] = 127;
				}
			}
			array_push((array*)&idxs, _MOV((RepIndex[]){ (RepIndex){.idx = idx,.val_idx = rep_i,} }));
			idx += rep.len;
			new_len += with.len - rep.len;
		}
	}
	if (idxs.len == 0) {
		return string_clone(s);
	}
	qsort(idxs.data, idxs.len, idxs.element_size, (int (*)(const void *, const void *))&compare_RepIndex_by_idx);
	byte* b = malloc_noscan(new_len + 1);
	int idx_pos = 0;
	RepIndex cur_idx = ((RepIndex*)idxs.data)[idx_pos];
	int b_i = 0;
	for (int i = 0; i < s.len; i++) {
		if (i == cur_idx.idx) {
			string rep = ((string*)vals.data)[cur_idx.val_idx];
			string with = ((string*)vals.data)[cur_idx.val_idx + 1];
			for (int j = 0; j < with.len; ++j) {
				{ // Unsafe block
					b[b_i] = with.str[ j];
				}
				b_i++;
			}
			i += rep.len - 1;
			idx_pos++;
			if (idx_pos < idxs.len) {
				cur_idx = ((RepIndex*)idxs.data)[idx_pos];
			}
		} else {
			{ // Unsafe block
				b[b_i] = s.str[i];
			}
			b_i++;
		}
	}
	{ // Unsafe block
		b[new_len] = 0;
		return tos(b, new_len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

bool string_bool(string s) {
	return string__eq(s, _SLIT("true")) || string__eq(s, _SLIT("t"));
}

int string_int(string s) {
	Option_i64 _t2 = strconv__common_parse_int(s, 0, 32, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(i64*) _t2.data = 0;
	}
	
 	return ((int)( (*(i64*)_t2.data)));
}

i64 string_i64(string s) {
	Option_i64 _t2 = strconv__common_parse_int(s, 0, 64, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(i64*) _t2.data = 0;
	}
	
 	return  (*(i64*)_t2.data);
}

i8 string_i8(string s) {
	Option_i64 _t2 = strconv__common_parse_int(s, 0, 8, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(i64*) _t2.data = 0;
	}
	
 	return ((i8)( (*(i64*)_t2.data)));
}

i16 string_i16(string s) {
	Option_i64 _t2 = strconv__common_parse_int(s, 0, 16, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(i64*) _t2.data = 0;
	}
	
 	return ((i16)( (*(i64*)_t2.data)));
}

f32 string_f32(string s) {
	return ((f32)(strconv__atof64(s)));
}

f64 string_f64(string s) {
	return strconv__atof64(s);
}

u8 string_byte(string s) {
	Option_u64 _t2 = strconv__common_parse_uint(s, 0, 8, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(u64*) _t2.data = 0U;
	}
	
 	return ((byte)( (*(u64*)_t2.data)));
}

u16 string_u16(string s) {
	Option_u64 _t2 = strconv__common_parse_uint(s, 0, 16, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(u64*) _t2.data = 0U;
	}
	
 	return ((u16)( (*(u64*)_t2.data)));
}

u32 string_u32(string s) {
	Option_u64 _t2 = strconv__common_parse_uint(s, 0, 32, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(u64*) _t2.data = 0U;
	}
	
 	return ((u32)( (*(u64*)_t2.data)));
}

u64 string_u64(string s) {
	Option_u64 _t2 = strconv__common_parse_uint(s, 0, 64, false, false);
	if (_t2.state != 0) { /*or block*/ 
		IError err = _t2.err;
		*(u64*) _t2.data = 0U;
	}
	
 	return  (*(u64*)_t2.data);
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL bool string__eq(string s, string a) {
	if (s.str == 0) {
		Dpanic(_SLIT("string.eq(): nil string"));
		VUNREACHABLE();
	}
	if (s.len != a.len) {
		return false;
	}
	if (s.len > 0) {
		int last_idx = s.len - 1;
		if (s.str[ last_idx] != a.str[ last_idx]) {
			return false;
		}
	}
	{ // Unsafe block
		return vmemcmp(s.str, a.str, a.len) == 0;
	}
	return 0;
}

// Attr: [direct_array_access]
int string_compare(string s, string a) {
	int min_len = (s.len < a.len ? (s.len) : (a.len));
	for (int i = 0; i < min_len; ++i) {
		if (s.str[ i] < a.str[ i]) {
			return -1;
		}
		if (s.str[ i] > a.str[ i]) {
			return 1;
		}
	}
	if (s.len < a.len) {
		return -1;
	}
	if (s.len > a.len) {
		return 1;
	}
	return 0;
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL bool string__lt(string s, string a) {
	for (int i = 0; i < s.len; ++i) {
		if (i >= a.len || s.str[ i] > a.str[ i]) {
			return false;
		} else if (s.str[ i] < a.str[ i]) {
			return true;
		}
	}
	if (s.len < a.len) {
		return true;
	}
	return false;
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL string string__plus(string s, string a) {
	int new_len = a.len + s.len;
	string res = (string){.str = malloc_noscan(new_len + 1), .len = new_len};
	for (int j = 0; j < s.len; ++j) {
		{ // Unsafe block
			res.str[j] = s.str[j];
		}
	}
	for (int j = 0; j < a.len; ++j) {
		{ // Unsafe block
			res.str[s.len + j] = a.str[j];
		}
	}
	{ // Unsafe block
		res.str[new_len] = 0;
	}
	return res;
}

Array_string string_split(string s, string delim) {
	return string_split_nth(s, delim, 0);
}

// Attr: [direct_array_access]
Array_string string_split_nth(string s, string delim, int nth) {
	Array_string res = __new_array_with_default(0, 0, sizeof(string), 0);
	int i = 0;

	if (delim.len == (0)) {
		i = 1;
		for (int _t1 = 0; _t1 < s.len; ++_t1) {
			byte ch = s.str[_t1];
			if (nth > 0 && i >= nth) {
				array_push((array*)&res, _MOV((string[]){ string_substr(s, i, s.len) }));
				break;
			}
			array_push((array*)&res, _MOV((string[]){ byte_ascii_str(ch) }));
			i++;
		}
		return res;
	}
	else if (delim.len == (1)) {
		int start = 0;
		byte delim_byte = delim.str[ 0];
		for (;;) {
			if (!(i < s.len)) break;
			if (s.str[ i] == delim_byte) {
				bool was_last = nth > 0 && res.len == nth - 1;
				if (was_last) {
					break;
				}
				string val = string_substr(s, start, i);
				array_push((array*)&res, _MOV((string[]){ val }));
				start = i + delim.len;
				i = start;
			} else {
				i++;
			}
		}
		if (nth < 1 || res.len < nth) {
			array_push((array*)&res, _MOV((string[]){ string_substr(s, start, s.len) }));
		}
		return res;
	}
	else {
		int start = 0;
		for (;;) {
			if (!(i <= s.len)) break;
			bool is_delim = i + delim.len <= s.len && string__eq(string_substr(s, i, i + delim.len), delim);
			if (is_delim) {
				bool was_last = nth > 0 && res.len == nth - 1;
				if (was_last) {
					break;
				}
				string val = string_substr(s, start, i);
				array_push((array*)&res, _MOV((string[]){ val }));
				start = i + delim.len;
				i = start;
			} else {
				i++;
			}
		}
		if (nth < 1 || res.len < nth) {
			array_push((array*)&res, _MOV((string[]){ string_substr(s, start, s.len) }));
		}
		return res;
	};
	return __new_array(0, 0, sizeof(string));
}

// Attr: [direct_array_access]
Array_string string_split_into_lines(string s) {
	Array_string res = __new_array_with_default(0, 0, sizeof(string), 0);
	if (s.len == 0) {
		return res;
	}
	int start = 0;
	int end = 0;
	for (int i = 0; i < s.len; i++) {
		if (s.str[ i] == 10) {
			end = (i > 0 && s.str[ i - 1] == 13 ? (i - 1) : (i));
			array_push((array*)&res, _MOV((string[]){ (start == end ? (_SLIT("")) : (string_substr(s, start, end))) }));
			start = i + 1;
		}
	}
	if (start < s.len) {
		array_push((array*)&res, _MOV((string[]){ string_substr(s, start, s.len) }));
	}
	return res;
}

VV_LOCAL_SYMBOL string string_substr2(string s, int start, int _end, bool end_max) {
	int end = (end_max ? (s.len) : (_end));
	return string_substr(s, start, end);
}

// Attr: [direct_array_access]
string string_substr(string s, int start, int end) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (start > end || start > s.len || end > s.len || start < 0 || end < 0) {
			Dpanic( str_intp(4, _MOV((StrIntpData[]){{_SLIT("substr("), 0xfe07, {.d_i32 = start}}, {_SLIT(", "), 0xfe07, {.d_i32 = end}}, {_SLIT(") out of bounds (len="), 0xfe07, {.d_i32 = s.len}}, {_SLIT(")"), 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	int len = end - start;
	if (len == s.len) {
		return string_clone(s);
	}
	string res = (string){.str = malloc_noscan(len + 1), .len = len};
	for (int i = 0; i < len; ++i) {
		{ // Unsafe block
			res.str[i] = s.str[start + i];
		}
	}
	{ // Unsafe block
		res.str[len] = 0;
	}
	return res;
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL int string_index_(string s, string p) {
	if (p.len > s.len || p.len == 0) {
		return -1;
	}
	if (p.len > 2) {
		return string_index_kmp(s, p);
	}
	int i = 0;
	for (;;) {
		if (!(i < s.len)) break;
		int j = 0;
		for (;;) {
			if (!(j < p.len && s.str[i + j] == p.str[j])) break;
			j++;
		}
		if (j == p.len) {
			return i;
		}
		i++;
	}
	return -1;
}

Option_int string_index(string s, string p) {
	int idx = string_index_(s, p);
	if (idx == -1) {
		return (Option_int){ .state=2, .err=_const_none__, .data={EMPTY_STRUCT_INITIALIZATION} };
	}
	Option_int _t2;
	opt_ok(&(int[]) { idx }, (Option*)(&_t2), sizeof(int));
	return _t2;
}

// Attr: [direct_array_access]
// Attr: [manualfree]
VV_LOCAL_SYMBOL int string_index_kmp(string s, string p) {
bool string_index_kmp_defer_0 = false;
Array_int prefix;
	if (p.len > s.len) {
		return -1;
	}
	prefix = __new_array_with_default(p.len, 0, sizeof(int), 0);
	string_index_kmp_defer_0 = true;
	int j = 0;
	for (int i = 1; i < p.len; i++) {
		for (;;) {
			if (!(p.str[j] != p.str[i] && j > 0)) break;
			j = ((int*)prefix.data)[j - 1];
		}
		if (p.str[j] == p.str[i]) {
			j++;
		}
		((int*)prefix.data)[i] = j;
	}
	j = 0;
	for (int i = 0; i < s.len; ++i) {
		for (;;) {
			if (!(p.str[j] != s.str[i] && j > 0)) break;
			j = ((int*)prefix.data)[j - 1];
		}
		if (p.str[j] == s.str[i]) {
			j++;
		}
		if (j == p.len) {
			int _t2 = i - p.len + 1;
			// Defer begin
			if (string_index_kmp_defer_0) {
				array_free(&prefix);
			}
			// Defer end
			return _t2;
		}
	}
	int _t3 = -1;
	// Defer begin
	if (string_index_kmp_defer_0) {
		array_free(&prefix);
	}
	// Defer end
	return _t3;
}

int string_index_any(string s, string chars) {
	for (int i = 0; i < s.len; ++i) {
		byte ss = s.str[i];
		for (int _t1 = 0; _t1 < chars.len; ++_t1) {
			byte c = chars.str[_t1];
			if (c == ss) {
				return i;
			}
		}
	}
	return -1;
}

// Attr: [direct_array_access]
VV_LOCAL_SYMBOL int string_last_index_(string s, string p) {
	if (p.len > s.len || p.len == 0) {
		return -1;
	}
	int i = s.len - p.len;
	for (;;) {
		if (!(i >= 0)) break;
		int j = 0;
		for (;;) {
			if (!(j < p.len && s.str[i + j] == p.str[j])) break;
			j++;
		}
		if (j == p.len) {
			return i;
		}
		i--;
	}
	return -1;
}

Option_int string_last_index(string s, string p) {
	int idx = string_last_index_(s, p);
	if (idx == -1) {
		return (Option_int){ .state=2, .err=_const_none__, .data={EMPTY_STRUCT_INITIALIZATION} };
	}
	Option_int _t2;
	opt_ok(&(int[]) { idx }, (Option*)(&_t2), sizeof(int));
	return _t2;
}

// Attr: [direct_array_access]
int string_index_after(string s, string p, int start) {
	if (p.len > s.len) {
		return -1;
	}
	int strt = start;
	if (start < 0) {
		strt = 0;
	}
	if (start >= s.len) {
		return -1;
	}
	int i = strt;
	for (;;) {
		if (!(i < s.len)) break;
		int j = 0;
		int ii = i;
		for (;;) {
			if (!(j < p.len && s.str[ii] == p.str[j])) break;
			j++;
			ii++;
		}
		if (j == p.len) {
			return i;
		}
		i++;
	}
	return -1;
}

// Attr: [direct_array_access]
int string_index_byte(string s, byte c) {
	for (int i = 0; i < s.len; ++i) {
		if (s.str[i] == c) {
			return i;
		}
	}
	return -1;
}

// Attr: [direct_array_access]
int string_last_index_byte(string s, byte c) {
	for (int i = s.len - 1; i >= 0; i--) {
		if (s.str[i] == c) {
			return i;
		}
	}
	return -1;
}

// Attr: [direct_array_access]
int string_count(string s, string substr) {
	if (s.len == 0 || substr.len == 0) {
		return 0;
	}
	if (substr.len > s.len) {
		return 0;
	}
	int n = 0;
	if (substr.len == 1) {
		byte target = substr.str[ 0];
		for (int _t3 = 0; _t3 < s.len; ++_t3) {
			byte letter = s.str[_t3];
			if (letter == target) {
				n++;
			}
		}
		return n;
	}
	int i = 0;
	for (;;) {
		i = string_index_after(s, substr, i);
		if (i == -1) {
			return n;
		}
		i += substr.len;
		n++;
	}
	return 0;
}

bool string_contains(string s, string substr) {
	if (substr.len == 0) {
		return true;
	}
	if (string_index_(s, substr) == -1) {
		return false;
	}
	return true;
}

bool string_contains_any(string s, string chars) {
	for (int _t1 = 0; _t1 < chars.len; ++_t1) {
		byte c = chars.str[_t1];
		if (string_contains(s, byte_ascii_str(c))) {
			return true;
		}
	}
	return false;
}

bool string_contains_any_substr(string s, Array_string substrs) {
	if (substrs.len == 0) {
		return true;
	}
	for (int _t2 = 0; _t2 < substrs.len; ++_t2) {
		string sub = ((string*)substrs.data)[_t2];
		if (string_contains(s, sub)) {
			return true;
		}
	}
	return false;
}

// Attr: [direct_array_access]
bool string_starts_with(string s, string p) {
	if (p.len > s.len) {
		return false;
	}
	for (int i = 0; i < p.len; ++i) {
		if (s.str[i] != p.str[i]) {
			return false;
		}
	}
	return true;
}

// Attr: [direct_array_access]
bool string_ends_with(string s, string p) {
	if (p.len > s.len) {
		return false;
	}
	for (int i = 0; i < p.len; ++i) {
		if (p.str[i] != s.str[s.len - p.len + i]) {
			return false;
		}
	}
	return true;
}

// Attr: [direct_array_access]
string string_to_lower(string s) {
	{ // Unsafe block
		byte* b = malloc_noscan(s.len + 1);
		for (int i = 0; i < s.len; ++i) {
			if (s.str[i] >= 'A' && s.str[i] <= 'Z') {
				b[i] = s.str[i] + 32;
			} else {
				b[i] = s.str[i];
			}
		}
		b[s.len] = 0;
		return tos(b, s.len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
bool string_is_lower(string s) {
	for (int i = 0; i < s.len; ++i) {
		if (s.str[ i] >= 'A' && s.str[ i] <= 'Z') {
			return false;
		}
	}
	return true;
}

// Attr: [direct_array_access]
string string_to_upper(string s) {
	{ // Unsafe block
		byte* b = malloc_noscan(s.len + 1);
		for (int i = 0; i < s.len; ++i) {
			if (s.str[i] >= 'a' && s.str[i] <= 'z') {
				b[i] = s.str[i] - 32;
			} else {
				b[i] = s.str[i];
			}
		}
		b[s.len] = 0;
		return tos(b, s.len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [direct_array_access]
bool string_is_upper(string s) {
	for (int i = 0; i < s.len; ++i) {
		if (s.str[ i] >= 'a' && s.str[ i] <= 'z') {
			return false;
		}
	}
	return true;
}

// Attr: [direct_array_access]
string string_capitalize(string s) {
	if (s.len == 0) {
		return _SLIT("");
	}
	byte s0 = s.str[ 0];
	string letter = byte_ascii_str(s0);
	string uletter = string_to_upper(letter);
	if (s.len == 1) {
		return uletter;
	}
	string srest = string_substr(s, 1, s.len);
	string res = string__plus(uletter, srest);
	return res;
}

// Attr: [direct_array_access]
bool string_is_capital(string s) {
	if (s.len == 0 || !(s.str[ 0] >= 'A' && s.str[ 0] <= 'Z')) {
		return false;
	}
	for (int i = 1; i < s.len; ++i) {
		if (s.str[ i] >= 'A' && s.str[ i] <= 'Z') {
			return false;
		}
	}
	return true;
}

// Attr: [direct_array_access]
bool string_starts_with_capital(string s) {
	if (s.len == 0 || !(s.str[ 0] >= 'A' && s.str[ 0] <= 'Z')) {
		return false;
	}
	return true;
}

string string_title(string s) {
	Array_string words = string_split(s, _SLIT(" "));
	Array_string tit = __new_array_with_default(0, 0, sizeof(string), 0);
	for (int _t1 = 0; _t1 < words.len; ++_t1) {
		string word = ((string*)words.data)[_t1];
		array_push((array*)&tit, _MOV((string[]){ string_capitalize(word) }));
	}
	string title = Array_string_join(tit, _SLIT(" "));
	return title;
}

bool string_is_title(string s) {
	Array_string words = string_split(s, _SLIT(" "));
	for (int _t1 = 0; _t1 < words.len; ++_t1) {
		string word = ((string*)words.data)[_t1];
		if (!string_is_capital(word)) {
			return false;
		}
	}
	return true;
}

string string_find_between(string s, string start, string end) {
	int start_pos = string_index_(s, start);
	if (start_pos == -1) {
		return _SLIT("");
	}
	string val = string_substr(s, start_pos + start.len, s.len);
	int end_pos = string_index_(val, end);
	if (end_pos == -1) {
		return val;
	}
	return string_substr(val, 0, end_pos);
}

string string_trim_space(string s) {
	return string_trim(s, _SLIT(" \n\t\v\f\r"));
}

// Attr: [direct_array_access]
string string_trim(string s, string cutset) {
	if (s.len < 1 || cutset.len < 1) {
		return string_clone(s);
	}
	int pos_left = 0;
	int pos_right = s.len - 1;
	bool cs_match = true;
	for (;;) {
		if (!(pos_left <= s.len && pos_right >= -1 && cs_match)) break;
		cs_match = false;
		for (int _t2 = 0; _t2 < cutset.len; ++_t2) {
			byte cs = cutset.str[_t2];
			if (s.str[ pos_left] == cs) {
				pos_left++;
				cs_match = true;
				break;
			}
		}
		for (int _t3 = 0; _t3 < cutset.len; ++_t3) {
			byte cs = cutset.str[_t3];
			if (s.str[ pos_right] == cs) {
				pos_right--;
				cs_match = true;
				break;
			}
		}
		if (pos_left > pos_right) {
			return _SLIT("");
		}
	}
	return string_substr(s, pos_left, pos_right + 1);
}

// Attr: [direct_array_access]
string string_trim_left(string s, string cutset) {
	if (s.len < 1 || cutset.len < 1) {
		return string_clone(s);
	}
	int pos = 0;
	for (;;) {
		if (!(pos < s.len)) break;
		bool found = false;
		for (int _t2 = 0; _t2 < cutset.len; ++_t2) {
			byte cs = cutset.str[_t2];
			if (s.str[ pos] == cs) {
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
		pos++;
	}
	return string_substr(s, pos, s.len);
}

// Attr: [direct_array_access]
string string_trim_right(string s, string cutset) {
	if (s.len < 1 || cutset.len < 1) {
		return string_clone(s);
	}
	int pos = s.len - 1;
	for (;;) {
		if (!(pos >= 0)) break;
		bool found = false;
		for (int _t2 = 0; _t2 < cutset.len; ++_t2) {
			byte cs = cutset.str[_t2];
			if (s.str[ pos] == cs) {
				found = true;
			}
		}
		if (!found) {
			break;
		}
		pos--;
	}
	if (pos < 0) {
		return _SLIT("");
	}
	return string_substr(s, 0, pos + 1);
}

string string_trim_prefix(string s, string str) {
	if (string_starts_with(s, str)) {
		return string_substr(s, str.len, s.len);
	}
	return string_clone(s);
}

string string_trim_suffix(string s, string str) {
	if (string_ends_with(s, str)) {
		return string_substr(s, 0, s.len - str.len);
	}
	return string_clone(s);
}

int compare_strings(string* a, string* b) {
	if (string__lt(*a, *b)) {
		return -1;
	}
	if (string__lt(*b, *a)) {
		return 1;
	}
	return 0;
}

VV_LOCAL_SYMBOL int compare_strings_by_len(string* a, string* b) {
	if (a->len < b->len) {
		return -1;
	}
	if (a->len > b->len) {
		return 1;
	}
	return 0;
}

VV_LOCAL_SYMBOL int compare_lower_strings(string* a, string* b) {
	string aa = string_to_lower(/*rec*/*a);
	string bb = string_to_lower(/*rec*/*b);
	return compare_strings(&aa, &bb);
}

void Array_string_sort_ignore_case(Array_string* s) {
	array_sort_with_compare(s, (voidptr)compare_lower_strings);
}

void Array_string_sort_by_len(Array_string* s) {
	array_sort_with_compare(s, (voidptr)compare_strings_by_len);
}

string string_str(string s) {
	return string_clone(s);
}

VV_LOCAL_SYMBOL byte string_at(string s, int idx) {
	#if !defined(CUSTOM_DEFINE_no_bounds_checking)
	{
		if (idx < 0 || idx >= s.len) {
			Dpanic( str_intp(3, _MOV((StrIntpData[]){{_SLIT("string index out of range: "), 0xfe07, {.d_i32 = idx}}, {_SLIT(" / "), 0xfe07, {.d_i32 = s.len}}, {_SLIT0, 0, { .d_c = 0 }}})));
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return s.str[idx];
	}
	return 0;
}

VV_LOCAL_SYMBOL Option_byte string_at_with_check(string s, int idx) {
	if (idx < 0 || idx >= s.len) {
		return (Option_byte){ .state=2, .err=Derror(_SLIT("string index out of range")), .data={EMPTY_STRUCT_INITIALIZATION} };
	}
	{ // Unsafe block
		Option_byte _t2;
		opt_ok(&(byte[]) { s.str[idx] }, (Option*)(&_t2), sizeof(byte));
		return _t2;
	}
	return (Option_byte){0};
}

// Attr: [inline]
inline bool byte_is_space(byte c) {
	return c == 32 || (c > 8 && c < 14) || (c == 0x85) || (c == 0xa0);
}

// Attr: [inline]
inline bool byte_is_digit(byte c) {
	return c >= '0' && c <= '9';
}

// Attr: [inline]
inline bool byte_is_hex_digit(byte c) {
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Attr: [inline]
inline bool byte_is_oct_digit(byte c) {
	return c >= '0' && c <= '7';
}

// Attr: [inline]
inline bool byte_is_bin_digit(byte c) {
	return c == '0' || c == '1';
}

// Attr: [inline]
inline bool byte_is_letter(byte c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Attr: [inline]
inline bool byte_is_alnum(byte c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Attr: [manualfree]
// Attr: [unsafe]
void string_free(string* s) {
	if (s->is_lit == -98761234) {
		byte* double_free_msg = ((byte*)("double string.free() detected\n"));
		int double_free_msg_len = vstrlen(double_free_msg);
		#if defined(_VFREESTANDING)
		{
		}
		#else
		{
			_write_buf_to_fd(1, double_free_msg, double_free_msg_len);
		}
		#endif
		return;
	}
	if (s->is_lit == 1 || s->str == 0) {
		return;
	}
	Dfree(s->str);
	s->is_lit = -98761234;
}

string string_before(string s, string sub) {
	int pos = string_index_(s, sub);
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, 0, pos);
}

string string_all_before(string s, string sub) {
	int pos = string_index_(s, sub);
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, 0, pos);
}

string string_all_before_last(string s, string sub) {
	int pos = string_last_index_(s, sub);
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, 0, pos);
}

string string_all_after(string s, string sub) {
	int pos = string_index_(s, sub);
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, pos + sub.len, s.len);
}

string string_all_after_last(string s, string sub) {
	int pos = string_last_index_(s, sub);
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, pos + sub.len, s.len);
}

string string_after(string s, string sub) {
	return string_all_after_last(s, sub);
}

string string_after_char(string s, byte sub) {
	int pos = -1;
	for (int i = 0; i < s.len; ++i) {
		byte c = s.str[i];
		if (c == sub) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		return string_clone(s);
	}
	return string_substr(s, pos + 1, s.len);
}

string Array_string_join(Array_string a, string sep) {
	if (a.len == 0) {
		return _SLIT("");
	}
	int len = 0;
	for (int _t2 = 0; _t2 < a.len; ++_t2) {
		string val = ((string*)a.data)[_t2];
		len += val.len + sep.len;
	}
	len -= sep.len;
	string res = (string){.str = malloc_noscan(len + 1), .len = len};
	int idx = 0;
	for (int i = 0; i < a.len; ++i) {
		string val = ((string*)a.data)[i];
		{ // Unsafe block
			vmemcpy(res.str + idx, val.str, val.len);
			idx += val.len;
		}
		if (i != a.len - 1) {
			{ // Unsafe block
				vmemcpy(res.str + idx, sep.str, sep.len);
				idx += sep.len;
			}
		}
	}
	{ // Unsafe block
		res.str[res.len] = 0;
	}
	return res;
}

string Array_string_join_lines(Array_string s) {
	return Array_string_join(s, _SLIT("\n"));
}

string string_reverse(string s) {
	if (s.len == 0 || s.len == 1) {
		return string_clone(s);
	}
	string res = (string){.str = malloc_noscan(s.len + 1), .len = s.len};
	for (int i = s.len - 1; i >= 0; i--) {
		{ // Unsafe block
			res.str[s.len - i - 1] = string_at(s, i);
		}
	}
	{ // Unsafe block
		res.str[res.len] = 0;
	}
	return res;
}

string string_limit(string s, int max) {
	Array_rune u = string_runes(s);
	if (u.len <= max) {
		return string_clone(s);
	}
	return Array_rune_string(array_slice(u, 0, max));
}

int string_hash(string s) {
	u32 h = ((u32)(0U));
	if (h == 0U && s.len > 0) {
		for (int _t1 = 0; _t1 < s.len; ++_t1) {
			byte c = s.str[_t1];
			h = h * 31U + ((u32)(c));
		}
	}
	return ((int)(h));
}

Array_byte string_bytes(string s) {
	if (s.len == 0) {
		return __new_array_with_default(0, 0, sizeof(byte), 0);
	}
	Array_byte buf = __new_array_with_default(s.len, 0, sizeof(byte), 0);
	vmemcpy(buf.data, s.str, s.len);
	return buf;
}

string string_repeat(string s, int count) {
	if (count < 0) {
		Dpanic( str_intp(2, _MOV((StrIntpData[]){{_SLIT("string.repeat: count is negative: "), 0xfe07, {.d_i32 = count}}, {_SLIT0, 0, { .d_c = 0 }}})));
		VUNREACHABLE();
	} else if (count == 0) {
		return _SLIT("");
	} else if (count == 1) {
		return string_clone(s);
	}
	byte* ret = malloc_noscan(s.len * count + 1);
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < s.len; ++j) {
			{ // Unsafe block
				ret[i * s.len + j] = string_at(s, j);
			}
		}
	}
	int new_len = s.len * count;
	{ // Unsafe block
		ret[new_len] = 0;
	}
	return byte_vstring_with_len(ret, new_len);
}

Array_string string_fields(string s) {
	Array_string res = __new_array_with_default(0, 0, sizeof(string), 0);
	int word_start = 0;
	int word_len = 0;
	bool is_in_word = false;
	bool is_space = false;
	for (int i = 0; i < s.len; ++i) {
		byte c = s.str[i];
		is_space = (c == 32 || c == 9 || c == 10);
		if (!is_space) {
			word_len++;
		}
		if (!is_in_word && !is_space) {
			word_start = i;
			is_in_word = true;
			continue;
		}
		if (is_space && is_in_word) {
			array_push((array*)&res, _MOV((string[]){ string_substr(s, word_start, word_start + word_len) }));
			is_in_word = false;
			word_len = 0;
			word_start = 0;
			continue;
		}
	}
	if (is_in_word && word_len > 0) {
		array_push((array*)&res, _MOV((string[]){ string_substr(s, word_start, s.len) }));
	}
	return res;
}

string string_strip_margin(string s) {
	return string_strip_margin_custom(s, '|');
}

// Attr: [direct_array_access]
string string_strip_margin_custom(string s, byte del) {
	byte sep = del;
	if (byte_is_space(sep)) {
		eprintln(_SLIT("Warning: `strip_margin` cannot use white-space as a delimiter"));
		eprintln(_SLIT("    Defaulting to `|`"));
		sep = '|';
	}
	byte* ret = malloc_noscan(s.len + 1);
	int count = 0;
	for (int i = 0; i < s.len; i++) {
		if (s.str[ i] == 10 || s.str[ i] == 13) {
			{ // Unsafe block
				ret[count] = s.str[ i];
			}
			count++;
			if (s.str[ i] == 13 && i < s.len - 1 && s.str[ i + 1] == 10) {
				{ // Unsafe block
					ret[count] = s.str[ i + 1];
				}
				count++;
				i++;
			}
			for (;;) {
				if (!(s.str[ i] != sep)) break;
				i++;
				if (i >= s.len) {
					break;
				}
			}
		} else {
			{ // Unsafe block
				ret[count] = s.str[ i];
			}
			count++;
		}
	}
	{ // Unsafe block
		ret[count] = 0;
		return byte_vstring_with_len(ret, count);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [unsafe]
Array_byte byteptr_vbytes(byteptr data, int len) {
	return voidptr_vbytes(((voidptr)(data)), len);
}

// Attr: [unsafe]
string byteptr_vstring(byteptr bp) {
	return (string){.str = bp, .len = vstrlen(bp)};
}

// Attr: [unsafe]
string byteptr_vstring_with_len(byteptr bp, int len) {
	return (string){.str = bp, .len = len, .is_lit = 0};
}

// Attr: [unsafe]
string charptr_vstring(charptr cp) {
	return (string){.str = ((byteptr)(cp)), .len = vstrlen_char(cp), .is_lit = 0};
}

// Attr: [unsafe]
string charptr_vstring_with_len(charptr cp, int len) {
	return (string){.str = ((byteptr)(cp)), .len = len, .is_lit = 0};
}

// Attr: [unsafe]
string byteptr_vstring_literal(byteptr bp) {
	return (string){.str = bp, .len = vstrlen(bp), .is_lit = 1};
}

// Attr: [unsafe]
string byteptr_vstring_literal_with_len(byteptr bp, int len) {
	return (string){.str = bp, .len = len, .is_lit = 1};
}

// Attr: [unsafe]
string charptr_vstring_literal(charptr cp) {
	return (string){.str = ((byteptr)(cp)), .len = vstrlen_char(cp), .is_lit = 1};
}

// Attr: [unsafe]
string charptr_vstring_literal_with_len(charptr cp, int len) {
	return (string){.str = ((byteptr)(cp)), .len = len, .is_lit = 1};
}

string StrIntpType_str(StrIntpType x) {
	switch (x) {
		case StrIntpType__si_no_str: 
			{
				return _SLIT("no_str");
			} break;
		case StrIntpType__si_c: 
			{
				return _SLIT("c");
			} break;
		case StrIntpType__si_u8: 
			{
				return _SLIT("u8");
			} break;
		case StrIntpType__si_i8: 
			{
				return _SLIT("i8");
			} break;
		case StrIntpType__si_u16: 
			{
				return _SLIT("u16");
			} break;
		case StrIntpType__si_i16: 
			{
				return _SLIT("i16");
			} break;
		case StrIntpType__si_u32: 
			{
				return _SLIT("u32");
			} break;
		case StrIntpType__si_i32: 
			{
				return _SLIT("i32");
			} break;
		case StrIntpType__si_u64: 
			{
				return _SLIT("u64");
			} break;
		case StrIntpType__si_i64: 
			{
				return _SLIT("i64");
			} break;
		case StrIntpType__si_f32: 
			{
				return _SLIT("f32");
			} break;
		case StrIntpType__si_f64: 
			{
				return _SLIT("f64");
			} break;
		case StrIntpType__si_g32: 
			{
				return _SLIT("f32");
			} break;
		case StrIntpType__si_g64: 
			{
				return _SLIT("f64");
			} break;
		case StrIntpType__si_e32: 
			{
				return _SLIT("f32");
			} break;
		case StrIntpType__si_e64: 
			{
				return _SLIT("f64");
			} break;
		case StrIntpType__si_s: 
			{
				return _SLIT("s");
			} break;
		case StrIntpType__si_p: 
			{
				return _SLIT("p");
			} break;
		case StrIntpType__si_vp: 
			{
				return _SLIT("vp");
			} break;
	}
	;
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL f32 fabs32(f32 x) {
	return (x < 0 ? (-x) : (x));
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL f64 fabs64(f64 x) {
	return (x < 0 ? (-x) : (x));
}

// Attr: [inline]
inline VV_LOCAL_SYMBOL u64 abs64(i64 x) {
	return (x < 0 ? (((u64)(-x))) : (((u64)(x))));
}

u64 get_str_intp_u64_format(StrIntpType fmt_type, int in_width, int in_precision, bool in_tail_zeros, bool in_sign, byte in_pad_ch, int in_base, bool in_upper_case) {
	u64 width = (in_width != 0 ? (abs64(in_width)) : (((u64)(0U))));
	u64 allign = (in_width > 0 ? (((u64)(1 << 5))) : (((u64)(0U))));
	u64 upper_case = (in_upper_case ? (((u64)(1 << 7))) : (((u64)(0U))));
	u64 sign = (in_sign ? (((u64)(1 << 8))) : (((u64)(0U))));
	u64 precision = (in_precision != 987698 ? ((((u64)((in_precision & 0x7F))) << 9U)) : (((u64)(0x7FU)) << 9U));
	u32 tail_zeros = (in_tail_zeros ? (((u32)(1U)) << 16U) : (((u32)(0U))));
	u64 base = ((u64)(((u32)((in_base & 0xf))) << 27U));
	u64 res = ((u64)(((((((((((((u64)(fmt_type)) & 0x1FU)) | allign) | upper_case) | sign) | precision) | tail_zeros) | (((u64)((width & 0x3FFU))) << 17U)) | base) | (((u64)(in_pad_ch)) << 31U))));
	return res;
}

u32 get_str_intp_u32_format(StrIntpType fmt_type, int in_width, int in_precision, bool in_tail_zeros, bool in_sign, byte in_pad_ch, int in_base, bool in_upper_case) {
	u64 width = (in_width != 0 ? (abs64(in_width)) : (((u32)(0U))));
	u32 allign = (in_width > 0 ? (((u32)(1 << 5))) : (((u32)(0U))));
	u32 upper_case = (in_upper_case ? (((u32)(1 << 7))) : (((u32)(0U))));
	u32 sign = (in_sign ? (((u32)(1 << 8))) : (((u32)(0U))));
	u32 precision = (in_precision != 987698 ? ((((u32)((in_precision & 0x7F))) << 9U)) : (((u32)(0x7FU)) << 9U));
	u32 tail_zeros = (in_tail_zeros ? (((u32)(1U)) << 16U) : (((u32)(0U))));
	u32 base = ((u32)(((u32)((in_base & 0xf))) << 27U));
	u32 res = ((u32)(((((((((((((u32)(fmt_type)) & 0x1FU)) | allign) | upper_case) | sign) | precision) | tail_zeros) | (((u32)((width & 0x3FFU))) << 17U)) | base) | (((u32)((in_pad_ch & 1))) << 31U))));
	return res;
}

// Attr: [manualfree]
VV_LOCAL_SYMBOL void StrIntpData_get_fmt_format(StrIntpData data, strings__Builder* sb) {
	u32 x = data.fmt;
	StrIntpType typ = ((StrIntpType)((x & 0x1FU)));
	int allign = ((int)(((x >> 5U) & 0x01U)));
	bool upper_case = ((((x >> 7U) & 0x01U)) > 0U ? (true) : (false));
	int sign = ((int)(((x >> 8U) & 0x01U)));
	int precision = ((int)(((x >> 9U) & 0x7FU)));
	bool tail_zeros = ((((x >> 16U) & 0x01U)) > 0U ? (true) : (false));
	int width = ((int)(((i16)(((x >> 17U) & 0x3FFU)))));
	int base = (((int)(x >> 27U)) & 0xF);
	byte fmt_pad_ch = ((byte)(((x >> 31U) & 0xFFU)));
	if (typ == StrIntpType__si_no_str) {
		return;
	}
	if (base > 0) {
		base += 2;
	}
	byte pad_ch = ((byte)(' '));
	if (fmt_pad_ch > 0) {
		pad_ch = '0';
	}
	int len0_set = (width > 0 ? (width) : (-1));
	int len1_set = (precision == 0x7F ? (-1) : (precision));
	bool sign_set = (sign == 1 ? (true) : (false));
	strconv__BF_param bf = (strconv__BF_param){
		.pad_ch = pad_ch,
		.len0 = len0_set,
		.len1 = len1_set,
		.positive = true,
		.sign_flag = sign_set,
		.allign = strconv__Align_text__left,
		.rm_tail_zero = tail_zeros,
	};
	if (fmt_pad_ch == 0) {

		if (allign == (0)) {
			bf.allign = strconv__Align_text__left;
		}
		else if (allign == (1)) {
			bf.allign = strconv__Align_text__right;
		}
		else {
			bf.allign = strconv__Align_text__left;
		};
	} else {
		bf.allign = strconv__Align_text__right;
	}
	{ // Unsafe block
		if (typ == StrIntpType__si_s) {
			string s = _SLIT("");
			if (upper_case) {
				s = string_to_upper(data.d.d_s);
			} else {
				s = string_clone(data.d.d_s);
			}
			if (width == 0) {
				strings__Builder_write_string(sb, s);
			} else {
				strconv__format_str_sb(s, bf, sb);
			}
			string_free(&s);
			return;
		}
		if (typ == StrIntpType__si_i8 || typ == StrIntpType__si_i16 || typ == StrIntpType__si_i32 || typ == StrIntpType__si_i64) {
			i64 d = data.d.d_i64;
			if (typ == StrIntpType__si_i8) {
				d = ((i64)(data.d.d_i8));
			} else if (typ == StrIntpType__si_i16) {
				d = ((i64)(data.d.d_i16));
			} else if (typ == StrIntpType__si_i32) {
				d = ((i64)(data.d.d_i32));
			}
			if (base == 0) {
				if (width == 0) {
					string d_str = i64_str(d);
					strings__Builder_write_string(sb, d_str);
					string_free(&d_str);
					return;
				}
				if (d < 0) {
					bf.positive = false;
				}
				strconv__format_dec_sb(abs64(d), bf, sb);
			} else {
				if (base == 3) {
					base = 2;
				}
				string hx = strconv__format_int(d, base);
				if (upper_case) {
					string tmp = hx;
					hx = string_to_upper(hx);
					string_free(&tmp);
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				string_free(&hx);
			}
			return;
		}
		if (typ == StrIntpType__si_u8 || typ == StrIntpType__si_u16 || typ == StrIntpType__si_u32 || typ == StrIntpType__si_u64) {
			u64 d = data.d.d_u64;
			if (typ == StrIntpType__si_u8) {
				d = ((u64)(data.d.d_u8));
			} else if (typ == StrIntpType__si_u16) {
				d = ((u64)(data.d.d_u16));
			} else if (typ == StrIntpType__si_u32) {
				d = ((u64)(data.d.d_u32));
			}
			if (base == 0) {
				if (width == 0) {
					string d_str = u64_str(d);
					strings__Builder_write_string(sb, d_str);
					string_free(&d_str);
					return;
				}
				strconv__format_dec_sb(d, bf, sb);
			} else {
				if (base == 3) {
					base = 2;
				}
				string hx = strconv__format_uint(d, base);
				if (upper_case) {
					string tmp = hx;
					hx = string_to_upper(hx);
					string_free(&tmp);
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				string_free(&hx);
			}
			return;
		}
		if (typ == StrIntpType__si_p) {
			u64 d = data.d.d_u64;
			base = 16;
			if (base == 0) {
				if (width == 0) {
					string d_str = u64_str(d);
					strings__Builder_write_string(sb, d_str);
					string_free(&d_str);
					return;
				}
				strconv__format_dec_sb(d, bf, sb);
			} else {
				string hx = strconv__format_uint(d, base);
				if (upper_case) {
					string tmp = hx;
					hx = string_to_upper(hx);
					string_free(&tmp);
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				string_free(&hx);
			}
			return;
		}
		bool use_default_str = false;
		if (width == 0 && precision == 0x7F) {
			bf.len1 = 3;
			use_default_str = true;
		}
		if (bf.len1 < 0) {
			bf.len1 = 3;
		}
		switch (typ) {
			case StrIntpType__si_f32: 
				{
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						if (use_default_str) {
							string f = f32_str(data.d.d_f32);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						} else {
							if (data.d.d_f32 < 0) {
								bf.positive = false;
							}
							string f = strconv__format_fl(data.d.d_f32, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
					}
					#endif
				} break;
			case StrIntpType__si_f64: 
				{
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						if (use_default_str) {
							string f = f64_str(data.d.d_f64);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						} else {
							if (data.d.d_f64 < 0) {
								bf.positive = false;
							}
							strconv__Float64u f_union = (strconv__Float64u){.f = data.d.d_f64,};
							if (f_union.u == _const_strconv__double_minus_zero) {
								bf.positive = false;
							}
							string f = strconv__format_fl(data.d.d_f64, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
					}
					#endif
				} break;
			case StrIntpType__si_g32: 
				{
					if (use_default_str) {
						#if !defined(CUSTOM_DEFINE_nofloat)
						{
							string f = f32_strg(data.d.d_f32);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
						#endif
					} else {
						if (data.d.d_f32 == _const_strconv__single_plus_zero) {
							string tmp_str = _SLIT("0");
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
							return;
						}
						if (data.d.d_f32 == _const_strconv__single_minus_zero) {
							string tmp_str = _SLIT("-0");
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
							return;
						}
						if (data.d.d_f32 == _const_strconv__single_plus_infinity) {
							string tmp_str = _SLIT("+inf");
							if (upper_case) {
								tmp_str = _SLIT("+INF");
							}
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
						}
						if (data.d.d_f32 == _const_strconv__single_minus_infinity) {
							string tmp_str = _SLIT("-inf");
							if (upper_case) {
								tmp_str = _SLIT("-INF");
							}
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
						}
						if (data.d.d_f32 < 0) {
							bf.positive = false;
						}
						f32 d = fabs32(data.d.d_f32);
						if (d < 999999.0 && d >= 0.00001) {
							string f = strconv__format_fl(data.d.d_f32, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
							return;
						}
						string f = strconv__format_es(data.d.d_f32, bf);
						if (upper_case) {
							string tmp = f;
							f = string_to_upper(f);
							string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						string_free(&f);
					}
				} break;
			case StrIntpType__si_g64: 
				{
					if (use_default_str) {
						#if !defined(CUSTOM_DEFINE_nofloat)
						{
							string f = f64_strg(data.d.d_f64);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
						#endif
					} else {
						if (data.d.d_f64 == _const_strconv__double_plus_zero) {
							string tmp_str = _SLIT("0");
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
							return;
						}
						if (data.d.d_f64 == _const_strconv__double_minus_zero) {
							string tmp_str = _SLIT("-0");
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
							return;
						}
						if (data.d.d_f64 == _const_strconv__double_plus_infinity) {
							string tmp_str = _SLIT("+inf");
							if (upper_case) {
								tmp_str = _SLIT("+INF");
							}
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
						}
						if (data.d.d_f64 == _const_strconv__double_minus_infinity) {
							string tmp_str = _SLIT("-inf");
							if (upper_case) {
								tmp_str = _SLIT("-INF");
							}
							strconv__format_str_sb(tmp_str, bf, sb);
							string_free(&tmp_str);
						}
						if (data.d.d_f64 < 0) {
							bf.positive = false;
						}
						f64 d = fabs64(data.d.d_f64);
						if (d < 999999.0 && d >= 0.00001) {
							string f = strconv__format_fl(data.d.d_f64, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
							return;
						}
						string f = strconv__format_es(data.d.d_f64, bf);
						if (upper_case) {
							string tmp = f;
							f = string_to_upper(f);
							string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						string_free(&f);
					}
				} break;
			case StrIntpType__si_e32: 
				{
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						bf.len1 = 6;
						if (use_default_str) {
							string f = f32_str(data.d.d_f32);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						} else {
							if (data.d.d_f32 < 0) {
								bf.positive = false;
							}
							string f = strconv__format_es(data.d.d_f32, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
					}
					#endif
				} break;
			case StrIntpType__si_e64: 
				{
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						bf.len1 = 6;
						if (use_default_str) {
							string f = f64_str(data.d.d_f64);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						} else {
							if (data.d.d_f64 < 0) {
								bf.positive = false;
							}
							string f = strconv__format_es(data.d.d_f64, bf);
							if (upper_case) {
								string tmp = f;
								f = string_to_upper(f);
								string_free(&tmp);
							}
							strings__Builder_write_string(sb, f);
							string_free(&f);
						}
					}
					#endif
				} break;
			case StrIntpType__si_c: 
				{
					string ss = utf32_to_str(data.d.d_c);
					strings__Builder_write_string(sb, ss);
					string_free(&ss);
				} break;
			case StrIntpType__si_vp: 
				{
					string ss = u64_hex(((u64)(data.d.d_vp)));
					strings__Builder_write_string(sb, ss);
					string_free(&ss);
				} break;
			case StrIntpType__si_no_str:
			case StrIntpType__si_u8:
			case StrIntpType__si_i8:
			case StrIntpType__si_u16:
			case StrIntpType__si_i16:
			case StrIntpType__si_u32:
			case StrIntpType__si_i32:
			case StrIntpType__si_u64:
			case StrIntpType__si_i64:
			case StrIntpType__si_s:
			case StrIntpType__si_p:
			default:
				{
					strings__Builder_write_string(sb, _SLIT("***ERROR!***"));
				} break;
		}
		;
	}
}

// Attr: [manualfree]
string str_intp(int data_len, voidptr in_data) {
	strings__Builder res = strings__new_builder(256);
	{ // Unsafe block
		int i = 0;
		for (;;) {
			if (!(i < data_len)) break;
			StrIntpData* data = ((StrIntpData*)(((byte*)(in_data)) + (((int)(sizeof(StrIntpData))) * i)));
			if (data->str.len != 0) {
				strings__Builder_write_string(&res, data->str);
			}
			if (data->fmt != 0U) {
				StrIntpData_get_fmt_format(/*rec*/*data, &res);
			}
			i++;
		}
	}
	string ret = strings__Builder_str(&res);
	strings__Builder_free(&res);
	return ret;
}

// Attr: [inline]
inline string str_intp_sq(string in_str) {
	return  str_intp(3, _MOV((StrIntpData[]){{_SLIT("str_intp(2, _MOV((StrIntpData[]){{_SLIT(\"\'\"), "), 0xfe10, {.d_s = _const_si_s_code}}, {_SLIT(", {.d_s = "), 0xfe10, {.d_s = in_str}}, {_SLIT("}},{_SLIT(\"\'\"), 0, {.d_c = 0 }}}))"), 0, { .d_c = 0 }}}));
}

// Attr: [inline]
inline string str_intp_rune(string in_str) {
	return  str_intp(3, _MOV((StrIntpData[]){{_SLIT("str_intp(2, _MOV((StrIntpData[]){{_SLIT(\"`\"), "), 0xfe10, {.d_s = _const_si_s_code}}, {_SLIT(", {.d_s = "), 0xfe10, {.d_s = in_str}}, {_SLIT("}},{_SLIT(\"`\"), 0, {.d_c = 0 }}}))"), 0, { .d_c = 0 }}}));
}

// Attr: [inline]
inline string str_intp_g32(string in_str) {
	return  str_intp(3, _MOV((StrIntpData[]){{_SLIT("str_intp(1, _MOV((StrIntpData[]){{_SLIT0, "), 0xfe10, {.d_s = _const_si_g32_code}}, {_SLIT(", {.d_f32 = "), 0xfe10, {.d_s = in_str}}, {_SLIT(" }}}))"), 0, { .d_c = 0 }}}));
}

// Attr: [inline]
inline string str_intp_g64(string in_str) {
	return  str_intp(3, _MOV((StrIntpData[]){{_SLIT("str_intp(1, _MOV((StrIntpData[]){{_SLIT0, "), 0xfe10, {.d_s = _const_si_g64_code}}, {_SLIT(", {.d_f64 = "), 0xfe10, {.d_s = in_str}}, {_SLIT(" }}}))"), 0, { .d_c = 0 }}}));
}

// Attr: [manualfree]
string str_intp_sub(string base_str, string in_str) {
	Option_int _t1 = string_index(base_str, _SLIT("%%"));
	if (_t1.state != 0) { /*or block*/ 
		IError err = _t1.err;
		eprintln(_SLIT("No strin interpolation %% parameteres"));
		Dexit(1);
		VUNREACHABLE();
	;
	}
	
 	int index =  (*(int*)_t1.data);
	{ // Unsafe block
		string st_str = string_substr(base_str, 0, index);
		if (index + 2 < base_str.len) {
			string en_str = string_substr(base_str, index + 2, base_str.len);
			string res_str =  str_intp(5, _MOV((StrIntpData[]){{_SLIT("str_intp(2, _MOV((StrIntpData[]){{_SLIT(\""), 0xfe10, {.d_s = st_str}}, {_SLIT("\"), "), 0xfe10, {.d_s = _const_si_s_code}}, {_SLIT(", {.d_s = "), 0xfe10, {.d_s = in_str}}, {_SLIT(" }},{_SLIT(\""), 0xfe10, {.d_s = en_str}}, {_SLIT("\"), 0, {.d_c = 0}}}))"), 0, { .d_c = 0 }}}));
			string_free(&st_str);
			string_free(&en_str);
			return res_str;
		}
		string res2_str =  str_intp(4, _MOV((StrIntpData[]){{_SLIT("str_intp(1, _MOV((StrIntpData[]){{_SLIT(\""), 0xfe10, {.d_s = st_str}}, {_SLIT("\"), "), 0xfe10, {.d_s = _const_si_s_code}}, {_SLIT(", {.d_s = "), 0xfe10, {.d_s = in_str}}, {_SLIT(" }}}))"), 0, { .d_c = 0 }}}));
		string_free(&st_str);
		return res2_str;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

u16* string_to_wide(string _str) {
	#if defined(_WIN32)
	{
	}
	#else
	{
		return 0;
	}
	#endif
	return 0;
}

// Attr: [unsafe]
string string_from_wide(u16* _wstr) {
	#if defined(_WIN32)
	{
	}
	#else
	{
		return _SLIT("");
	}
	#endif
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [unsafe]
string string_from_wide2(u16* _wstr, int len) {
	#if defined(_WIN32)
	{
	}
	#else
	{
		return _SLIT("");
	}
	#endif
	return (string){.str=(byteptr)"", .is_lit=1};
}

int utf8_getchar(void) {
	int c = getchar();
	int len = utf8_len(((byte)(~c)));
	if (c < 0) {
		return 0;
	} else if (len == 0) {
		return c;
	} else if (len == 1) {
		return -1;
	} else {
		int uc = (c & ((1 << (7 - len)) - 1));
		for (int i = 0; i + 1 < len; i++) {
			int c2 = getchar();
			if (c2 != -1 && (c2 >> 6) == 2) {
				uc <<= 6;
				uc |= ((c2 & 63));
			} else if (c2 == -1) {
				return 0;
			} else {
				return -1;
			}
		}
		return uc;
	}
	return 0;
}

int utf8_char_len(byte b) {
	return (((0xe5000000 >> (((b >> 3) & 0x1e))) & 3)) + 1;
}

string utf32_to_str(u32 code) {
	{ // Unsafe block
		byte* buffer = malloc_noscan(5);
		string res = utf32_to_str_no_malloc(code, buffer);
		if (res.len == 0) {
			Dfree(buffer);
		}
		return res;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}

// Attr: [manualfree]
// Attr: [unsafe]
string utf32_to_str_no_malloc(u32 code, byte* buf) {
	{ // Unsafe block
		int icode = ((int)(code));
		byte* buffer = ((byte*)(buf));
		if (icode <= 127) {
			buffer[0] = ((byte)(icode));
			buffer[1] = 0;
			return tos(buffer, 1);
		} else if (icode <= 2047) {
			buffer[0] = (192 | ((byte)(icode >> 6)));
			buffer[1] = (128 | ((byte)((icode & 63))));
			buffer[2] = 0;
			return tos(buffer, 2);
		} else if (icode <= 65535) {
			buffer[0] = (224 | ((byte)(icode >> 12)));
			buffer[1] = (128 | ((((byte)(icode >> 6)) & 63)));
			buffer[2] = (128 | ((byte)((icode & 63))));
			buffer[3] = 0;
			return tos(buffer, 3);
		} else if (icode <= 1114111) {
			buffer[0] = (240 | ((byte)(icode >> 18)));
			buffer[1] = (128 | ((((byte)(icode >> 12)) & 63)));
			buffer[2] = (128 | ((((byte)(icode >> 6)) & 63)));
			buffer[3] = (128 | ((byte)((icode & 63))));
			buffer[4] = 0;
			return tos(buffer, 4);
		}
	}
	return _SLIT("");
}

int string_utf32_code(string _rune) {
	if (_rune.len == 0) {
		return 0;
	}
	if (_rune.len == 1) {
		return ((int)(string_at(_rune, 0)));
	}
	byte b = ((byte)(((int)(string_at(_rune, 0)))));
	b = b << _rune.len;
	u32 res = ((u32)(b));
	int shift = 6 - _rune.len;
	for (int i = 1; i < _rune.len; i++) {
		u32 c = ((u32)(string_at(_rune, i)));
		res = ((u32)(res)) << shift;
		res |= (c & 63U);
		shift = 6;
	}
	return ((int)(res));
}

VV_LOCAL_SYMBOL int utf8_len(byte c) {
	int b = 0;
	byte x = c;
	if (((x & 240)) != 0) {
		x >>= 4;
	} else {
		b += 4;
	}
	if (((x & 12)) != 0) {
		x >>= 2;
	} else {
		b += 2;
	}
	if (((x & 2)) == 0) {
		b++;
	}
	return b;
}

int utf8_str_len(string s) {
	int l = 0;
	int i = 0;
	for (;;) {
		if (!(i < s.len)) break;
		l++;
		i += (((0xe5000000 >> (((s.str[i] >> 3) & 0x1e))) & 3)) + 1;
	}
	return l;
}

int utf8_str_visible_length(string s) {
	int l = 0;
	int ul = 1;
	for (int i = 0; i < s.len; i += ul) {
		byte c = s.str[i];
		ul = (((0xe5000000 >> (((s.str[i] >> 3) & 0x1e))) & 3)) + 1;
		if (i + ul > s.len) {
			return l;
		}
		l++;
		if (ul == 1) {
			continue;
		}

		if (ul == (2)) {
			u64 r = ((u64)(((((u16)(c)) << 8U) | s.str[i + 1])));
			if (r >= 0xcc80U && r < 0xcdb0U) {
				l--;
			}
		}
		else if (ul == (3)) {
			u64 r = ((u64)(((((u32)(c)) << 16U) | ((((u32)(s.str[i + 1])) << 8U) | s.str[i + 2]))));
			if ((r >= 0xe1aab0U && r <= 0xe1ac7fU) || (r >= 0xe1b780U && r <= 0xe1b87fU) || (r >= 0xe28390U && r <= 0xe2847fU) || (r >= 0xefb8a0U && r <= 0xefb8afU)) {
				l--;
			} else if ((r >= 0xe18480U && r <= 0xe1859fU) || (r >= 0xe2ba80U && r <= 0xe2bf95U) || (r >= 0xe38080U && r <= 0xe4b77fU) || (r >= 0xe4b880U && r <= 0xea807fU) || (r >= 0xeaa5a0U && r <= 0xeaa79fU) || (r >= 0xeab080U && r <= 0xed9eafU) || (r >= 0xefa480U && r <= 0xefac7fU) || (r >= 0xefb8b8U && r <= 0xefb9afU)) {
				l++;
			}
		}
		else if (ul == (4)) {
			u64 r = ((u64)(((((u32)(c)) << 24U) | (((((u32)(s.str[i + 1])) << 16U) | (((u32)(s.str[i + 2])) << 8U)) | s.str[i + 3]))));
			if ((r >= 0x0f9f8880U && r <= 0xf09f8a8fU) || (r >= 0xf09f8c80U && r <= 0xf09f9c90U) || (r >= 0xf09fa490U && r <= 0xf09fa7afU) || (r >= 0xf0a08080U && r <= 0xf180807fU)) {
				l++;
			}
		}
		else {
		};
	}
	return l;
}

VV_LOCAL_SYMBOL void main__main(void) {
	main__execv_blod(_SLIT("print( (),  (1,2) , `hello, world`)"));
}

VV_LOCAL_SYMBOL void main__execv_blod(string code) {
	string buffer = _SLIT("");
	string fname = _SLIT("");
	int state = 10;
	Array_string args = __new_array_with_default(0, 0, sizeof(string), 0);
	for (int _t1 = 0; _t1 < code.len; ++_t1) {
		byte Dchar = code.str[_t1];
		string cur = byte_ascii_str(Dchar);
		if (string__eq(cur, _SLIT("(")) && state == 10) {
			fname = buffer;
			state = 0;
			buffer = _SLIT("");
		} else if (string__eq(cur, _SLIT("(")) && state != 10) {
			state += 10;
			buffer = /*f*/string__plus(buffer, cur);
		} else if (string__eq(cur, _SLIT("\"")) && state == 0) {
			state = 9999;
		} else if (string__eq(cur, _SLIT("\"")) && state == 9999) {
			state = 0;
		} else if (string__eq(cur, _SLIT("`")) && state == 0) {
			state = 99991;
		} else if (string__eq(cur, _SLIT("`")) && state == 99991) {
			state = 0;
		} else if (string__eq(cur, _SLIT(")")) && state != 0) {
			state -= 10;
			buffer = /*f*/string__plus(buffer, cur);
		} else if (string__eq(cur, _SLIT(")")) && state == 0) {
			if (buffer.len > 0) {
				array_push((array*)&args, _MOV((string[]){ string_clone(string_trim_space(buffer)) }));
			}
			break;
		} else if (string__eq(cur, _SLIT(",")) && state == 0) {
			array_push((array*)&args, _MOV((string[]){ string_clone(string_trim_space(buffer)) }));
			buffer = _SLIT("");
		} else {
			buffer = /*f*/string__plus(buffer, cur);
		}
	}
	if (state != 0) {
		println(_SLIT("compiler error: state != 0"));
	}
	println(_SLIT("semantic analysis complete"));
	println(Array_string_str(args));
	println(fname);
	println(int_str(state));
}

void _vinit(int ___argc, voidptr ___argv) {
#if __STDC_HOSTED__ == 1
	signal(11, v_segmentation_fault_handler);
#endif
	as_cast_type_indexes = new_array_from_c_array(1, 1, sizeof(VCastTypeIndexName), _MOV((VCastTypeIndexName[1]){(VCastTypeIndexName){.tindex = 0,.tname = _SLIT("unknown")}}));

	builtin_init();
	vinit_string_literals();
	{ // Initializations for module strings :
	}
	{ // Initializations for module math.bits :
	_const_math__bits__de_bruijn32tab = new_array_from_c_array(32, 32, sizeof(byte), _MOV((byte[32]){
		((byte)(0)), 1, 28, 2, 29, 14, 24, 3, 30,
		22, 20, 15, 25, 17, 4, 8, 31,
		27, 13, 23, 21, 19, 16, 7, 26,
		12, 18, 6, 11, 5, 10, 9}));
	_const_math__bits__de_bruijn64tab = new_array_from_c_array(64, 64, sizeof(byte), _MOV((byte[64]){
		((byte)(0)), 1, 56, 2, 57, 49, 28, 3, 61,
		58, 42, 50, 38, 29, 17, 4, 62,
		47, 59, 36, 45, 43, 51, 22, 53,
		39, 33, 30, 24, 18, 12, 5, 63,
		55, 48, 27, 60, 41, 37, 16, 46,
		35, 44, 21, 52, 32, 23, 11, 54,
		26, 40, 15, 34, 20, 31, 10, 25,
		14, 19, 9, 13, 8, 7, 6}));
	_const_math__bits__ntz_8_tab = new_array_from_c_array(256, 256, sizeof(byte), _MOV((byte[256]){
		((byte)(0x08)), 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x05,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x06,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x05,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x07,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x05,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x06,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x05,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03,
		0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00}));
	_const_math__bits__pop_8_tab = new_array_from_c_array(256, 256, sizeof(byte), _MOV((byte[256]){
		((byte)(0x00)), 0x01, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03, 0x01,
		0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x01,
		0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x01,
		0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x01,
		0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x04,
		0x05, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07, 0x01,
		0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x04,
		0x05, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07, 0x02,
		0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x04,
		0x05, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07, 0x03,
		0x04, 0x04, 0x05, 0x04, 0x05, 0x05, 0x06, 0x04,
		0x05, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07, 0x04,
		0x05, 0x05, 0x06, 0x05, 0x06, 0x06, 0x07, 0x05,
		0x06, 0x06, 0x07, 0x06, 0x07, 0x07, 0x08}));
	_const_math__bits__rev_8_tab = new_array_from_c_array(256, 256, sizeof(byte), _MOV((byte[256]){
		((byte)(0x00)), 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10,
		0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0, 0x08,
		0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18,
		0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8, 0x04,
		0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14,
		0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4, 0x0c,
		0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c,
		0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc, 0x02,
		0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12,
		0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2, 0x0a,
		0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a,
		0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa, 0x06,
		0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16,
		0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6, 0x0e,
		0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e,
		0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe, 0x01,
		0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11,
		0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1, 0x09,
		0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19,
		0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9, 0x05,
		0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15,
		0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5, 0x0d,
		0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d,
		0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd, 0x03,
		0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13,
		0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3, 0x0b,
		0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b,
		0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb, 0x07,
		0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7, 0x17,
		0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7, 0x0f,
		0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f,
		0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff}));
	_const_math__bits__len_8_tab = new_array_from_c_array(256, 256, sizeof(byte), _MOV((byte[256]){
		((byte)(0x00)), 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05,
		0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
		0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06,
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08}));
	}
	{ // Initializations for module strconv :
	_const_strconv__pos_exp = new_array_from_c_array(309, 309, sizeof(u64), _MOV((u64[309]){
		((u64)(0x3ff0000000000000U)), ((u64)(0x4024000000000000U)), ((u64)(0x4059000000000000U)), ((u64)(0x408f400000000000U)), ((u64)(0x40c3880000000000U)), ((u64)(0x40f86a0000000000U)), ((u64)(0x412e848000000000U)), ((u64)(0x416312d000000000U)), ((u64)(0x4197d78400000000U)),
		((u64)(0x41cdcd6500000000U)), ((u64)(0x4202a05f20000000U)), ((u64)(0x42374876e8000000U)), ((u64)(0x426d1a94a2000000U)), ((u64)(0x42a2309ce5400000U)), ((u64)(0x42d6bcc41e900000U)), ((u64)(0x430c6bf526340000U)), ((u64)(0x4341c37937e08000U)),
		((u64)(0x4376345785d8a000U)), ((u64)(0x43abc16d674ec800U)), ((u64)(0x43e158e460913d00U)), ((u64)(0x4415af1d78b58c40U)), ((u64)(0x444b1ae4d6e2ef50U)), ((u64)(0x4480f0cf064dd592U)), ((u64)(0x44b52d02c7e14af6U)), ((u64)(0x44ea784379d99db4U)),
		((u64)(0x45208b2a2c280291U)), ((u64)(0x4554adf4b7320335U)), ((u64)(0x4589d971e4fe8402U)), ((u64)(0x45c027e72f1f1281U)), ((u64)(0x45f431e0fae6d721U)), ((u64)(0x46293e5939a08ceaU)), ((u64)(0x465f8def8808b024U)), ((u64)(0x4693b8b5b5056e17U)),
		((u64)(0x46c8a6e32246c99cU)), ((u64)(0x46fed09bead87c03U)), ((u64)(0x4733426172c74d82U)), ((u64)(0x476812f9cf7920e3U)), ((u64)(0x479e17b84357691bU)), ((u64)(0x47d2ced32a16a1b1U)), ((u64)(0x48078287f49c4a1dU)), ((u64)(0x483d6329f1c35ca5U)),
		((u64)(0x48725dfa371a19e7U)), ((u64)(0x48a6f578c4e0a061U)), ((u64)(0x48dcb2d6f618c879U)), ((u64)(0x4911efc659cf7d4cU)), ((u64)(0x49466bb7f0435c9eU)), ((u64)(0x497c06a5ec5433c6U)), ((u64)(0x49b18427b3b4a05cU)), ((u64)(0x49e5e531a0a1c873U)),
		((u64)(0x4a1b5e7e08ca3a8fU)), ((u64)(0x4a511b0ec57e649aU)), ((u64)(0x4a8561d276ddfdc0U)), ((u64)(0x4ababa4714957d30U)), ((u64)(0x4af0b46c6cdd6e3eU)), ((u64)(0x4b24e1878814c9ceU)), ((u64)(0x4b5a19e96a19fc41U)), ((u64)(0x4b905031e2503da9U)),
		((u64)(0x4bc4643e5ae44d13U)), ((u64)(0x4bf97d4df19d6057U)), ((u64)(0x4c2fdca16e04b86dU)), ((u64)(0x4c63e9e4e4c2f344U)), ((u64)(0x4c98e45e1df3b015U)), ((u64)(0x4ccf1d75a5709c1bU)), ((u64)(0x4d03726987666191U)), ((u64)(0x4d384f03e93ff9f5U)),
		((u64)(0x4d6e62c4e38ff872U)), ((u64)(0x4da2fdbb0e39fb47U)), ((u64)(0x4dd7bd29d1c87a19U)), ((u64)(0x4e0dac74463a989fU)), ((u64)(0x4e428bc8abe49f64U)), ((u64)(0x4e772ebad6ddc73dU)), ((u64)(0x4eacfa698c95390cU)), ((u64)(0x4ee21c81f7dd43a7U)),
		((u64)(0x4f16a3a275d49491U)), ((u64)(0x4f4c4c8b1349b9b5U)), ((u64)(0x4f81afd6ec0e1411U)), ((u64)(0x4fb61bcca7119916U)), ((u64)(0x4feba2bfd0d5ff5bU)), ((u64)(0x502145b7e285bf99U)), ((u64)(0x50559725db272f7fU)), ((u64)(0x508afcef51f0fb5fU)),
		((u64)(0x50c0de1593369d1bU)), ((u64)(0x50f5159af8044462U)), ((u64)(0x512a5b01b605557bU)), ((u64)(0x516078e111c3556dU)), ((u64)(0x5194971956342ac8U)), ((u64)(0x51c9bcdfabc1357aU)), ((u64)(0x5200160bcb58c16cU)), ((u64)(0x52341b8ebe2ef1c7U)),
		((u64)(0x526922726dbaae39U)), ((u64)(0x529f6b0f092959c7U)), ((u64)(0x52d3a2e965b9d81dU)), ((u64)(0x53088ba3bf284e24U)), ((u64)(0x533eae8caef261adU)), ((u64)(0x53732d17ed577d0cU)), ((u64)(0x53a7f85de8ad5c4fU)), ((u64)(0x53ddf67562d8b363U)),
		((u64)(0x5412ba095dc7701eU)), ((u64)(0x5447688bb5394c25U)), ((u64)(0x547d42aea2879f2eU)), ((u64)(0x54b249ad2594c37dU)), ((u64)(0x54e6dc186ef9f45cU)), ((u64)(0x551c931e8ab87173U)), ((u64)(0x5551dbf316b346e8U)), ((u64)(0x558652efdc6018a2U)),
		((u64)(0x55bbe7abd3781ecaU)), ((u64)(0x55f170cb642b133fU)), ((u64)(0x5625ccfe3d35d80eU)), ((u64)(0x565b403dcc834e12U)), ((u64)(0x569108269fd210cbU)), ((u64)(0x56c54a3047c694feU)), ((u64)(0x56fa9cbc59b83a3dU)), ((u64)(0x5730a1f5b8132466U)),
		((u64)(0x5764ca732617ed80U)), ((u64)(0x5799fd0fef9de8e0U)), ((u64)(0x57d03e29f5c2b18cU)), ((u64)(0x58044db473335defU)), ((u64)(0x583961219000356bU)), ((u64)(0x586fb969f40042c5U)), ((u64)(0x58a3d3e2388029bbU)), ((u64)(0x58d8c8dac6a0342aU)),
		((u64)(0x590efb1178484135U)), ((u64)(0x59435ceaeb2d28c1U)), ((u64)(0x59783425a5f872f1U)), ((u64)(0x59ae412f0f768fadU)), ((u64)(0x59e2e8bd69aa19ccU)), ((u64)(0x5a17a2ecc414a03fU)), ((u64)(0x5a4d8ba7f519c84fU)), ((u64)(0x5a827748f9301d32U)),
		((u64)(0x5ab7151b377c247eU)), ((u64)(0x5aecda62055b2d9eU)), ((u64)(0x5b22087d4358fc82U)), ((u64)(0x5b568a9c942f3ba3U)), ((u64)(0x5b8c2d43b93b0a8cU)), ((u64)(0x5bc19c4a53c4e697U)), ((u64)(0x5bf6035ce8b6203dU)), ((u64)(0x5c2b843422e3a84dU)),
		((u64)(0x5c6132a095ce4930U)), ((u64)(0x5c957f48bb41db7cU)), ((u64)(0x5ccadf1aea12525bU)), ((u64)(0x5d00cb70d24b7379U)), ((u64)(0x5d34fe4d06de5057U)), ((u64)(0x5d6a3de04895e46dU)), ((u64)(0x5da066ac2d5daec4U)), ((u64)(0x5dd4805738b51a75U)),
		((u64)(0x5e09a06d06e26112U)), ((u64)(0x5e400444244d7cabU)), ((u64)(0x5e7405552d60dbd6U)), ((u64)(0x5ea906aa78b912ccU)), ((u64)(0x5edf485516e7577fU)), ((u64)(0x5f138d352e5096afU)), ((u64)(0x5f48708279e4bc5bU)), ((u64)(0x5f7e8ca3185deb72U)),
		((u64)(0x5fb317e5ef3ab327U)), ((u64)(0x5fe7dddf6b095ff1U)), ((u64)(0x601dd55745cbb7edU)), ((u64)(0x6052a5568b9f52f4U)), ((u64)(0x60874eac2e8727b1U)), ((u64)(0x60bd22573a28f19dU)), ((u64)(0x60f2357684599702U)), ((u64)(0x6126c2d4256ffcc3U)),
		((u64)(0x615c73892ecbfbf4U)), ((u64)(0x6191c835bd3f7d78U)), ((u64)(0x61c63a432c8f5cd6U)), ((u64)(0x61fbc8d3f7b3340cU)), ((u64)(0x62315d847ad00087U)), ((u64)(0x6265b4e5998400a9U)), ((u64)(0x629b221effe500d4U)), ((u64)(0x62d0f5535fef2084U)),
		((u64)(0x630532a837eae8a5U)), ((u64)(0x633a7f5245e5a2cfU)), ((u64)(0x63708f936baf85c1U)), ((u64)(0x63a4b378469b6732U)), ((u64)(0x63d9e056584240feU)), ((u64)(0x64102c35f729689fU)), ((u64)(0x6444374374f3c2c6U)), ((u64)(0x647945145230b378U)),
		((u64)(0x64af965966bce056U)), ((u64)(0x64e3bdf7e0360c36U)), ((u64)(0x6518ad75d8438f43U)), ((u64)(0x654ed8d34e547314U)), ((u64)(0x6583478410f4c7ecU)), ((u64)(0x65b819651531f9e8U)), ((u64)(0x65ee1fbe5a7e7861U)), ((u64)(0x6622d3d6f88f0b3dU)),
		((u64)(0x665788ccb6b2ce0cU)), ((u64)(0x668d6affe45f818fU)), ((u64)(0x66c262dfeebbb0f9U)), ((u64)(0x66f6fb97ea6a9d38U)), ((u64)(0x672cba7de5054486U)), ((u64)(0x6761f48eaf234ad4U)), ((u64)(0x679671b25aec1d89U)), ((u64)(0x67cc0e1ef1a724ebU)),
		((u64)(0x680188d357087713U)), ((u64)(0x6835eb082cca94d7U)), ((u64)(0x686b65ca37fd3a0dU)), ((u64)(0x68a11f9e62fe4448U)), ((u64)(0x68d56785fbbdd55aU)), ((u64)(0x690ac1677aad4ab1U)), ((u64)(0x6940b8e0acac4eafU)), ((u64)(0x6974e718d7d7625aU)),
		((u64)(0x69aa20df0dcd3af1U)), ((u64)(0x69e0548b68a044d6U)), ((u64)(0x6a1469ae42c8560cU)), ((u64)(0x6a498419d37a6b8fU)), ((u64)(0x6a7fe52048590673U)), ((u64)(0x6ab3ef342d37a408U)), ((u64)(0x6ae8eb0138858d0aU)), ((u64)(0x6b1f25c186a6f04cU)),
		((u64)(0x6b537798f4285630U)), ((u64)(0x6b88557f31326bbbU)), ((u64)(0x6bbe6adefd7f06aaU)), ((u64)(0x6bf302cb5e6f642aU)), ((u64)(0x6c27c37e360b3d35U)), ((u64)(0x6c5db45dc38e0c82U)), ((u64)(0x6c9290ba9a38c7d1U)), ((u64)(0x6cc734e940c6f9c6U)),
		((u64)(0x6cfd022390f8b837U)), ((u64)(0x6d3221563a9b7323U)), ((u64)(0x6d66a9abc9424febU)), ((u64)(0x6d9c5416bb92e3e6U)), ((u64)(0x6dd1b48e353bce70U)), ((u64)(0x6e0621b1c28ac20cU)), ((u64)(0x6e3baa1e332d728fU)), ((u64)(0x6e714a52dffc6799U)),
		((u64)(0x6ea59ce797fb817fU)), ((u64)(0x6edb04217dfa61dfU)), ((u64)(0x6f10e294eebc7d2cU)), ((u64)(0x6f451b3a2a6b9c76U)), ((u64)(0x6f7a6208b5068394U)), ((u64)(0x6fb07d457124123dU)), ((u64)(0x6fe49c96cd6d16ccU)), ((u64)(0x7019c3bc80c85c7fU)),
		((u64)(0x70501a55d07d39cfU)), ((u64)(0x708420eb449c8843U)), ((u64)(0x70b9292615c3aa54U)), ((u64)(0x70ef736f9b3494e9U)), ((u64)(0x7123a825c100dd11U)), ((u64)(0x7158922f31411456U)), ((u64)(0x718eb6bafd91596bU)), ((u64)(0x71c33234de7ad7e3U)),
		((u64)(0x71f7fec216198ddcU)), ((u64)(0x722dfe729b9ff153U)), ((u64)(0x7262bf07a143f6d4U)), ((u64)(0x72976ec98994f489U)), ((u64)(0x72cd4a7bebfa31abU)), ((u64)(0x73024e8d737c5f0bU)), ((u64)(0x7336e230d05b76cdU)), ((u64)(0x736c9abd04725481U)),
		((u64)(0x73a1e0b622c774d0U)), ((u64)(0x73d658e3ab795204U)), ((u64)(0x740bef1c9657a686U)), ((u64)(0x74417571ddf6c814U)), ((u64)(0x7475d2ce55747a18U)), ((u64)(0x74ab4781ead1989eU)), ((u64)(0x74e10cb132c2ff63U)), ((u64)(0x75154fdd7f73bf3cU)),
		((u64)(0x754aa3d4df50af0bU)), ((u64)(0x7580a6650b926d67U)), ((u64)(0x75b4cffe4e7708c0U)), ((u64)(0x75ea03fde214caf1U)), ((u64)(0x7620427ead4cfed6U)), ((u64)(0x7654531e58a03e8cU)), ((u64)(0x768967e5eec84e2fU)), ((u64)(0x76bfc1df6a7a61bbU)),
		((u64)(0x76f3d92ba28c7d15U)), ((u64)(0x7728cf768b2f9c5aU)), ((u64)(0x775f03542dfb8370U)), ((u64)(0x779362149cbd3226U)), ((u64)(0x77c83a99c3ec7eb0U)), ((u64)(0x77fe494034e79e5cU)), ((u64)(0x7832edc82110c2f9U)), ((u64)(0x7867a93a2954f3b8U)),
		((u64)(0x789d9388b3aa30a5U)), ((u64)(0x78d27c35704a5e67U)), ((u64)(0x79071b42cc5cf601U)), ((u64)(0x793ce2137f743382U)), ((u64)(0x79720d4c2fa8a031U)), ((u64)(0x79a6909f3b92c83dU)), ((u64)(0x79dc34c70a777a4dU)), ((u64)(0x7a11a0fc668aac70U)),
		((u64)(0x7a46093b802d578cU)), ((u64)(0x7a7b8b8a6038ad6fU)), ((u64)(0x7ab137367c236c65U)), ((u64)(0x7ae585041b2c477fU)), ((u64)(0x7b1ae64521f7595eU)), ((u64)(0x7b50cfeb353a97dbU)), ((u64)(0x7b8503e602893dd2U)), ((u64)(0x7bba44df832b8d46U)),
		((u64)(0x7bf06b0bb1fb384cU)), ((u64)(0x7c2485ce9e7a065fU)), ((u64)(0x7c59a742461887f6U)), ((u64)(0x7c9008896bcf54faU)), ((u64)(0x7cc40aabc6c32a38U)), ((u64)(0x7cf90d56b873f4c7U)), ((u64)(0x7d2f50ac6690f1f8U)), ((u64)(0x7d63926bc01a973bU)),
		((u64)(0x7d987706b0213d0aU)), ((u64)(0x7dce94c85c298c4cU)), ((u64)(0x7e031cfd3999f7b0U)), ((u64)(0x7e37e43c8800759cU)), ((u64)(0x7e6ddd4baa009303U)), ((u64)(0x7ea2aa4f4a405be2U)), ((u64)(0x7ed754e31cd072daU)), ((u64)(0x7f0d2a1be4048f90U)),
		((u64)(0x7f423a516e82d9baU)), ((u64)(0x7f76c8e5ca239029U)), ((u64)(0x7fac7b1f3cac7433U)), ((u64)(0x7fe1ccf385ebc8a0U))}));
	_const_strconv__neg_exp = new_array_from_c_array(324, 324, sizeof(u64), _MOV((u64[324]){
		((u64)(0x3ff0000000000000U)), ((u64)(0x3fb999999999999aU)), ((u64)(0x3f847ae147ae147bU)), ((u64)(0x3f50624dd2f1a9fcU)), ((u64)(0x3f1a36e2eb1c432dU)), ((u64)(0x3ee4f8b588e368f1U)), ((u64)(0x3eb0c6f7a0b5ed8dU)), ((u64)(0x3e7ad7f29abcaf48U)), ((u64)(0x3e45798ee2308c3aU)),
		((u64)(0x3e112e0be826d695U)), ((u64)(0x3ddb7cdfd9d7bdbbU)), ((u64)(0x3da5fd7fe1796495U)), ((u64)(0x3d719799812dea11U)), ((u64)(0x3d3c25c268497682U)), ((u64)(0x3d06849b86a12b9bU)), ((u64)(0x3cd203af9ee75616U)), ((u64)(0x3c9cd2b297d889bcU)),
		((u64)(0x3c670ef54646d497U)), ((u64)(0x3c32725dd1d243acU)), ((u64)(0x3bfd83c94fb6d2acU)), ((u64)(0x3bc79ca10c924223U)), ((u64)(0x3b92e3b40a0e9b4fU)), ((u64)(0x3b5e392010175ee6U)), ((u64)(0x3b282db34012b251U)), ((u64)(0x3af357c299a88ea7U)),
		((u64)(0x3abef2d0f5da7dd9U)), ((u64)(0x3a88c240c4aecb14U)), ((u64)(0x3a53ce9a36f23c10U)), ((u64)(0x3a1fb0f6be506019U)), ((u64)(0x39e95a5efea6b347U)), ((u64)(0x39b4484bfeebc2a0U)), ((u64)(0x398039d665896880U)), ((u64)(0x3949f623d5a8a733U)),
		((u64)(0x3914c4e977ba1f5cU)), ((u64)(0x38e09d8792fb4c49U)), ((u64)(0x38aa95a5b7f87a0fU)), ((u64)(0x38754484932d2e72U)), ((u64)(0x3841039d428a8b8fU)), ((u64)(0x380b38fb9daa78e4U)), ((u64)(0x37d5c72fb1552d83U)), ((u64)(0x37a16c262777579cU)),
		((u64)(0x376be03d0bf225c7U)), ((u64)(0x37364cfda3281e39U)), ((u64)(0x3701d7314f534b61U)), ((u64)(0x36cc8b8218854567U)), ((u64)(0x3696d601ad376ab9U)), ((u64)(0x366244ce242c5561U)), ((u64)(0x362d3ae36d13bbceU)), ((u64)(0x35f7624f8a762fd8U)),
		((u64)(0x35c2b50c6ec4f313U)), ((u64)(0x358dee7a4ad4b81fU)), ((u64)(0x3557f1fb6f10934cU)), ((u64)(0x352327fc58da0f70U)), ((u64)(0x34eea6608e29b24dU)), ((u64)(0x34b8851a0b548ea4U)), ((u64)(0x34839dae6f76d883U)), ((u64)(0x344f62b0b257c0d2U)),
		((u64)(0x34191bc08eac9a41U)), ((u64)(0x33e41633a556e1ceU)), ((u64)(0x33b011c2eaabe7d8U)), ((u64)(0x3379b604aaaca626U)), ((u64)(0x3344919d5556eb52U)), ((u64)(0x3310747ddddf22a8U)), ((u64)(0x32da53fc9631d10dU)), ((u64)(0x32a50ffd44f4a73dU)),
		((u64)(0x3270d9976a5d5297U)), ((u64)(0x323af5bf109550f2U)), ((u64)(0x32059165a6ddda5bU)), ((u64)(0x31d1411e1f17e1e3U)), ((u64)(0x319b9b6364f30304U)), ((u64)(0x316615e91d8f359dU)), ((u64)(0x3131ab20e472914aU)), ((u64)(0x30fc45016d841baaU)),
		((u64)(0x30c69d9abe034955U)), ((u64)(0x309217aefe690777U)), ((u64)(0x305cf2b1970e7258U)), ((u64)(0x3027288e1271f513U)), ((u64)(0x2ff286d80ec190dcU)), ((u64)(0x2fbda48ce468e7c7U)), ((u64)(0x2f87b6d71d20b96cU)), ((u64)(0x2f52f8ac174d6123U)),
		((u64)(0x2f1e5aacf2156838U)), ((u64)(0x2ee8488a5b445360U)), ((u64)(0x2eb36d3b7c36a91aU)), ((u64)(0x2e7f152bf9f10e90U)), ((u64)(0x2e48ddbcc7f40ba6U)), ((u64)(0x2e13e497065cd61fU)), ((u64)(0x2ddfd424d6faf031U)), ((u64)(0x2da97683df2f268dU)),
		((u64)(0x2d745ecfe5bf520bU)), ((u64)(0x2d404bd984990e6fU)), ((u64)(0x2d0a12f5a0f4e3e5U)), ((u64)(0x2cd4dbf7b3f71cb7U)), ((u64)(0x2ca0aff95cc5b092U)), ((u64)(0x2c6ab328946f80eaU)), ((u64)(0x2c355c2076bf9a55U)), ((u64)(0x2c0116805effaeaaU)),
		((u64)(0x2bcb5733cb32b111U)), ((u64)(0x2b95df5ca28ef40dU)), ((u64)(0x2b617f7d4ed8c33eU)), ((u64)(0x2b2bff2ee48e0530U)), ((u64)(0x2af665bf1d3e6a8dU)), ((u64)(0x2ac1eaff4a98553dU)), ((u64)(0x2a8cab3210f3bb95U)), ((u64)(0x2a56ef5b40c2fc77U)),
		((u64)(0x2a225915cd68c9f9U)), ((u64)(0x29ed5b561574765bU)), ((u64)(0x29b77c44ddf6c516U)), ((u64)(0x2982c9d0b1923745U)), ((u64)(0x294e0fb44f50586eU)), ((u64)(0x29180c903f7379f2U)), ((u64)(0x28e33d4032c2c7f5U)), ((u64)(0x28aec866b79e0cbaU)),
		((u64)(0x2878a0522c7e7095U)), ((u64)(0x2843b374f06526deU)), ((u64)(0x280f8587e7083e30U)), ((u64)(0x27d9379fec069826U)), ((u64)(0x27a42c7ff0054685U)), ((u64)(0x277023998cd10537U)), ((u64)(0x2739d28f47b4d525U)), ((u64)(0x2704a8729fc3ddb7U)),
		((u64)(0x26d086c219697e2cU)), ((u64)(0x269a71368f0f3047U)), ((u64)(0x2665275ed8d8f36cU)), ((u64)(0x2630ec4be0ad8f89U)), ((u64)(0x25fb13ac9aaf4c0fU)), ((u64)(0x25c5a956e225d672U)), ((u64)(0x2591544581b7dec2U)), ((u64)(0x255bba08cf8c979dU)),
		((u64)(0x25262e6d72d6dfb0U)), ((u64)(0x24f1bebdf578b2f4U)), ((u64)(0x24bc6463225ab7ecU)), ((u64)(0x2486b6b5b5155ff0U)), ((u64)(0x24522bc490dde65aU)), ((u64)(0x241d12d41afca3c3U)), ((u64)(0x23e7424348ca1c9cU)), ((u64)(0x23b29b69070816e3U)),
		((u64)(0x237dc574d80cf16bU)), ((u64)(0x2347d12a4670c123U)), ((u64)(0x23130dbb6b8d674fU)), ((u64)(0x22de7c5f127bd87eU)), ((u64)(0x22a8637f41fcad32U)), ((u64)(0x227382cc34ca2428U)), ((u64)(0x223f37ad21436d0cU)), ((u64)(0x2208f9574dcf8a70U)),
		((u64)(0x21d3faac3e3fa1f3U)), ((u64)(0x219ff779fd329cb9U)), ((u64)(0x216992c7fdc216faU)), ((u64)(0x2134756ccb01abfbU)), ((u64)(0x21005df0a267bcc9U)), ((u64)(0x20ca2fe76a3f9475U)), ((u64)(0x2094f31f8832dd2aU)), ((u64)(0x2060c27fa028b0efU)),
		((u64)(0x202ad0cc33744e4bU)), ((u64)(0x1ff573d68f903ea2U)), ((u64)(0x1fc1297872d9cbb5U)), ((u64)(0x1f8b758d848fac55U)), ((u64)(0x1f55f7a46a0c89ddU)), ((u64)(0x1f2192e9ee706e4bU)), ((u64)(0x1eec1e43171a4a11U)), ((u64)(0x1eb67e9c127b6e74U)),
		((u64)(0x1e81fee341fc585dU)), ((u64)(0x1e4ccb0536608d61U)), ((u64)(0x1e1708d0f84d3de7U)), ((u64)(0x1de26d73f9d764b9U)), ((u64)(0x1dad7becc2f23ac2U)), ((u64)(0x1d779657025b6235U)), ((u64)(0x1d42deac01e2b4f7U)), ((u64)(0x1d0e3113363787f2U)),
		((u64)(0x1cd8274291c6065bU)), ((u64)(0x1ca3529ba7d19eafU)), ((u64)(0x1c6eea92a61c3118U)), ((u64)(0x1c38bba884e35a7aU)), ((u64)(0x1c03c9539d82aec8U)), ((u64)(0x1bcfa885c8d117a6U)), ((u64)(0x1b99539e3a40dfb8U)), ((u64)(0x1b6442e4fb671960U)),
		((u64)(0x1b303583fc527ab3U)), ((u64)(0x1af9ef3993b72ab8U)), ((u64)(0x1ac4bf6142f8eefaU)), ((u64)(0x1a90991a9bfa58c8U)), ((u64)(0x1a5a8e90f9908e0dU)), ((u64)(0x1a253eda614071a4U)), ((u64)(0x19f0ff151a99f483U)), ((u64)(0x19bb31bb5dc320d2U)),
		((u64)(0x1985c162b168e70eU)), ((u64)(0x1951678227871f3eU)), ((u64)(0x191bd8d03f3e9864U)), ((u64)(0x18e6470cff6546b6U)), ((u64)(0x18b1d270cc51055fU)), ((u64)(0x187c83e7ad4e6efeU)), ((u64)(0x1846cfec8aa52598U)), ((u64)(0x18123ff06eea847aU)),
		((u64)(0x17dd331a4b10d3f6U)), ((u64)(0x17a75c1508da432bU)), ((u64)(0x1772b010d3e1cf56U)), ((u64)(0x173de6815302e556U)), ((u64)(0x1707eb9aa8cf1ddeU)), ((u64)(0x16d322e220a5b17eU)), ((u64)(0x169e9e369aa2b597U)), ((u64)(0x16687e92154ef7acU)),
		((u64)(0x16339874ddd8c623U)), ((u64)(0x15ff5a549627a36cU)), ((u64)(0x15c91510781fb5f0U)), ((u64)(0x159410d9f9b2f7f3U)), ((u64)(0x15600d7b2e28c65cU)), ((u64)(0x1529af2b7d0e0a2dU)), ((u64)(0x14f48c22ca71a1bdU)), ((u64)(0x14c0701bd527b498U)),
		((u64)(0x148a4cf9550c5426U)), ((u64)(0x14550a6110d6a9b8U)), ((u64)(0x1420d51a73deee2dU)), ((u64)(0x13eaee90b964b047U)), ((u64)(0x13b58ba6fab6f36cU)), ((u64)(0x13813c85955f2923U)), ((u64)(0x134b9408eefea839U)), ((u64)(0x1316100725988694U)),
		((u64)(0x12e1a66c1e139eddU)), ((u64)(0x12ac3d79c9b8fe2eU)), ((u64)(0x12769794a160cb58U)), ((u64)(0x124212dd4de70913U)), ((u64)(0x120ceafbafd80e85U)), ((u64)(0x11d72262f3133ed1U)), ((u64)(0x11a281e8c275cbdaU)), ((u64)(0x116d9ca79d89462aU)),
		((u64)(0x1137b08617a104eeU)), ((u64)(0x1102f39e794d9d8bU)), ((u64)(0x10ce5297287c2f45U)), ((u64)(0x1098421286c9bf6bU)), ((u64)(0x1063680ed23aff89U)), ((u64)(0x102f0ce4839198dbU)), ((u64)(0x0ff8d71d360e13e2U)), ((u64)(0x0fc3df4a91a4dcb5U)),
		((u64)(0x0f8fcbaa82a16121U)), ((u64)(0x0f596fbb9bb44db4U)), ((u64)(0x0f245962e2f6a490U)), ((u64)(0x0ef047824f2bb6daU)), ((u64)(0x0eba0c03b1df8af6U)), ((u64)(0x0e84d6695b193bf8U)), ((u64)(0x0e50ab877c142ffaU)), ((u64)(0x0e1aac0bf9b9e65cU)),
		((u64)(0x0de5566ffafb1eb0U)), ((u64)(0x0db111f32f2f4bc0U)), ((u64)(0x0d7b4feb7eb212cdU)), ((u64)(0x0d45d98932280f0aU)), ((u64)(0x0d117ad428200c08U)), ((u64)(0x0cdbf7b9d9cce00dU)), ((u64)(0x0ca65fc7e170b33eU)), ((u64)(0x0c71e6398126f5cbU)),
		((u64)(0x0c3ca38f350b22dfU)), ((u64)(0x0c06e93f5da2824cU)), ((u64)(0x0bd25432b14ecea3U)), ((u64)(0x0b9d53844ee47dd1U)), ((u64)(0x0b677603725064a8U)), ((u64)(0x0b32c4cf8ea6b6ecU)), ((u64)(0x0afe07b27dd78b14U)), ((u64)(0x0ac8062864ac6f43U)),
		((u64)(0x0a9338205089f29cU)), ((u64)(0x0a5ec033b40fea93U)), ((u64)(0x0a2899c2f6732210U)), ((u64)(0x09f3ae3591f5b4d9U)), ((u64)(0x09bf7d228322baf5U)), ((u64)(0x098930e868e89591U)), ((u64)(0x0954272053ed4474U)), ((u64)(0x09201f4d0ff10390U)),
		((u64)(0x08e9cbae7fe805b3U)), ((u64)(0x08b4a2f1ffecd15cU)), ((u64)(0x0880825b3323dab0U)), ((u64)(0x084a6a2b85062ab3U)), ((u64)(0x081521bc6a6b555cU)), ((u64)(0x07e0e7c9eebc444aU)), ((u64)(0x07ab0c764ac6d3a9U)), ((u64)(0x0775a391d56bdc87U)),
		((u64)(0x07414fa7ddefe3a0U)), ((u64)(0x070bb2a62fe638ffU)), ((u64)(0x06d62884f31e93ffU)), ((u64)(0x06a1ba03f5b21000U)), ((u64)(0x066c5cd322b67fffU)), ((u64)(0x0636b0a8e891ffffU)), ((u64)(0x060226ed86db3333U)), ((u64)(0x05cd0b15a491eb84U)),
		((u64)(0x05973c115074bc6aU)), ((u64)(0x05629674405d6388U)), ((u64)(0x052dbd86cd6238d9U)), ((u64)(0x04f7cad23de82d7bU)), ((u64)(0x04c308a831868ac9U)), ((u64)(0x048e74404f3daadbU)), ((u64)(0x04585d003f6488afU)), ((u64)(0x04237d99cc506d59U)),
		((u64)(0x03ef2f5c7a1a488eU)), ((u64)(0x03b8f2b061aea072U)), ((u64)(0x0383f559e7bee6c1U)), ((u64)(0x034feef63f97d79cU)), ((u64)(0x03198bf832dfdfb0U)), ((u64)(0x02e46ff9c24cb2f3U)), ((u64)(0x02b059949b708f29U)), ((u64)(0x027a28edc580e50eU)),
		((u64)(0x0244ed8b04671da5U)), ((u64)(0x0210be08d0527e1dU)), ((u64)(0x01dac9a7b3b7302fU)), ((u64)(0x01a56e1fc2f8f359U)), ((u64)(0x017124e63593f5e1U)), ((u64)(0x013b6e3d22865634U)), ((u64)(0x0105f1ca820511c3U)), ((u64)(0x00d18e3b9b374169U)),
		((u64)(0x009c16c5c5253575U)), ((u64)(0x0066789e3750f791U)), ((u64)(0x0031fa182c40c60dU)), ((u64)(0x000730d67819e8d2U)), ((u64)(0x0000b8157268fdafU)), ((u64)(0x000012688b70e62bU)), ((u64)(0x000001d74124e3d1U)), ((u64)(0x0000002f201d49fbU)),
		((u64)(0x00000004b6695433U)), ((u64)(0x0000000078a42205U)), ((u64)(0x000000000c1069cdU)), ((u64)(0x000000000134d761U)), ((u64)(0x00000000001ee257U)), ((u64)(0x00000000000316a2U)), ((u64)(0x0000000000004f10U)), ((u64)(0x00000000000007e8U)),
		((u64)(0x00000000000000caU)), ((u64)(0x0000000000000014U)), ((u64)(0x0000000000000002U))}));
	_const_strconv__ten_pow_table_32 = new_array_from_c_array(12, 12, sizeof(u32), _MOV((u32[12]){
		((u32)(1U)), ((u32)(10U)), ((u32)(100U)), ((u32)(1000U)), ((u32)(10000U)), ((u32)(100000U)), ((u32)(1000000U)), ((u32)(10000000U)), ((u32)(100000000U)),
		((u32)(1000000000U)), ((u32)(10000000000U)), ((u32)(100000000000U))}));
	_const_strconv__ten_pow_table_64 = new_array_from_c_array(20, 20, sizeof(u64), _MOV((u64[20]){
		((u64)(1U)), ((u64)(10U)), ((u64)(100U)), ((u64)(1000U)), ((u64)(10000U)), ((u64)(100000U)), ((u64)(1000000U)), ((u64)(10000000U)), ((u64)(100000000U)),
		((u64)(1000000000U)), ((u64)(10000000000U)), ((u64)(100000000000U)), ((u64)(1000000000000U)), ((u64)(10000000000000U)), ((u64)(100000000000000U)), ((u64)(1000000000000000U)), ((u64)(10000000000000000U)),
		((u64)(100000000000000000U)), ((u64)(1000000000000000000U)), ((u64)(10000000000000000000U))}));
	_const_strconv__dec_round = new_array_from_c_array(20, 20, sizeof(f64), _MOV((f64[20]){
		((f64)(0.5)), 0.05, 0.005, 0.0005, 0.00005, 0.000005, 0.0000005, 0.00000005, 0.000000005,
		0.0000000005, 0.00000000005, 0.000000000005, 0.0000000000005, 0.00000000000005, 0.000000000000005, 0.0000000000000005, 0.00000000000000005,
		0.000000000000000005, 0.0000000000000000005, 0.00000000000000000005}));
	_const_strconv__powers_of_10 = new_array_from_c_array(18, 18, sizeof(u64), _MOV((u64[18]){
		((u64)(1e0)), ((u64)(1e1)), ((u64)(1e2)), ((u64)(1e3)), ((u64)(1e4)), ((u64)(1e5)), ((u64)(1e6)), ((u64)(1e7)), ((u64)(1e8)),
		((u64)(1e9)), ((u64)(1e10)), ((u64)(1e11)), ((u64)(1e12)), ((u64)(1e13)), ((u64)(1e14)), ((u64)(1e15)), ((u64)(1e16)),
		((u64)(1e17))}));
	_const_strconv__pow5_split_32 = new_array_from_c_array(47, 47, sizeof(u64), _MOV((u64[47]){
		((u64)(1152921504606846976U)), ((u64)(1441151880758558720U)), ((u64)(1801439850948198400U)), ((u64)(2251799813685248000U)), ((u64)(1407374883553280000U)), ((u64)(1759218604441600000U)), ((u64)(2199023255552000000U)), ((u64)(1374389534720000000U)), ((u64)(1717986918400000000U)),
		((u64)(2147483648000000000U)), ((u64)(1342177280000000000U)), ((u64)(1677721600000000000U)), ((u64)(2097152000000000000U)), ((u64)(1310720000000000000U)), ((u64)(1638400000000000000U)), ((u64)(2048000000000000000U)), ((u64)(1280000000000000000U)),
		((u64)(1600000000000000000U)), ((u64)(2000000000000000000U)), ((u64)(1250000000000000000U)), ((u64)(1562500000000000000U)), ((u64)(1953125000000000000U)), ((u64)(1220703125000000000U)), ((u64)(1525878906250000000U)), ((u64)(1907348632812500000U)),
		((u64)(1192092895507812500U)), ((u64)(1490116119384765625U)), ((u64)(1862645149230957031U)), ((u64)(1164153218269348144U)), ((u64)(1455191522836685180U)), ((u64)(1818989403545856475U)), ((u64)(2273736754432320594U)), ((u64)(1421085471520200371U)),
		((u64)(1776356839400250464U)), ((u64)(2220446049250313080U)), ((u64)(1387778780781445675U)), ((u64)(1734723475976807094U)), ((u64)(2168404344971008868U)), ((u64)(1355252715606880542U)), ((u64)(1694065894508600678U)), ((u64)(2117582368135750847U)),
		((u64)(1323488980084844279U)), ((u64)(1654361225106055349U)), ((u64)(2067951531382569187U)), ((u64)(1292469707114105741U)), ((u64)(1615587133892632177U)), ((u64)(2019483917365790221U))}));
	_const_strconv__pow5_inv_split_32 = new_array_from_c_array(31, 31, sizeof(u64), _MOV((u64[31]){
		((u64)(576460752303423489U)), ((u64)(461168601842738791U)), ((u64)(368934881474191033U)), ((u64)(295147905179352826U)), ((u64)(472236648286964522U)), ((u64)(377789318629571618U)), ((u64)(302231454903657294U)), ((u64)(483570327845851670U)), ((u64)(386856262276681336U)),
		((u64)(309485009821345069U)), ((u64)(495176015714152110U)), ((u64)(396140812571321688U)), ((u64)(316912650057057351U)), ((u64)(507060240091291761U)), ((u64)(405648192073033409U)), ((u64)(324518553658426727U)), ((u64)(519229685853482763U)),
		((u64)(415383748682786211U)), ((u64)(332306998946228969U)), ((u64)(531691198313966350U)), ((u64)(425352958651173080U)), ((u64)(340282366920938464U)), ((u64)(544451787073501542U)), ((u64)(435561429658801234U)), ((u64)(348449143727040987U)),
		((u64)(557518629963265579U)), ((u64)(446014903970612463U)), ((u64)(356811923176489971U)), ((u64)(570899077082383953U)), ((u64)(456719261665907162U)), ((u64)(365375409332725730U))}));
	_const_strconv__pow5_split_64 = new_array_from_c_array(326, 326, sizeof(strconv__Uint128), _MOV((strconv__Uint128[326]){
		(strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0100000000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0140000000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0190000000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01f4000000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0138800000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0186a00000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01e8480000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01312d0000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x017d784000000000U)),},
		(strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01dcd65000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x012a05f200000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0174876e80000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01d1a94a20000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x012309ce54000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x016bcc41e9000000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01c6bf5263400000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x011c37937e080000U)),},
		(strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x016345785d8a0000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01bc16d674ec8000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01158e460913d000U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x015af1d78b58c400U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01b1ae4d6e2ef500U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x010f0cf064dd5920U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x0152d02c7e14af68U)),}, (strconv__Uint128){.lo = ((u64)(0x0000000000000000U)),.hi = ((u64)(0x01a784379d99db42U)),},
		(strconv__Uint128){.lo = ((u64)(0x4000000000000000U)),.hi = ((u64)(0x0108b2a2c2802909U)),}, (strconv__Uint128){.lo = ((u64)(0x9000000000000000U)),.hi = ((u64)(0x014adf4b7320334bU)),}, (strconv__Uint128){.lo = ((u64)(0x7400000000000000U)),.hi = ((u64)(0x019d971e4fe8401eU)),}, (strconv__Uint128){.lo = ((u64)(0x0880000000000000U)),.hi = ((u64)(0x01027e72f1f12813U)),}, (strconv__Uint128){.lo = ((u64)(0xcaa0000000000000U)),.hi = ((u64)(0x01431e0fae6d7217U)),}, (strconv__Uint128){.lo = ((u64)(0xbd48000000000000U)),.hi = ((u64)(0x0193e5939a08ce9dU)),}, (strconv__Uint128){.lo = ((u64)(0x2c9a000000000000U)),.hi = ((u64)(0x01f8def8808b0245U)),}, (strconv__Uint128){.lo = ((u64)(0x3be0400000000000U)),.hi = ((u64)(0x013b8b5b5056e16bU)),},
		(strconv__Uint128){.lo = ((u64)(0x0ad8500000000000U)),.hi = ((u64)(0x018a6e32246c99c6U)),}, (strconv__Uint128){.lo = ((u64)(0x8d8e640000000000U)),.hi = ((u64)(0x01ed09bead87c037U)),}, (strconv__Uint128){.lo = ((u64)(0xb878fe8000000000U)),.hi = ((u64)(0x013426172c74d822U)),}, (strconv__Uint128){.lo = ((u64)(0x66973e2000000000U)),.hi = ((u64)(0x01812f9cf7920e2bU)),}, (strconv__Uint128){.lo = ((u64)(0x403d0da800000000U)),.hi = ((u64)(0x01e17b84357691b6U)),}, (strconv__Uint128){.lo = ((u64)(0xe826288900000000U)),.hi = ((u64)(0x012ced32a16a1b11U)),}, (strconv__Uint128){.lo = ((u64)(0x622fb2ab40000000U)),.hi = ((u64)(0x0178287f49c4a1d6U)),}, (strconv__Uint128){.lo = ((u64)(0xfabb9f5610000000U)),.hi = ((u64)(0x01d6329f1c35ca4bU)),},
		(strconv__Uint128){.lo = ((u64)(0x7cb54395ca000000U)),.hi = ((u64)(0x0125dfa371a19e6fU)),}, (strconv__Uint128){.lo = ((u64)(0x5be2947b3c800000U)),.hi = ((u64)(0x016f578c4e0a060bU)),}, (strconv__Uint128){.lo = ((u64)(0x32db399a0ba00000U)),.hi = ((u64)(0x01cb2d6f618c878eU)),}, (strconv__Uint128){.lo = ((u64)(0xdfc9040047440000U)),.hi = ((u64)(0x011efc659cf7d4b8U)),}, (strconv__Uint128){.lo = ((u64)(0x17bb450059150000U)),.hi = ((u64)(0x0166bb7f0435c9e7U)),}, (strconv__Uint128){.lo = ((u64)(0xddaa16406f5a4000U)),.hi = ((u64)(0x01c06a5ec5433c60U)),}, (strconv__Uint128){.lo = ((u64)(0x8a8a4de845986800U)),.hi = ((u64)(0x0118427b3b4a05bcU)),}, (strconv__Uint128){.lo = ((u64)(0xad2ce16256fe8200U)),.hi = ((u64)(0x015e531a0a1c872bU)),},
		(strconv__Uint128){.lo = ((u64)(0x987819baecbe2280U)),.hi = ((u64)(0x01b5e7e08ca3a8f6U)),}, (strconv__Uint128){.lo = ((u64)(0x1f4b1014d3f6d590U)),.hi = ((u64)(0x0111b0ec57e6499aU)),}, (strconv__Uint128){.lo = ((u64)(0xa71dd41a08f48af4U)),.hi = ((u64)(0x01561d276ddfdc00U)),}, (strconv__Uint128){.lo = ((u64)(0xd0e549208b31adb1U)),.hi = ((u64)(0x01aba4714957d300U)),}, (strconv__Uint128){.lo = ((u64)(0x828f4db456ff0c8eU)),.hi = ((u64)(0x010b46c6cdd6e3e0U)),}, (strconv__Uint128){.lo = ((u64)(0xa33321216cbecfb2U)),.hi = ((u64)(0x014e1878814c9cd8U)),}, (strconv__Uint128){.lo = ((u64)(0xcbffe969c7ee839eU)),.hi = ((u64)(0x01a19e96a19fc40eU)),}, (strconv__Uint128){.lo = ((u64)(0x3f7ff1e21cf51243U)),.hi = ((u64)(0x0105031e2503da89U)),},
		(strconv__Uint128){.lo = ((u64)(0x8f5fee5aa43256d4U)),.hi = ((u64)(0x014643e5ae44d12bU)),}, (strconv__Uint128){.lo = ((u64)(0x7337e9f14d3eec89U)),.hi = ((u64)(0x0197d4df19d60576U)),}, (strconv__Uint128){.lo = ((u64)(0x1005e46da08ea7abU)),.hi = ((u64)(0x01fdca16e04b86d4U)),}, (strconv__Uint128){.lo = ((u64)(0x8a03aec4845928cbU)),.hi = ((u64)(0x013e9e4e4c2f3444U)),}, (strconv__Uint128){.lo = ((u64)(0xac849a75a56f72fdU)),.hi = ((u64)(0x018e45e1df3b0155U)),}, (strconv__Uint128){.lo = ((u64)(0x17a5c1130ecb4fbdU)),.hi = ((u64)(0x01f1d75a5709c1abU)),}, (strconv__Uint128){.lo = ((u64)(0xeec798abe93f11d6U)),.hi = ((u64)(0x013726987666190aU)),}, (strconv__Uint128){.lo = ((u64)(0xaa797ed6e38ed64bU)),.hi = ((u64)(0x0184f03e93ff9f4dU)),},
		(strconv__Uint128){.lo = ((u64)(0x1517de8c9c728bdeU)),.hi = ((u64)(0x01e62c4e38ff8721U)),}, (strconv__Uint128){.lo = ((u64)(0xad2eeb17e1c7976bU)),.hi = ((u64)(0x012fdbb0e39fb474U)),}, (strconv__Uint128){.lo = ((u64)(0xd87aa5ddda397d46U)),.hi = ((u64)(0x017bd29d1c87a191U)),}, (strconv__Uint128){.lo = ((u64)(0x4e994f5550c7dc97U)),.hi = ((u64)(0x01dac74463a989f6U)),}, (strconv__Uint128){.lo = ((u64)(0xf11fd195527ce9deU)),.hi = ((u64)(0x0128bc8abe49f639U)),}, (strconv__Uint128){.lo = ((u64)(0x6d67c5faa71c2456U)),.hi = ((u64)(0x0172ebad6ddc73c8U)),}, (strconv__Uint128){.lo = ((u64)(0x88c1b77950e32d6cU)),.hi = ((u64)(0x01cfa698c95390baU)),}, (strconv__Uint128){.lo = ((u64)(0x957912abd28dfc63U)),.hi = ((u64)(0x0121c81f7dd43a74U)),},
		(strconv__Uint128){.lo = ((u64)(0xbad75756c7317b7cU)),.hi = ((u64)(0x016a3a275d494911U)),}, (strconv__Uint128){.lo = ((u64)(0x298d2d2c78fdda5bU)),.hi = ((u64)(0x01c4c8b1349b9b56U)),}, (strconv__Uint128){.lo = ((u64)(0xd9f83c3bcb9ea879U)),.hi = ((u64)(0x011afd6ec0e14115U)),}, (strconv__Uint128){.lo = ((u64)(0x50764b4abe865297U)),.hi = ((u64)(0x0161bcca7119915bU)),}, (strconv__Uint128){.lo = ((u64)(0x2493de1d6e27e73dU)),.hi = ((u64)(0x01ba2bfd0d5ff5b2U)),}, (strconv__Uint128){.lo = ((u64)(0x56dc6ad264d8f086U)),.hi = ((u64)(0x01145b7e285bf98fU)),}, (strconv__Uint128){.lo = ((u64)(0x2c938586fe0f2ca8U)),.hi = ((u64)(0x0159725db272f7f3U)),}, (strconv__Uint128){.lo = ((u64)(0xf7b866e8bd92f7d2U)),.hi = ((u64)(0x01afcef51f0fb5efU)),},
		(strconv__Uint128){.lo = ((u64)(0xfad34051767bdae3U)),.hi = ((u64)(0x010de1593369d1b5U)),}, (strconv__Uint128){.lo = ((u64)(0x79881065d41ad19cU)),.hi = ((u64)(0x015159af80444623U)),}, (strconv__Uint128){.lo = ((u64)(0x57ea147f49218603U)),.hi = ((u64)(0x01a5b01b605557acU)),}, (strconv__Uint128){.lo = ((u64)(0xb6f24ccf8db4f3c1U)),.hi = ((u64)(0x01078e111c3556cbU)),}, (strconv__Uint128){.lo = ((u64)(0xa4aee003712230b2U)),.hi = ((u64)(0x014971956342ac7eU)),}, (strconv__Uint128){.lo = ((u64)(0x4dda98044d6abcdfU)),.hi = ((u64)(0x019bcdfabc13579eU)),}, (strconv__Uint128){.lo = ((u64)(0xf0a89f02b062b60bU)),.hi = ((u64)(0x010160bcb58c16c2U)),}, (strconv__Uint128){.lo = ((u64)(0xacd2c6c35c7b638eU)),.hi = ((u64)(0x0141b8ebe2ef1c73U)),},
		(strconv__Uint128){.lo = ((u64)(0x98077874339a3c71U)),.hi = ((u64)(0x01922726dbaae390U)),}, (strconv__Uint128){.lo = ((u64)(0xbe0956914080cb8eU)),.hi = ((u64)(0x01f6b0f092959c74U)),}, (strconv__Uint128){.lo = ((u64)(0xf6c5d61ac8507f38U)),.hi = ((u64)(0x013a2e965b9d81c8U)),}, (strconv__Uint128){.lo = ((u64)(0x34774ba17a649f07U)),.hi = ((u64)(0x0188ba3bf284e23bU)),}, (strconv__Uint128){.lo = ((u64)(0x01951e89d8fdc6c8U)),.hi = ((u64)(0x01eae8caef261acaU)),}, (strconv__Uint128){.lo = ((u64)(0x40fd3316279e9c3dU)),.hi = ((u64)(0x0132d17ed577d0beU)),}, (strconv__Uint128){.lo = ((u64)(0xd13c7fdbb186434cU)),.hi = ((u64)(0x017f85de8ad5c4edU)),}, (strconv__Uint128){.lo = ((u64)(0x458b9fd29de7d420U)),.hi = ((u64)(0x01df67562d8b3629U)),},
		(strconv__Uint128){.lo = ((u64)(0xcb7743e3a2b0e494U)),.hi = ((u64)(0x012ba095dc7701d9U)),}, (strconv__Uint128){.lo = ((u64)(0x3e5514dc8b5d1db9U)),.hi = ((u64)(0x017688bb5394c250U)),}, (strconv__Uint128){.lo = ((u64)(0x4dea5a13ae346527U)),.hi = ((u64)(0x01d42aea2879f2e4U)),}, (strconv__Uint128){.lo = ((u64)(0xb0b2784c4ce0bf38U)),.hi = ((u64)(0x01249ad2594c37ceU)),}, (strconv__Uint128){.lo = ((u64)(0x5cdf165f6018ef06U)),.hi = ((u64)(0x016dc186ef9f45c2U)),}, (strconv__Uint128){.lo = ((u64)(0xf416dbf7381f2ac8U)),.hi = ((u64)(0x01c931e8ab871732U)),}, (strconv__Uint128){.lo = ((u64)(0xd88e497a83137abdU)),.hi = ((u64)(0x011dbf316b346e7fU)),}, (strconv__Uint128){.lo = ((u64)(0xceb1dbd923d8596cU)),.hi = ((u64)(0x01652efdc6018a1fU)),},
		(strconv__Uint128){.lo = ((u64)(0xc25e52cf6cce6fc7U)),.hi = ((u64)(0x01be7abd3781eca7U)),}, (strconv__Uint128){.lo = ((u64)(0xd97af3c1a40105dcU)),.hi = ((u64)(0x01170cb642b133e8U)),}, (strconv__Uint128){.lo = ((u64)(0x0fd9b0b20d014754U)),.hi = ((u64)(0x015ccfe3d35d80e3U)),}, (strconv__Uint128){.lo = ((u64)(0xd3d01cde90419929U)),.hi = ((u64)(0x01b403dcc834e11bU)),}, (strconv__Uint128){.lo = ((u64)(0x6462120b1a28ffb9U)),.hi = ((u64)(0x01108269fd210cb1U)),}, (strconv__Uint128){.lo = ((u64)(0xbd7a968de0b33fa8U)),.hi = ((u64)(0x0154a3047c694fddU)),}, (strconv__Uint128){.lo = ((u64)(0x2cd93c3158e00f92U)),.hi = ((u64)(0x01a9cbc59b83a3d5U)),}, (strconv__Uint128){.lo = ((u64)(0x3c07c59ed78c09bbU)),.hi = ((u64)(0x010a1f5b81324665U)),},
		(strconv__Uint128){.lo = ((u64)(0x8b09b7068d6f0c2aU)),.hi = ((u64)(0x014ca732617ed7feU)),}, (strconv__Uint128){.lo = ((u64)(0x2dcc24c830cacf34U)),.hi = ((u64)(0x019fd0fef9de8dfeU)),}, (strconv__Uint128){.lo = ((u64)(0xdc9f96fd1e7ec180U)),.hi = ((u64)(0x0103e29f5c2b18beU)),}, (strconv__Uint128){.lo = ((u64)(0x93c77cbc661e71e1U)),.hi = ((u64)(0x0144db473335deeeU)),}, (strconv__Uint128){.lo = ((u64)(0x38b95beb7fa60e59U)),.hi = ((u64)(0x01961219000356aaU)),}, (strconv__Uint128){.lo = ((u64)(0xc6e7b2e65f8f91efU)),.hi = ((u64)(0x01fb969f40042c54U)),}, (strconv__Uint128){.lo = ((u64)(0xfc50cfcffbb9bb35U)),.hi = ((u64)(0x013d3e2388029bb4U)),}, (strconv__Uint128){.lo = ((u64)(0x3b6503c3faa82a03U)),.hi = ((u64)(0x018c8dac6a0342a2U)),},
		(strconv__Uint128){.lo = ((u64)(0xca3e44b4f9523484U)),.hi = ((u64)(0x01efb1178484134aU)),}, (strconv__Uint128){.lo = ((u64)(0xbe66eaf11bd360d2U)),.hi = ((u64)(0x0135ceaeb2d28c0eU)),}, (strconv__Uint128){.lo = ((u64)(0x6e00a5ad62c83907U)),.hi = ((u64)(0x0183425a5f872f12U)),}, (strconv__Uint128){.lo = ((u64)(0x0980cf18bb7a4749U)),.hi = ((u64)(0x01e412f0f768fad7U)),}, (strconv__Uint128){.lo = ((u64)(0x65f0816f752c6c8dU)),.hi = ((u64)(0x012e8bd69aa19cc6U)),}, (strconv__Uint128){.lo = ((u64)(0xff6ca1cb527787b1U)),.hi = ((u64)(0x017a2ecc414a03f7U)),}, (strconv__Uint128){.lo = ((u64)(0xff47ca3e2715699dU)),.hi = ((u64)(0x01d8ba7f519c84f5U)),}, (strconv__Uint128){.lo = ((u64)(0xbf8cde66d86d6202U)),.hi = ((u64)(0x0127748f9301d319U)),},
		(strconv__Uint128){.lo = ((u64)(0x2f7016008e88ba83U)),.hi = ((u64)(0x017151b377c247e0U)),}, (strconv__Uint128){.lo = ((u64)(0x3b4c1b80b22ae923U)),.hi = ((u64)(0x01cda62055b2d9d8U)),}, (strconv__Uint128){.lo = ((u64)(0x250f91306f5ad1b6U)),.hi = ((u64)(0x012087d4358fc827U)),}, (strconv__Uint128){.lo = ((u64)(0xee53757c8b318623U)),.hi = ((u64)(0x0168a9c942f3ba30U)),}, (strconv__Uint128){.lo = ((u64)(0x29e852dbadfde7acU)),.hi = ((u64)(0x01c2d43b93b0a8bdU)),}, (strconv__Uint128){.lo = ((u64)(0x3a3133c94cbeb0ccU)),.hi = ((u64)(0x0119c4a53c4e6976U)),}, (strconv__Uint128){.lo = ((u64)(0xc8bd80bb9fee5cffU)),.hi = ((u64)(0x016035ce8b6203d3U)),}, (strconv__Uint128){.lo = ((u64)(0xbaece0ea87e9f43eU)),.hi = ((u64)(0x01b843422e3a84c8U)),},
		(strconv__Uint128){.lo = ((u64)(0x74d40c9294f238a7U)),.hi = ((u64)(0x01132a095ce492fdU)),}, (strconv__Uint128){.lo = ((u64)(0xd2090fb73a2ec6d1U)),.hi = ((u64)(0x0157f48bb41db7bcU)),}, (strconv__Uint128){.lo = ((u64)(0x068b53a508ba7885U)),.hi = ((u64)(0x01adf1aea12525acU)),}, (strconv__Uint128){.lo = ((u64)(0x8417144725748b53U)),.hi = ((u64)(0x010cb70d24b7378bU)),}, (strconv__Uint128){.lo = ((u64)(0x651cd958eed1ae28U)),.hi = ((u64)(0x014fe4d06de5056eU)),}, (strconv__Uint128){.lo = ((u64)(0xfe640faf2a8619b2U)),.hi = ((u64)(0x01a3de04895e46c9U)),}, (strconv__Uint128){.lo = ((u64)(0x3efe89cd7a93d00fU)),.hi = ((u64)(0x01066ac2d5daec3eU)),}, (strconv__Uint128){.lo = ((u64)(0xcebe2c40d938c413U)),.hi = ((u64)(0x014805738b51a74dU)),},
		(strconv__Uint128){.lo = ((u64)(0x426db7510f86f518U)),.hi = ((u64)(0x019a06d06e261121U)),}, (strconv__Uint128){.lo = ((u64)(0xc9849292a9b4592fU)),.hi = ((u64)(0x0100444244d7cab4U)),}, (strconv__Uint128){.lo = ((u64)(0xfbe5b73754216f7aU)),.hi = ((u64)(0x01405552d60dbd61U)),}, (strconv__Uint128){.lo = ((u64)(0x7adf25052929cb59U)),.hi = ((u64)(0x01906aa78b912cbaU)),}, (strconv__Uint128){.lo = ((u64)(0x1996ee4673743e2fU)),.hi = ((u64)(0x01f485516e7577e9U)),}, (strconv__Uint128){.lo = ((u64)(0xaffe54ec0828a6ddU)),.hi = ((u64)(0x0138d352e5096af1U)),}, (strconv__Uint128){.lo = ((u64)(0x1bfdea270a32d095U)),.hi = ((u64)(0x018708279e4bc5aeU)),}, (strconv__Uint128){.lo = ((u64)(0xa2fd64b0ccbf84baU)),.hi = ((u64)(0x01e8ca3185deb719U)),},
		(strconv__Uint128){.lo = ((u64)(0x05de5eee7ff7b2f4U)),.hi = ((u64)(0x01317e5ef3ab3270U)),}, (strconv__Uint128){.lo = ((u64)(0x0755f6aa1ff59fb1U)),.hi = ((u64)(0x017dddf6b095ff0cU)),}, (strconv__Uint128){.lo = ((u64)(0x092b7454a7f3079eU)),.hi = ((u64)(0x01dd55745cbb7ecfU)),}, (strconv__Uint128){.lo = ((u64)(0x65bb28b4e8f7e4c3U)),.hi = ((u64)(0x012a5568b9f52f41U)),}, (strconv__Uint128){.lo = ((u64)(0xbf29f2e22335ddf3U)),.hi = ((u64)(0x0174eac2e8727b11U)),}, (strconv__Uint128){.lo = ((u64)(0x2ef46f9aac035570U)),.hi = ((u64)(0x01d22573a28f19d6U)),}, (strconv__Uint128){.lo = ((u64)(0xdd58c5c0ab821566U)),.hi = ((u64)(0x0123576845997025U)),}, (strconv__Uint128){.lo = ((u64)(0x54aef730d6629ac0U)),.hi = ((u64)(0x016c2d4256ffcc2fU)),},
		(strconv__Uint128){.lo = ((u64)(0x29dab4fd0bfb4170U)),.hi = ((u64)(0x01c73892ecbfbf3bU)),}, (strconv__Uint128){.lo = ((u64)(0xfa28b11e277d08e6U)),.hi = ((u64)(0x011c835bd3f7d784U)),}, (strconv__Uint128){.lo = ((u64)(0x38b2dd65b15c4b1fU)),.hi = ((u64)(0x0163a432c8f5cd66U)),}, (strconv__Uint128){.lo = ((u64)(0xc6df94bf1db35de7U)),.hi = ((u64)(0x01bc8d3f7b3340bfU)),}, (strconv__Uint128){.lo = ((u64)(0xdc4bbcf772901ab0U)),.hi = ((u64)(0x0115d847ad000877U)),}, (strconv__Uint128){.lo = ((u64)(0xd35eac354f34215cU)),.hi = ((u64)(0x015b4e5998400a95U)),}, (strconv__Uint128){.lo = ((u64)(0x48365742a30129b4U)),.hi = ((u64)(0x01b221effe500d3bU)),}, (strconv__Uint128){.lo = ((u64)(0x0d21f689a5e0ba10U)),.hi = ((u64)(0x010f5535fef20845U)),},
		(strconv__Uint128){.lo = ((u64)(0x506a742c0f58e894U)),.hi = ((u64)(0x01532a837eae8a56U)),}, (strconv__Uint128){.lo = ((u64)(0xe4851137132f22b9U)),.hi = ((u64)(0x01a7f5245e5a2cebU)),}, (strconv__Uint128){.lo = ((u64)(0x6ed32ac26bfd75b4U)),.hi = ((u64)(0x0108f936baf85c13U)),}, (strconv__Uint128){.lo = ((u64)(0x4a87f57306fcd321U)),.hi = ((u64)(0x014b378469b67318U)),}, (strconv__Uint128){.lo = ((u64)(0x5d29f2cfc8bc07e9U)),.hi = ((u64)(0x019e056584240fdeU)),}, (strconv__Uint128){.lo = ((u64)(0xfa3a37c1dd7584f1U)),.hi = ((u64)(0x0102c35f729689eaU)),}, (strconv__Uint128){.lo = ((u64)(0xb8c8c5b254d2e62eU)),.hi = ((u64)(0x014374374f3c2c65U)),}, (strconv__Uint128){.lo = ((u64)(0x26faf71eea079fb9U)),.hi = ((u64)(0x01945145230b377fU)),},
		(strconv__Uint128){.lo = ((u64)(0xf0b9b4e6a48987a8U)),.hi = ((u64)(0x01f965966bce055eU)),}, (strconv__Uint128){.lo = ((u64)(0x5674111026d5f4c9U)),.hi = ((u64)(0x013bdf7e0360c35bU)),}, (strconv__Uint128){.lo = ((u64)(0x2c111554308b71fbU)),.hi = ((u64)(0x018ad75d8438f432U)),}, (strconv__Uint128){.lo = ((u64)(0xb7155aa93cae4e7aU)),.hi = ((u64)(0x01ed8d34e547313eU)),}, (strconv__Uint128){.lo = ((u64)(0x326d58a9c5ecf10cU)),.hi = ((u64)(0x013478410f4c7ec7U)),}, (strconv__Uint128){.lo = ((u64)(0xff08aed437682d4fU)),.hi = ((u64)(0x01819651531f9e78U)),}, (strconv__Uint128){.lo = ((u64)(0x3ecada89454238a3U)),.hi = ((u64)(0x01e1fbe5a7e78617U)),}, (strconv__Uint128){.lo = ((u64)(0x873ec895cb496366U)),.hi = ((u64)(0x012d3d6f88f0b3ceU)),},
		(strconv__Uint128){.lo = ((u64)(0x290e7abb3e1bbc3fU)),.hi = ((u64)(0x01788ccb6b2ce0c2U)),}, (strconv__Uint128){.lo = ((u64)(0xb352196a0da2ab4fU)),.hi = ((u64)(0x01d6affe45f818f2U)),}, (strconv__Uint128){.lo = ((u64)(0xb0134fe24885ab11U)),.hi = ((u64)(0x01262dfeebbb0f97U)),}, (strconv__Uint128){.lo = ((u64)(0x9c1823dadaa715d6U)),.hi = ((u64)(0x016fb97ea6a9d37dU)),}, (strconv__Uint128){.lo = ((u64)(0x031e2cd19150db4bU)),.hi = ((u64)(0x01cba7de5054485dU)),}, (strconv__Uint128){.lo = ((u64)(0x21f2dc02fad2890fU)),.hi = ((u64)(0x011f48eaf234ad3aU)),}, (strconv__Uint128){.lo = ((u64)(0xaa6f9303b9872b53U)),.hi = ((u64)(0x01671b25aec1d888U)),}, (strconv__Uint128){.lo = ((u64)(0xd50b77c4a7e8f628U)),.hi = ((u64)(0x01c0e1ef1a724eaaU)),},
		(strconv__Uint128){.lo = ((u64)(0xc5272adae8f199d9U)),.hi = ((u64)(0x01188d357087712aU)),}, (strconv__Uint128){.lo = ((u64)(0x7670f591a32e004fU)),.hi = ((u64)(0x015eb082cca94d75U)),}, (strconv__Uint128){.lo = ((u64)(0xd40d32f60bf98063U)),.hi = ((u64)(0x01b65ca37fd3a0d2U)),}, (strconv__Uint128){.lo = ((u64)(0xc4883fd9c77bf03eU)),.hi = ((u64)(0x0111f9e62fe44483U)),}, (strconv__Uint128){.lo = ((u64)(0xb5aa4fd0395aec4dU)),.hi = ((u64)(0x0156785fbbdd55a4U)),}, (strconv__Uint128){.lo = ((u64)(0xe314e3c447b1a760U)),.hi = ((u64)(0x01ac1677aad4ab0dU)),}, (strconv__Uint128){.lo = ((u64)(0xaded0e5aaccf089cU)),.hi = ((u64)(0x010b8e0acac4eae8U)),}, (strconv__Uint128){.lo = ((u64)(0xd96851f15802cac3U)),.hi = ((u64)(0x014e718d7d7625a2U)),},
		(strconv__Uint128){.lo = ((u64)(0x8fc2666dae037d74U)),.hi = ((u64)(0x01a20df0dcd3af0bU)),}, (strconv__Uint128){.lo = ((u64)(0x39d980048cc22e68U)),.hi = ((u64)(0x010548b68a044d67U)),}, (strconv__Uint128){.lo = ((u64)(0x084fe005aff2ba03U)),.hi = ((u64)(0x01469ae42c8560c1U)),}, (strconv__Uint128){.lo = ((u64)(0x4a63d8071bef6883U)),.hi = ((u64)(0x0198419d37a6b8f1U)),}, (strconv__Uint128){.lo = ((u64)(0x9cfcce08e2eb42a4U)),.hi = ((u64)(0x01fe52048590672dU)),}, (strconv__Uint128){.lo = ((u64)(0x821e00c58dd309a7U)),.hi = ((u64)(0x013ef342d37a407cU)),}, (strconv__Uint128){.lo = ((u64)(0xa2a580f6f147cc10U)),.hi = ((u64)(0x018eb0138858d09bU)),}, (strconv__Uint128){.lo = ((u64)(0x8b4ee134ad99bf15U)),.hi = ((u64)(0x01f25c186a6f04c2U)),},
		(strconv__Uint128){.lo = ((u64)(0x97114cc0ec80176dU)),.hi = ((u64)(0x0137798f428562f9U)),}, (strconv__Uint128){.lo = ((u64)(0xfcd59ff127a01d48U)),.hi = ((u64)(0x018557f31326bbb7U)),}, (strconv__Uint128){.lo = ((u64)(0xfc0b07ed7188249aU)),.hi = ((u64)(0x01e6adefd7f06aa5U)),}, (strconv__Uint128){.lo = ((u64)(0xbd86e4f466f516e0U)),.hi = ((u64)(0x01302cb5e6f642a7U)),}, (strconv__Uint128){.lo = ((u64)(0xace89e3180b25c98U)),.hi = ((u64)(0x017c37e360b3d351U)),}, (strconv__Uint128){.lo = ((u64)(0x1822c5bde0def3beU)),.hi = ((u64)(0x01db45dc38e0c826U)),}, (strconv__Uint128){.lo = ((u64)(0xcf15bb96ac8b5857U)),.hi = ((u64)(0x01290ba9a38c7d17U)),}, (strconv__Uint128){.lo = ((u64)(0xc2db2a7c57ae2e6dU)),.hi = ((u64)(0x01734e940c6f9c5dU)),},
		(strconv__Uint128){.lo = ((u64)(0x3391f51b6d99ba08U)),.hi = ((u64)(0x01d022390f8b8375U)),}, (strconv__Uint128){.lo = ((u64)(0x403b393124801445U)),.hi = ((u64)(0x01221563a9b73229U)),}, (strconv__Uint128){.lo = ((u64)(0x904a077d6da01956U)),.hi = ((u64)(0x016a9abc9424feb3U)),}, (strconv__Uint128){.lo = ((u64)(0x745c895cc9081facU)),.hi = ((u64)(0x01c5416bb92e3e60U)),}, (strconv__Uint128){.lo = ((u64)(0x48b9d5d9fda513cbU)),.hi = ((u64)(0x011b48e353bce6fcU)),}, (strconv__Uint128){.lo = ((u64)(0x5ae84b507d0e58beU)),.hi = ((u64)(0x01621b1c28ac20bbU)),}, (strconv__Uint128){.lo = ((u64)(0x31a25e249c51eeeeU)),.hi = ((u64)(0x01baa1e332d728eaU)),}, (strconv__Uint128){.lo = ((u64)(0x5f057ad6e1b33554U)),.hi = ((u64)(0x0114a52dffc67992U)),},
		(strconv__Uint128){.lo = ((u64)(0xf6c6d98c9a2002aaU)),.hi = ((u64)(0x0159ce797fb817f6U)),}, (strconv__Uint128){.lo = ((u64)(0xb4788fefc0a80354U)),.hi = ((u64)(0x01b04217dfa61df4U)),}, (strconv__Uint128){.lo = ((u64)(0xf0cb59f5d8690214U)),.hi = ((u64)(0x010e294eebc7d2b8U)),}, (strconv__Uint128){.lo = ((u64)(0x2cfe30734e83429aU)),.hi = ((u64)(0x0151b3a2a6b9c767U)),}, (strconv__Uint128){.lo = ((u64)(0xf83dbc9022241340U)),.hi = ((u64)(0x01a6208b50683940U)),}, (strconv__Uint128){.lo = ((u64)(0x9b2695da15568c08U)),.hi = ((u64)(0x0107d457124123c8U)),}, (strconv__Uint128){.lo = ((u64)(0xc1f03b509aac2f0aU)),.hi = ((u64)(0x0149c96cd6d16cbaU)),}, (strconv__Uint128){.lo = ((u64)(0x726c4a24c1573acdU)),.hi = ((u64)(0x019c3bc80c85c7e9U)),},
		(strconv__Uint128){.lo = ((u64)(0xe783ae56f8d684c0U)),.hi = ((u64)(0x0101a55d07d39cf1U)),}, (strconv__Uint128){.lo = ((u64)(0x616499ecb70c25f0U)),.hi = ((u64)(0x01420eb449c8842eU)),}, (strconv__Uint128){.lo = ((u64)(0xf9bdc067e4cf2f6cU)),.hi = ((u64)(0x019292615c3aa539U)),}, (strconv__Uint128){.lo = ((u64)(0x782d3081de02fb47U)),.hi = ((u64)(0x01f736f9b3494e88U)),}, (strconv__Uint128){.lo = ((u64)(0x4b1c3e512ac1dd0cU)),.hi = ((u64)(0x013a825c100dd115U)),}, (strconv__Uint128){.lo = ((u64)(0x9de34de57572544fU)),.hi = ((u64)(0x018922f31411455aU)),}, (strconv__Uint128){.lo = ((u64)(0x455c215ed2cee963U)),.hi = ((u64)(0x01eb6bafd91596b1U)),}, (strconv__Uint128){.lo = ((u64)(0xcb5994db43c151deU)),.hi = ((u64)(0x0133234de7ad7e2eU)),},
		(strconv__Uint128){.lo = ((u64)(0x7e2ffa1214b1a655U)),.hi = ((u64)(0x017fec216198ddbaU)),}, (strconv__Uint128){.lo = ((u64)(0x1dbbf89699de0febU)),.hi = ((u64)(0x01dfe729b9ff1529U)),}, (strconv__Uint128){.lo = ((u64)(0xb2957b5e202ac9f3U)),.hi = ((u64)(0x012bf07a143f6d39U)),}, (strconv__Uint128){.lo = ((u64)(0x1f3ada35a8357c6fU)),.hi = ((u64)(0x0176ec98994f4888U)),}, (strconv__Uint128){.lo = ((u64)(0x270990c31242db8bU)),.hi = ((u64)(0x01d4a7bebfa31aaaU)),}, (strconv__Uint128){.lo = ((u64)(0x5865fa79eb69c937U)),.hi = ((u64)(0x0124e8d737c5f0aaU)),}, (strconv__Uint128){.lo = ((u64)(0xee7f791866443b85U)),.hi = ((u64)(0x016e230d05b76cd4U)),}, (strconv__Uint128){.lo = ((u64)(0x2a1f575e7fd54a66U)),.hi = ((u64)(0x01c9abd04725480aU)),},
		(strconv__Uint128){.lo = ((u64)(0x5a53969b0fe54e80U)),.hi = ((u64)(0x011e0b622c774d06U)),}, (strconv__Uint128){.lo = ((u64)(0xf0e87c41d3dea220U)),.hi = ((u64)(0x01658e3ab7952047U)),}, (strconv__Uint128){.lo = ((u64)(0xed229b5248d64aa8U)),.hi = ((u64)(0x01bef1c9657a6859U)),}, (strconv__Uint128){.lo = ((u64)(0x3435a1136d85eea9U)),.hi = ((u64)(0x0117571ddf6c8138U)),}, (strconv__Uint128){.lo = ((u64)(0x4143095848e76a53U)),.hi = ((u64)(0x015d2ce55747a186U)),}, (strconv__Uint128){.lo = ((u64)(0xd193cbae5b2144e8U)),.hi = ((u64)(0x01b4781ead1989e7U)),}, (strconv__Uint128){.lo = ((u64)(0xe2fc5f4cf8f4cb11U)),.hi = ((u64)(0x0110cb132c2ff630U)),}, (strconv__Uint128){.lo = ((u64)(0x1bbb77203731fdd5U)),.hi = ((u64)(0x0154fdd7f73bf3bdU)),},
		(strconv__Uint128){.lo = ((u64)(0x62aa54e844fe7d4aU)),.hi = ((u64)(0x01aa3d4df50af0acU)),}, (strconv__Uint128){.lo = ((u64)(0xbdaa75112b1f0e4eU)),.hi = ((u64)(0x010a6650b926d66bU)),}, (strconv__Uint128){.lo = ((u64)(0xad15125575e6d1e2U)),.hi = ((u64)(0x014cffe4e7708c06U)),}, (strconv__Uint128){.lo = ((u64)(0x585a56ead360865bU)),.hi = ((u64)(0x01a03fde214caf08U)),}, (strconv__Uint128){.lo = ((u64)(0x37387652c41c53f8U)),.hi = ((u64)(0x010427ead4cfed65U)),}, (strconv__Uint128){.lo = ((u64)(0x850693e7752368f7U)),.hi = ((u64)(0x014531e58a03e8beU)),}, (strconv__Uint128){.lo = ((u64)(0x264838e1526c4334U)),.hi = ((u64)(0x01967e5eec84e2eeU)),}, (strconv__Uint128){.lo = ((u64)(0xafda4719a7075402U)),.hi = ((u64)(0x01fc1df6a7a61ba9U)),},
		(strconv__Uint128){.lo = ((u64)(0x0de86c7008649481U)),.hi = ((u64)(0x013d92ba28c7d14aU)),}, (strconv__Uint128){.lo = ((u64)(0x9162878c0a7db9a1U)),.hi = ((u64)(0x018cf768b2f9c59cU)),}, (strconv__Uint128){.lo = ((u64)(0xb5bb296f0d1d280aU)),.hi = ((u64)(0x01f03542dfb83703U)),}, (strconv__Uint128){.lo = ((u64)(0x5194f9e568323906U)),.hi = ((u64)(0x01362149cbd32262U)),}, (strconv__Uint128){.lo = ((u64)(0xe5fa385ec23ec747U)),.hi = ((u64)(0x0183a99c3ec7eafaU)),}, (strconv__Uint128){.lo = ((u64)(0x9f78c67672ce7919U)),.hi = ((u64)(0x01e494034e79e5b9U)),}, (strconv__Uint128){.lo = ((u64)(0x03ab7c0a07c10bb0U)),.hi = ((u64)(0x012edc82110c2f94U)),}, (strconv__Uint128){.lo = ((u64)(0x04965b0c89b14e9cU)),.hi = ((u64)(0x017a93a2954f3b79U)),},
		(strconv__Uint128){.lo = ((u64)(0x45bbf1cfac1da243U)),.hi = ((u64)(0x01d9388b3aa30a57U)),}, (strconv__Uint128){.lo = ((u64)(0x8b957721cb92856aU)),.hi = ((u64)(0x0127c35704a5e676U)),}, (strconv__Uint128){.lo = ((u64)(0x2e7ad4ea3e7726c4U)),.hi = ((u64)(0x0171b42cc5cf6014U)),}, (strconv__Uint128){.lo = ((u64)(0x3a198a24ce14f075U)),.hi = ((u64)(0x01ce2137f7433819U)),}, (strconv__Uint128){.lo = ((u64)(0xc44ff65700cd1649U)),.hi = ((u64)(0x0120d4c2fa8a030fU)),}, (strconv__Uint128){.lo = ((u64)(0xb563f3ecc1005bdbU)),.hi = ((u64)(0x016909f3b92c83d3U)),}, (strconv__Uint128){.lo = ((u64)(0xa2bcf0e7f14072d2U)),.hi = ((u64)(0x01c34c70a777a4c8U)),}, (strconv__Uint128){.lo = ((u64)(0x65b61690f6c847c3U)),.hi = ((u64)(0x011a0fc668aac6fdU)),},
		(strconv__Uint128){.lo = ((u64)(0xbf239c35347a59b4U)),.hi = ((u64)(0x016093b802d578bcU)),}, (strconv__Uint128){.lo = ((u64)(0xeeec83428198f021U)),.hi = ((u64)(0x01b8b8a6038ad6ebU)),}, (strconv__Uint128){.lo = ((u64)(0x7553d20990ff9615U)),.hi = ((u64)(0x01137367c236c653U)),}, (strconv__Uint128){.lo = ((u64)(0x52a8c68bf53f7b9aU)),.hi = ((u64)(0x01585041b2c477e8U)),}, (strconv__Uint128){.lo = ((u64)(0x6752f82ef28f5a81U)),.hi = ((u64)(0x01ae64521f7595e2U)),}, (strconv__Uint128){.lo = ((u64)(0x8093db1d57999890U)),.hi = ((u64)(0x010cfeb353a97dadU)),}, (strconv__Uint128){.lo = ((u64)(0xe0b8d1e4ad7ffeb4U)),.hi = ((u64)(0x01503e602893dd18U)),}, (strconv__Uint128){.lo = ((u64)(0x18e7065dd8dffe62U)),.hi = ((u64)(0x01a44df832b8d45fU)),},
		(strconv__Uint128){.lo = ((u64)(0x6f9063faa78bfefdU)),.hi = ((u64)(0x0106b0bb1fb384bbU)),}, (strconv__Uint128){.lo = ((u64)(0x4b747cf9516efebcU)),.hi = ((u64)(0x01485ce9e7a065eaU)),}, (strconv__Uint128){.lo = ((u64)(0xde519c37a5cabe6bU)),.hi = ((u64)(0x019a742461887f64U)),}, (strconv__Uint128){.lo = ((u64)(0x0af301a2c79eb703U)),.hi = ((u64)(0x01008896bcf54f9fU)),}, (strconv__Uint128){.lo = ((u64)(0xcdafc20b798664c4U)),.hi = ((u64)(0x0140aabc6c32a386U)),}, (strconv__Uint128){.lo = ((u64)(0x811bb28e57e7fdf5U)),.hi = ((u64)(0x0190d56b873f4c68U)),}, (strconv__Uint128){.lo = ((u64)(0xa1629f31ede1fd72U)),.hi = ((u64)(0x01f50ac6690f1f82U)),}, (strconv__Uint128){.lo = ((u64)(0xa4dda37f34ad3e67U)),.hi = ((u64)(0x013926bc01a973b1U)),},
		(strconv__Uint128){.lo = ((u64)(0x0e150c5f01d88e01U)),.hi = ((u64)(0x0187706b0213d09eU)),}, (strconv__Uint128){.lo = ((u64)(0x919a4f76c24eb181U)),.hi = ((u64)(0x01e94c85c298c4c5U)),}, (strconv__Uint128){.lo = ((u64)(0x7b0071aa39712ef1U)),.hi = ((u64)(0x0131cfd3999f7afbU)),}, (strconv__Uint128){.lo = ((u64)(0x59c08e14c7cd7aadU)),.hi = ((u64)(0x017e43c8800759baU)),}, (strconv__Uint128){.lo = ((u64)(0xf030b199f9c0d958U)),.hi = ((u64)(0x01ddd4baa0093028U)),}, (strconv__Uint128){.lo = ((u64)(0x961e6f003c1887d7U)),.hi = ((u64)(0x012aa4f4a405be19U)),}, (strconv__Uint128){.lo = ((u64)(0xfba60ac04b1ea9cdU)),.hi = ((u64)(0x01754e31cd072d9fU)),}, (strconv__Uint128){.lo = ((u64)(0xfa8f8d705de65440U)),.hi = ((u64)(0x01d2a1be4048f907U)),},
		(strconv__Uint128){.lo = ((u64)(0xfc99b8663aaff4a8U)),.hi = ((u64)(0x0123a516e82d9ba4U)),}, (strconv__Uint128){.lo = ((u64)(0x3bc0267fc95bf1d2U)),.hi = ((u64)(0x016c8e5ca239028eU)),}, (strconv__Uint128){.lo = ((u64)(0xcab0301fbbb2ee47U)),.hi = ((u64)(0x01c7b1f3cac74331U)),}, (strconv__Uint128){.lo = ((u64)(0x1eae1e13d54fd4ecU)),.hi = ((u64)(0x011ccf385ebc89ffU)),}, (strconv__Uint128){.lo = ((u64)(0xe659a598caa3ca27U)),.hi = ((u64)(0x01640306766bac7eU)),}, (strconv__Uint128){.lo = ((u64)(0x9ff00efefd4cbcb1U)),.hi = ((u64)(0x01bd03c81406979eU)),}, (strconv__Uint128){.lo = ((u64)(0x23f6095f5e4ff5efU)),.hi = ((u64)(0x0116225d0c841ec3U)),}, (strconv__Uint128){.lo = ((u64)(0xecf38bb735e3f36aU)),.hi = ((u64)(0x015baaf44fa52673U)),},
		(strconv__Uint128){.lo = ((u64)(0xe8306ea5035cf045U)),.hi = ((u64)(0x01b295b1638e7010U)),}, (strconv__Uint128){.lo = ((u64)(0x911e4527221a162bU)),.hi = ((u64)(0x010f9d8ede39060aU)),}, (strconv__Uint128){.lo = ((u64)(0x3565d670eaa09bb6U)),.hi = ((u64)(0x015384f295c7478dU)),}, (strconv__Uint128){.lo = ((u64)(0x82bf4c0d2548c2a3U)),.hi = ((u64)(0x01a8662f3b391970U)),}, (strconv__Uint128){.lo = ((u64)(0x51b78f88374d79a6U)),.hi = ((u64)(0x01093fdd8503afe6U)),}, (strconv__Uint128){.lo = ((u64)(0xe625736a4520d810U)),.hi = ((u64)(0x014b8fd4e6449bdfU)),}, (strconv__Uint128){.lo = ((u64)(0xdfaed044d6690e14U)),.hi = ((u64)(0x019e73ca1fd5c2d7U)),}, (strconv__Uint128){.lo = ((u64)(0xebcd422b0601a8ccU)),.hi = ((u64)(0x0103085e53e599c6U)),},
		(strconv__Uint128){.lo = ((u64)(0xa6c092b5c78212ffU)),.hi = ((u64)(0x0143ca75e8df0038U)),}, (strconv__Uint128){.lo = ((u64)(0xd070b763396297bfU)),.hi = ((u64)(0x0194bd136316c046U)),}, (strconv__Uint128){.lo = ((u64)(0x848ce53c07bb3dafU)),.hi = ((u64)(0x01f9ec583bdc7058U)),}, (strconv__Uint128){.lo = ((u64)(0x52d80f4584d5068dU)),.hi = ((u64)(0x013c33b72569c637U)),}, (strconv__Uint128){.lo = ((u64)(0x278e1316e60a4831U)),.hi = ((u64)(0x018b40a4eec437c5U)),}}));
	_const_strconv__pow5_inv_split_64 = new_array_from_c_array(292, 292, sizeof(strconv__Uint128), _MOV((strconv__Uint128[292]){
		(strconv__Uint128){.lo = ((u64)(0x0000000000000001U)),.hi = ((u64)(0x0400000000000000U)),}, (strconv__Uint128){.lo = ((u64)(0x3333333333333334U)),.hi = ((u64)(0x0333333333333333U)),}, (strconv__Uint128){.lo = ((u64)(0x28f5c28f5c28f5c3U)),.hi = ((u64)(0x028f5c28f5c28f5cU)),}, (strconv__Uint128){.lo = ((u64)(0xed916872b020c49cU)),.hi = ((u64)(0x020c49ba5e353f7cU)),}, (strconv__Uint128){.lo = ((u64)(0xaf4f0d844d013a93U)),.hi = ((u64)(0x0346dc5d63886594U)),}, (strconv__Uint128){.lo = ((u64)(0x8c3f3e0370cdc876U)),.hi = ((u64)(0x029f16b11c6d1e10U)),}, (strconv__Uint128){.lo = ((u64)(0xd698fe69270b06c5U)),.hi = ((u64)(0x0218def416bdb1a6U)),}, (strconv__Uint128){.lo = ((u64)(0xf0f4ca41d811a46eU)),.hi = ((u64)(0x035afe535795e90aU)),}, (strconv__Uint128){.lo = ((u64)(0xf3f70834acdae9f1U)),.hi = ((u64)(0x02af31dc4611873bU)),},
		(strconv__Uint128){.lo = ((u64)(0x5cc5a02a23e254c1U)),.hi = ((u64)(0x0225c17d04dad296U)),}, (strconv__Uint128){.lo = ((u64)(0xfad5cd10396a2135U)),.hi = ((u64)(0x036f9bfb3af7b756U)),}, (strconv__Uint128){.lo = ((u64)(0xfbde3da69454e75eU)),.hi = ((u64)(0x02bfaffc2f2c92abU)),}, (strconv__Uint128){.lo = ((u64)(0x2fe4fe1edd10b918U)),.hi = ((u64)(0x0232f33025bd4223U)),}, (strconv__Uint128){.lo = ((u64)(0x4ca19697c81ac1bfU)),.hi = ((u64)(0x0384b84d092ed038U)),}, (strconv__Uint128){.lo = ((u64)(0x3d4e1213067bce33U)),.hi = ((u64)(0x02d09370d4257360U)),}, (strconv__Uint128){.lo = ((u64)(0x643e74dc052fd829U)),.hi = ((u64)(0x024075f3dceac2b3U)),}, (strconv__Uint128){.lo = ((u64)(0x6d30baf9a1e626a7U)),.hi = ((u64)(0x039a5652fb113785U)),},
		(strconv__Uint128){.lo = ((u64)(0x2426fbfae7eb5220U)),.hi = ((u64)(0x02e1dea8c8da92d1U)),}, (strconv__Uint128){.lo = ((u64)(0x1cebfcc8b9890e80U)),.hi = ((u64)(0x024e4bba3a487574U)),}, (strconv__Uint128){.lo = ((u64)(0x94acc7a78f41b0ccU)),.hi = ((u64)(0x03b07929f6da5586U)),}, (strconv__Uint128){.lo = ((u64)(0xaa23d2ec729af3d7U)),.hi = ((u64)(0x02f394219248446bU)),}, (strconv__Uint128){.lo = ((u64)(0xbb4fdbf05baf2979U)),.hi = ((u64)(0x025c768141d369efU)),}, (strconv__Uint128){.lo = ((u64)(0xc54c931a2c4b758dU)),.hi = ((u64)(0x03c7240202ebdcb2U)),}, (strconv__Uint128){.lo = ((u64)(0x9dd6dc14f03c5e0bU)),.hi = ((u64)(0x0305b66802564a28U)),}, (strconv__Uint128){.lo = ((u64)(0x4b1249aa59c9e4d6U)),.hi = ((u64)(0x026af8533511d4edU)),},
		(strconv__Uint128){.lo = ((u64)(0x44ea0f76f60fd489U)),.hi = ((u64)(0x03de5a1ebb4fbb15U)),}, (strconv__Uint128){.lo = ((u64)(0x6a54d92bf80caa07U)),.hi = ((u64)(0x0318481895d96277U)),}, (strconv__Uint128){.lo = ((u64)(0x21dd7a89933d54d2U)),.hi = ((u64)(0x0279d346de4781f9U)),}, (strconv__Uint128){.lo = ((u64)(0x362f2a75b8622150U)),.hi = ((u64)(0x03f61ed7ca0c0328U)),}, (strconv__Uint128){.lo = ((u64)(0xf825bb91604e810dU)),.hi = ((u64)(0x032b4bdfd4d668ecU)),}, (strconv__Uint128){.lo = ((u64)(0xc684960de6a5340bU)),.hi = ((u64)(0x0289097fdd7853f0U)),}, (strconv__Uint128){.lo = ((u64)(0xd203ab3e521dc33cU)),.hi = ((u64)(0x02073accb12d0ff3U)),}, (strconv__Uint128){.lo = ((u64)(0xe99f7863b696052cU)),.hi = ((u64)(0x033ec47ab514e652U)),},
		(strconv__Uint128){.lo = ((u64)(0x87b2c6b62bab3757U)),.hi = ((u64)(0x02989d2ef743eb75U)),}, (strconv__Uint128){.lo = ((u64)(0xd2f56bc4efbc2c45U)),.hi = ((u64)(0x0213b0f25f69892aU)),}, (strconv__Uint128){.lo = ((u64)(0x1e55793b192d13a2U)),.hi = ((u64)(0x0352b4b6ff0f41deU)),}, (strconv__Uint128){.lo = ((u64)(0x4b77942f475742e8U)),.hi = ((u64)(0x02a8909265a5ce4bU)),}, (strconv__Uint128){.lo = ((u64)(0xd5f9435905df68baU)),.hi = ((u64)(0x022073a8515171d5U)),}, (strconv__Uint128){.lo = ((u64)(0x565b9ef4d6324129U)),.hi = ((u64)(0x03671f73b54f1c89U)),}, (strconv__Uint128){.lo = ((u64)(0xdeafb25d78283421U)),.hi = ((u64)(0x02b8e5f62aa5b06dU)),}, (strconv__Uint128){.lo = ((u64)(0x188c8eb12cecf681U)),.hi = ((u64)(0x022d84c4eeeaf38bU)),},
		(strconv__Uint128){.lo = ((u64)(0x8dadb11b7b14bd9bU)),.hi = ((u64)(0x037c07a17e44b8deU)),}, (strconv__Uint128){.lo = ((u64)(0x7157c0e2c8dd647cU)),.hi = ((u64)(0x02c99fb46503c718U)),}, (strconv__Uint128){.lo = ((u64)(0x8ddfcd823a4ab6caU)),.hi = ((u64)(0x023ae629ea696c13U)),}, (strconv__Uint128){.lo = ((u64)(0x1632e269f6ddf142U)),.hi = ((u64)(0x0391704310a8acecU)),}, (strconv__Uint128){.lo = ((u64)(0x44f581ee5f17f435U)),.hi = ((u64)(0x02dac035a6ed5723U)),}, (strconv__Uint128){.lo = ((u64)(0x372ace584c1329c4U)),.hi = ((u64)(0x024899c4858aac1cU)),}, (strconv__Uint128){.lo = ((u64)(0xbeaae3c079b842d3U)),.hi = ((u64)(0x03a75c6da27779c6U)),}, (strconv__Uint128){.lo = ((u64)(0x6555830061603576U)),.hi = ((u64)(0x02ec49f14ec5fb05U)),},
		(strconv__Uint128){.lo = ((u64)(0xb7779c004de6912bU)),.hi = ((u64)(0x0256a18dd89e626aU)),}, (strconv__Uint128){.lo = ((u64)(0xf258f99a163db512U)),.hi = ((u64)(0x03bdcf495a9703ddU)),}, (strconv__Uint128){.lo = ((u64)(0x5b7a614811caf741U)),.hi = ((u64)(0x02fe3f6de212697eU)),}, (strconv__Uint128){.lo = ((u64)(0xaf951aa00e3bf901U)),.hi = ((u64)(0x0264ff8b1b41edfeU)),}, (strconv__Uint128){.lo = ((u64)(0x7f54f7667d2cc19bU)),.hi = ((u64)(0x03d4cc11c5364997U)),}, (strconv__Uint128){.lo = ((u64)(0x32aa5f8530f09ae3U)),.hi = ((u64)(0x0310a3416a91d479U)),}, (strconv__Uint128){.lo = ((u64)(0xf55519375a5a1582U)),.hi = ((u64)(0x0273b5cdeedb1060U)),}, (strconv__Uint128){.lo = ((u64)(0xbbbb5b8bc3c3559dU)),.hi = ((u64)(0x03ec56164af81a34U)),},
		(strconv__Uint128){.lo = ((u64)(0x2fc916096969114aU)),.hi = ((u64)(0x03237811d593482aU)),}, (strconv__Uint128){.lo = ((u64)(0x596dab3ababa743cU)),.hi = ((u64)(0x0282c674aadc39bbU)),}, (strconv__Uint128){.lo = ((u64)(0x478aef622efb9030U)),.hi = ((u64)(0x0202385d557cfafcU)),}, (strconv__Uint128){.lo = ((u64)(0xd8de4bd04b2c19e6U)),.hi = ((u64)(0x0336c0955594c4c6U)),}, (strconv__Uint128){.lo = ((u64)(0xad7ea30d08f014b8U)),.hi = ((u64)(0x029233aaaadd6a38U)),}, (strconv__Uint128){.lo = ((u64)(0x24654f3da0c01093U)),.hi = ((u64)(0x020e8fbbbbe454faU)),}, (strconv__Uint128){.lo = ((u64)(0x3a3bb1fc346680ebU)),.hi = ((u64)(0x034a7f92c63a2190U)),}, (strconv__Uint128){.lo = ((u64)(0x94fc8e635d1ecd89U)),.hi = ((u64)(0x02a1ffa89e94e7a6U)),},
		(strconv__Uint128){.lo = ((u64)(0xaa63a51c4a7f0ad4U)),.hi = ((u64)(0x021b32ed4baa52ebU)),}, (strconv__Uint128){.lo = ((u64)(0xdd6c3b607731aaedU)),.hi = ((u64)(0x035eb7e212aa1e45U)),}, (strconv__Uint128){.lo = ((u64)(0x1789c919f8f488bdU)),.hi = ((u64)(0x02b22cb4dbbb4b6bU)),}, (strconv__Uint128){.lo = ((u64)(0xac6e3a7b2d906d64U)),.hi = ((u64)(0x022823c3e2fc3c55U)),}, (strconv__Uint128){.lo = ((u64)(0x13e390c515b3e23aU)),.hi = ((u64)(0x03736c6c9e606089U)),}, (strconv__Uint128){.lo = ((u64)(0xdcb60d6a77c31b62U)),.hi = ((u64)(0x02c2bd23b1e6b3a0U)),}, (strconv__Uint128){.lo = ((u64)(0x7d5e7121f968e2b5U)),.hi = ((u64)(0x0235641c8e52294dU)),}, (strconv__Uint128){.lo = ((u64)(0xc8971b698f0e3787U)),.hi = ((u64)(0x0388a02db0837548U)),},
		(strconv__Uint128){.lo = ((u64)(0xa078e2bad8d82c6cU)),.hi = ((u64)(0x02d3b357c0692aa0U)),}, (strconv__Uint128){.lo = ((u64)(0xe6c71bc8ad79bd24U)),.hi = ((u64)(0x0242f5dfcd20eee6U)),}, (strconv__Uint128){.lo = ((u64)(0x0ad82c7448c2c839U)),.hi = ((u64)(0x039e5632e1ce4b0bU)),}, (strconv__Uint128){.lo = ((u64)(0x3be023903a356cfaU)),.hi = ((u64)(0x02e511c24e3ea26fU)),}, (strconv__Uint128){.lo = ((u64)(0x2fe682d9c82abd95U)),.hi = ((u64)(0x0250db01d8321b8cU)),}, (strconv__Uint128){.lo = ((u64)(0x4ca4048fa6aac8eeU)),.hi = ((u64)(0x03b4919c8d1cf8e0U)),}, (strconv__Uint128){.lo = ((u64)(0x3d5003a61eef0725U)),.hi = ((u64)(0x02f6dae3a4172d80U)),}, (strconv__Uint128){.lo = ((u64)(0x9773361e7f259f51U)),.hi = ((u64)(0x025f1582e9ac2466U)),},
		(strconv__Uint128){.lo = ((u64)(0x8beb89ca6508fee8U)),.hi = ((u64)(0x03cb559e42ad070aU)),}, (strconv__Uint128){.lo = ((u64)(0x6fefa16eb73a6586U)),.hi = ((u64)(0x0309114b688a6c08U)),}, (strconv__Uint128){.lo = ((u64)(0xf3261abef8fb846bU)),.hi = ((u64)(0x026da76f86d52339U)),}, (strconv__Uint128){.lo = ((u64)(0x51d691318e5f3a45U)),.hi = ((u64)(0x03e2a57f3e21d1f6U)),}, (strconv__Uint128){.lo = ((u64)(0x0e4540f471e5c837U)),.hi = ((u64)(0x031bb798fe8174c5U)),}, (strconv__Uint128){.lo = ((u64)(0xd8376729f4b7d360U)),.hi = ((u64)(0x027c92e0cb9ac3d0U)),}, (strconv__Uint128){.lo = ((u64)(0xf38bd84321261effU)),.hi = ((u64)(0x03fa849adf5e061aU)),}, (strconv__Uint128){.lo = ((u64)(0x293cad0280eb4bffU)),.hi = ((u64)(0x032ed07be5e4d1afU)),},
		(strconv__Uint128){.lo = ((u64)(0xedca240200bc3cccU)),.hi = ((u64)(0x028bd9fcb7ea4158U)),}, (strconv__Uint128){.lo = ((u64)(0xbe3b50019a3030a4U)),.hi = ((u64)(0x02097b309321cde0U)),}, (strconv__Uint128){.lo = ((u64)(0xc9f88002904d1a9fU)),.hi = ((u64)(0x03425eb41e9c7c9aU)),}, (strconv__Uint128){.lo = ((u64)(0x3b2d3335403daee6U)),.hi = ((u64)(0x029b7ef67ee396e2U)),}, (strconv__Uint128){.lo = ((u64)(0x95bdc291003158b8U)),.hi = ((u64)(0x0215ff2b98b6124eU)),}, (strconv__Uint128){.lo = ((u64)(0x892f9db4cd1bc126U)),.hi = ((u64)(0x035665128df01d4aU)),}, (strconv__Uint128){.lo = ((u64)(0x07594af70a7c9a85U)),.hi = ((u64)(0x02ab840ed7f34aa2U)),}, (strconv__Uint128){.lo = ((u64)(0x6c476f2c0863aed1U)),.hi = ((u64)(0x0222d00bdff5d54eU)),},
		(strconv__Uint128){.lo = ((u64)(0x13a57eacda3917b4U)),.hi = ((u64)(0x036ae67966562217U)),}, (strconv__Uint128){.lo = ((u64)(0x0fb7988a482dac90U)),.hi = ((u64)(0x02bbeb9451de81acU)),}, (strconv__Uint128){.lo = ((u64)(0xd95fad3b6cf156daU)),.hi = ((u64)(0x022fefa9db1867bcU)),}, (strconv__Uint128){.lo = ((u64)(0xf565e1f8ae4ef15cU)),.hi = ((u64)(0x037fe5dc91c0a5faU)),}, (strconv__Uint128){.lo = ((u64)(0x911e4e608b725ab0U)),.hi = ((u64)(0x02ccb7e3a7cd5195U)),}, (strconv__Uint128){.lo = ((u64)(0xda7ea51a0928488dU)),.hi = ((u64)(0x023d5fe9530aa7aaU)),}, (strconv__Uint128){.lo = ((u64)(0xf7310829a8407415U)),.hi = ((u64)(0x039566421e7772aaU)),}, (strconv__Uint128){.lo = ((u64)(0x2c2739baed005cdeU)),.hi = ((u64)(0x02ddeb68185f8eefU)),},
		(strconv__Uint128){.lo = ((u64)(0xbcec2e2f24004a4bU)),.hi = ((u64)(0x024b22b9ad193f25U)),}, (strconv__Uint128){.lo = ((u64)(0x94ad16b1d333aa11U)),.hi = ((u64)(0x03ab6ac2ae8ecb6fU)),}, (strconv__Uint128){.lo = ((u64)(0xaa241227dc2954dbU)),.hi = ((u64)(0x02ef889bbed8a2bfU)),}, (strconv__Uint128){.lo = ((u64)(0x54e9a81fe35443e2U)),.hi = ((u64)(0x02593a163246e899U)),}, (strconv__Uint128){.lo = ((u64)(0x2175d9cc9eed396aU)),.hi = ((u64)(0x03c1f689ea0b0dc2U)),}, (strconv__Uint128){.lo = ((u64)(0xe7917b0a18bdc788U)),.hi = ((u64)(0x03019207ee6f3e34U)),}, (strconv__Uint128){.lo = ((u64)(0xb9412f3b46fe393aU)),.hi = ((u64)(0x0267a8065858fe90U)),}, (strconv__Uint128){.lo = ((u64)(0xf535185ed7fd285cU)),.hi = ((u64)(0x03d90cd6f3c1974dU)),},
		(strconv__Uint128){.lo = ((u64)(0xc42a79e57997537dU)),.hi = ((u64)(0x03140a458fce12a4U)),}, (strconv__Uint128){.lo = ((u64)(0x03552e512e12a931U)),.hi = ((u64)(0x02766e9e0ca4dbb7U)),}, (strconv__Uint128){.lo = ((u64)(0x9eeeb081e3510eb4U)),.hi = ((u64)(0x03f0b0fce107c5f1U)),}, (strconv__Uint128){.lo = ((u64)(0x4bf226ce4f740bc3U)),.hi = ((u64)(0x0326f3fd80d304c1U)),}, (strconv__Uint128){.lo = ((u64)(0xa3281f0b72c33c9cU)),.hi = ((u64)(0x02858ffe00a8d09aU)),}, (strconv__Uint128){.lo = ((u64)(0x1c2018d5f568fd4aU)),.hi = ((u64)(0x020473319a20a6e2U)),}, (strconv__Uint128){.lo = ((u64)(0xf9ccf48988a7fba9U)),.hi = ((u64)(0x033a51e8f69aa49cU)),}, (strconv__Uint128){.lo = ((u64)(0xfb0a5d3ad3b99621U)),.hi = ((u64)(0x02950e53f87bb6e3U)),},
		(strconv__Uint128){.lo = ((u64)(0x2f3b7dc8a96144e7U)),.hi = ((u64)(0x0210d8432d2fc583U)),}, (strconv__Uint128){.lo = ((u64)(0xe52bfc7442353b0cU)),.hi = ((u64)(0x034e26d1e1e608d1U)),}, (strconv__Uint128){.lo = ((u64)(0xb756639034f76270U)),.hi = ((u64)(0x02a4ebdb1b1e6d74U)),}, (strconv__Uint128){.lo = ((u64)(0x2c451c735d92b526U)),.hi = ((u64)(0x021d897c15b1f12aU)),}, (strconv__Uint128){.lo = ((u64)(0x13a1c71efc1deea3U)),.hi = ((u64)(0x0362759355e981ddU)),}, (strconv__Uint128){.lo = ((u64)(0x761b05b2634b2550U)),.hi = ((u64)(0x02b52adc44bace4aU)),}, (strconv__Uint128){.lo = ((u64)(0x91af37c1e908eaa6U)),.hi = ((u64)(0x022a88b036fbd83bU)),}, (strconv__Uint128){.lo = ((u64)(0x82b1f2cfdb417770U)),.hi = ((u64)(0x03774119f192f392U)),},
		(strconv__Uint128){.lo = ((u64)(0xcef4c23fe29ac5f3U)),.hi = ((u64)(0x02c5cdae5adbf60eU)),}, (strconv__Uint128){.lo = ((u64)(0x3f2a34ffe87bd190U)),.hi = ((u64)(0x0237d7beaf165e72U)),}, (strconv__Uint128){.lo = ((u64)(0x984387ffda5fb5b2U)),.hi = ((u64)(0x038c8c644b56fd83U)),}, (strconv__Uint128){.lo = ((u64)(0xe0360666484c915bU)),.hi = ((u64)(0x02d6d6b6a2abfe02U)),}, (strconv__Uint128){.lo = ((u64)(0x802b3851d3707449U)),.hi = ((u64)(0x024578921bbccb35U)),}, (strconv__Uint128){.lo = ((u64)(0x99dec082ebe72075U)),.hi = ((u64)(0x03a25a835f947855U)),}, (strconv__Uint128){.lo = ((u64)(0xae4bcd358985b391U)),.hi = ((u64)(0x02e8486919439377U)),}, (strconv__Uint128){.lo = ((u64)(0xbea30a913ad15c74U)),.hi = ((u64)(0x02536d20e102dc5fU)),},
		(strconv__Uint128){.lo = ((u64)(0xfdd1aa81f7b560b9U)),.hi = ((u64)(0x03b8ae9b019e2d65U)),}, (strconv__Uint128){.lo = ((u64)(0x97daeece5fc44d61U)),.hi = ((u64)(0x02fa2548ce182451U)),}, (strconv__Uint128){.lo = ((u64)(0xdfe258a51969d781U)),.hi = ((u64)(0x0261b76d71ace9daU)),}, (strconv__Uint128){.lo = ((u64)(0x996a276e8f0fbf34U)),.hi = ((u64)(0x03cf8be24f7b0fc4U)),}, (strconv__Uint128){.lo = ((u64)(0xe121b9253f3fcc2aU)),.hi = ((u64)(0x030c6fe83f95a636U)),}, (strconv__Uint128){.lo = ((u64)(0xb41afa8432997022U)),.hi = ((u64)(0x02705986994484f8U)),}, (strconv__Uint128){.lo = ((u64)(0xecf7f739ea8f19cfU)),.hi = ((u64)(0x03e6f5a4286da18dU)),}, (strconv__Uint128){.lo = ((u64)(0x23f99294bba5ae40U)),.hi = ((u64)(0x031f2ae9b9f14e0bU)),},
		(strconv__Uint128){.lo = ((u64)(0x4ffadbaa2fb7be99U)),.hi = ((u64)(0x027f5587c7f43e6fU)),}, (strconv__Uint128){.lo = ((u64)(0x7ff7c5dd1925fdc2U)),.hi = ((u64)(0x03feef3fa6539718U)),}, (strconv__Uint128){.lo = ((u64)(0xccc637e4141e649bU)),.hi = ((u64)(0x033258ffb842df46U)),}, (strconv__Uint128){.lo = ((u64)(0xd704f983434b83afU)),.hi = ((u64)(0x028ead9960357f6bU)),}, (strconv__Uint128){.lo = ((u64)(0x126a6135cf6f9c8cU)),.hi = ((u64)(0x020bbe144cf79923U)),}, (strconv__Uint128){.lo = ((u64)(0x83dd685618b29414U)),.hi = ((u64)(0x0345fced47f28e9eU)),}, (strconv__Uint128){.lo = ((u64)(0x9cb12044e08edcddU)),.hi = ((u64)(0x029e63f1065ba54bU)),}, (strconv__Uint128){.lo = ((u64)(0x16f419d0b3a57d7dU)),.hi = ((u64)(0x02184ff405161dd6U)),},
		(strconv__Uint128){.lo = ((u64)(0x8b20294dec3bfbfbU)),.hi = ((u64)(0x035a19866e89c956U)),}, (strconv__Uint128){.lo = ((u64)(0x3c19baa4bcfcc996U)),.hi = ((u64)(0x02ae7ad1f207d445U)),}, (strconv__Uint128){.lo = ((u64)(0xc9ae2eea30ca3adfU)),.hi = ((u64)(0x02252f0e5b39769dU)),}, (strconv__Uint128){.lo = ((u64)(0x0f7d17dd1add2afdU)),.hi = ((u64)(0x036eb1b091f58a96U)),}, (strconv__Uint128){.lo = ((u64)(0x3f97464a7be42264U)),.hi = ((u64)(0x02bef48d41913babU)),}, (strconv__Uint128){.lo = ((u64)(0xcc790508631ce850U)),.hi = ((u64)(0x02325d3dce0dc955U)),}, (strconv__Uint128){.lo = ((u64)(0xe0c1a1a704fb0d4dU)),.hi = ((u64)(0x0383c862e3494222U)),}, (strconv__Uint128){.lo = ((u64)(0x4d67b4859d95a43eU)),.hi = ((u64)(0x02cfd3824f6dce82U)),},
		(strconv__Uint128){.lo = ((u64)(0x711fc39e17aae9cbU)),.hi = ((u64)(0x023fdc683f8b0b9bU)),}, (strconv__Uint128){.lo = ((u64)(0xe832d2968c44a945U)),.hi = ((u64)(0x039960a6cc11ac2bU)),}, (strconv__Uint128){.lo = ((u64)(0xecf575453d03ba9eU)),.hi = ((u64)(0x02e11a1f09a7bcefU)),}, (strconv__Uint128){.lo = ((u64)(0x572ac4376402fbb1U)),.hi = ((u64)(0x024dae7f3aec9726U)),}, (strconv__Uint128){.lo = ((u64)(0x58446d256cd192b5U)),.hi = ((u64)(0x03af7d985e47583dU)),}, (strconv__Uint128){.lo = ((u64)(0x79d0575123dadbc4U)),.hi = ((u64)(0x02f2cae04b6c4697U)),}, (strconv__Uint128){.lo = ((u64)(0x94a6ac40e97be303U)),.hi = ((u64)(0x025bd5803c569edfU)),}, (strconv__Uint128){.lo = ((u64)(0x8771139b0f2c9e6cU)),.hi = ((u64)(0x03c62266c6f0fe32U)),},
		(strconv__Uint128){.lo = ((u64)(0x9f8da948d8f07ebdU)),.hi = ((u64)(0x0304e85238c0cb5bU)),}, (strconv__Uint128){.lo = ((u64)(0xe60aedd3e0c06564U)),.hi = ((u64)(0x026a5374fa33d5e2U)),}, (strconv__Uint128){.lo = ((u64)(0xa344afb9679a3bd2U)),.hi = ((u64)(0x03dd5254c3862304U)),}, (strconv__Uint128){.lo = ((u64)(0xe903bfc78614fca8U)),.hi = ((u64)(0x031775109c6b4f36U)),}, (strconv__Uint128){.lo = ((u64)(0xba6966393810ca20U)),.hi = ((u64)(0x02792a73b055d8f8U)),}, (strconv__Uint128){.lo = ((u64)(0x2a423d2859b4769aU)),.hi = ((u64)(0x03f510b91a22f4c1U)),}, (strconv__Uint128){.lo = ((u64)(0xee9b642047c39215U)),.hi = ((u64)(0x032a73c7481bf700U)),}, (strconv__Uint128){.lo = ((u64)(0xbee2b680396941aaU)),.hi = ((u64)(0x02885c9f6ce32c00U)),},
		(strconv__Uint128){.lo = ((u64)(0xff1bc53361210155U)),.hi = ((u64)(0x0206b07f8a4f5666U)),}, (strconv__Uint128){.lo = ((u64)(0x31c6085235019bbbU)),.hi = ((u64)(0x033de73276e5570bU)),}, (strconv__Uint128){.lo = ((u64)(0x27d1a041c4014963U)),.hi = ((u64)(0x0297ec285f1ddf3cU)),}, (strconv__Uint128){.lo = ((u64)(0xeca7b367d0010782U)),.hi = ((u64)(0x021323537f4b18fcU)),}, (strconv__Uint128){.lo = ((u64)(0xadd91f0c8001a59dU)),.hi = ((u64)(0x0351d21f3211c194U)),}, (strconv__Uint128){.lo = ((u64)(0xf17a7f3d3334847eU)),.hi = ((u64)(0x02a7db4c280e3476U)),}, (strconv__Uint128){.lo = ((u64)(0x279532975c2a0398U)),.hi = ((u64)(0x021fe2a3533e905fU)),}, (strconv__Uint128){.lo = ((u64)(0xd8eeb75893766c26U)),.hi = ((u64)(0x0366376bb8641a31U)),},
		(strconv__Uint128){.lo = ((u64)(0x7a5892ad42c52352U)),.hi = ((u64)(0x02b82c562d1ce1c1U)),}, (strconv__Uint128){.lo = ((u64)(0xfb7a0ef102374f75U)),.hi = ((u64)(0x022cf044f0e3e7cdU)),}, (strconv__Uint128){.lo = ((u64)(0xc59017e8038bb254U)),.hi = ((u64)(0x037b1a07e7d30c7cU)),}, (strconv__Uint128){.lo = ((u64)(0x37a67986693c8eaaU)),.hi = ((u64)(0x02c8e19feca8d6caU)),}, (strconv__Uint128){.lo = ((u64)(0xf951fad1edca0bbbU)),.hi = ((u64)(0x023a4e198a20abd4U)),}, (strconv__Uint128){.lo = ((u64)(0x28832ae97c76792bU)),.hi = ((u64)(0x03907cf5a9cddfbbU)),}, (strconv__Uint128){.lo = ((u64)(0x2068ef21305ec756U)),.hi = ((u64)(0x02d9fd9154a4b2fcU)),}, (strconv__Uint128){.lo = ((u64)(0x19ed8c1a8d189f78U)),.hi = ((u64)(0x0247fe0ddd508f30U)),},
		(strconv__Uint128){.lo = ((u64)(0x5caf4690e1c0ff26U)),.hi = ((u64)(0x03a66349621a7eb3U)),}, (strconv__Uint128){.lo = ((u64)(0x4a25d20d81673285U)),.hi = ((u64)(0x02eb82a11b48655cU)),}, (strconv__Uint128){.lo = ((u64)(0x3b5174d79ab8f537U)),.hi = ((u64)(0x0256021a7c39eab0U)),}, (strconv__Uint128){.lo = ((u64)(0x921bee25c45b21f1U)),.hi = ((u64)(0x03bcd02a605caab3U)),}, (strconv__Uint128){.lo = ((u64)(0xdb498b5169e2818eU)),.hi = ((u64)(0x02fd735519e3bbc2U)),}, (strconv__Uint128){.lo = ((u64)(0x15d46f7454b53472U)),.hi = ((u64)(0x02645c4414b62fcfU)),}, (strconv__Uint128){.lo = ((u64)(0xefba4bed545520b6U)),.hi = ((u64)(0x03d3c6d35456b2e4U)),}, (strconv__Uint128){.lo = ((u64)(0xf2fb6ff110441a2bU)),.hi = ((u64)(0x030fd242a9def583U)),},
		(strconv__Uint128){.lo = ((u64)(0x8f2f8cc0d9d014efU)),.hi = ((u64)(0x02730e9bbb18c469U)),}, (strconv__Uint128){.lo = ((u64)(0xb1e5ae015c80217fU)),.hi = ((u64)(0x03eb4a92c4f46d75U)),}, (strconv__Uint128){.lo = ((u64)(0xc1848b344a001accU)),.hi = ((u64)(0x0322a20f03f6bdf7U)),}, (strconv__Uint128){.lo = ((u64)(0xce03a2903b3348a3U)),.hi = ((u64)(0x02821b3f365efe5fU)),}, (strconv__Uint128){.lo = ((u64)(0xd802e873628f6d4fU)),.hi = ((u64)(0x0201af65c518cb7fU)),}, (strconv__Uint128){.lo = ((u64)(0x599e40b89db2487fU)),.hi = ((u64)(0x0335e56fa1c14599U)),}, (strconv__Uint128){.lo = ((u64)(0xe14b66fa17c1d399U)),.hi = ((u64)(0x029184594e3437adU)),}, (strconv__Uint128){.lo = ((u64)(0x81091f2e7967dc7aU)),.hi = ((u64)(0x020e037aa4f692f1U)),},
		(strconv__Uint128){.lo = ((u64)(0x9b41cb7d8f0c93f6U)),.hi = ((u64)(0x03499f2aa18a84b5U)),}, (strconv__Uint128){.lo = ((u64)(0xaf67d5fe0c0a0ff8U)),.hi = ((u64)(0x02a14c221ad536f7U)),}, (strconv__Uint128){.lo = ((u64)(0xf2b977fe70080cc7U)),.hi = ((u64)(0x021aa34e7bddc592U)),}, (strconv__Uint128){.lo = ((u64)(0x1df58cca4cd9ae0bU)),.hi = ((u64)(0x035dd2172c9608ebU)),}, (strconv__Uint128){.lo = ((u64)(0xe4c470a1d7148b3cU)),.hi = ((u64)(0x02b174df56de6d88U)),}, (strconv__Uint128){.lo = ((u64)(0x83d05a1b1276d5caU)),.hi = ((u64)(0x022790b2abe5246dU)),}, (strconv__Uint128){.lo = ((u64)(0x9fb3c35e83f1560fU)),.hi = ((u64)(0x0372811ddfd50715U)),}, (strconv__Uint128){.lo = ((u64)(0xb2f635e5365aab3fU)),.hi = ((u64)(0x02c200e4b310d277U)),},
		(strconv__Uint128){.lo = ((u64)(0xf591c4b75eaeef66U)),.hi = ((u64)(0x0234cd83c273db92U)),}, (strconv__Uint128){.lo = ((u64)(0xef4fa125644b18a3U)),.hi = ((u64)(0x0387af39371fc5b7U)),}, (strconv__Uint128){.lo = ((u64)(0x8c3fb41de9d5ad4fU)),.hi = ((u64)(0x02d2f2942c196af9U)),}, (strconv__Uint128){.lo = ((u64)(0x3cffc34b2177bdd9U)),.hi = ((u64)(0x02425ba9bce12261U)),}, (strconv__Uint128){.lo = ((u64)(0x94cc6bab68bf9628U)),.hi = ((u64)(0x039d5f75fb01d09bU)),}, (strconv__Uint128){.lo = ((u64)(0x10a38955ed6611b9U)),.hi = ((u64)(0x02e44c5e6267da16U)),}, (strconv__Uint128){.lo = ((u64)(0xda1c6dde5784dafbU)),.hi = ((u64)(0x02503d184eb97b44U)),}, (strconv__Uint128){.lo = ((u64)(0xf693e2fd58d49191U)),.hi = ((u64)(0x03b394f3b128c53aU)),},
		(strconv__Uint128){.lo = ((u64)(0xc5431bfde0aa0e0eU)),.hi = ((u64)(0x02f610c2f4209dc8U)),}, (strconv__Uint128){.lo = ((u64)(0x6a9c1664b3bb3e72U)),.hi = ((u64)(0x025e73cf29b3b16dU)),}, (strconv__Uint128){.lo = ((u64)(0x10f9bd6dec5eca4fU)),.hi = ((u64)(0x03ca52e50f85e8afU)),}, (strconv__Uint128){.lo = ((u64)(0xda616457f04bd50cU)),.hi = ((u64)(0x03084250d937ed58U)),}, (strconv__Uint128){.lo = ((u64)(0xe1e783798d09773dU)),.hi = ((u64)(0x026d01da475ff113U)),}, (strconv__Uint128){.lo = ((u64)(0x030c058f480f252eU)),.hi = ((u64)(0x03e19c9072331b53U)),}, (strconv__Uint128){.lo = ((u64)(0x68d66ad906728425U)),.hi = ((u64)(0x031ae3a6c1c27c42U)),}, (strconv__Uint128){.lo = ((u64)(0x8711ef14052869b7U)),.hi = ((u64)(0x027be952349b969bU)),},
		(strconv__Uint128){.lo = ((u64)(0x0b4fe4ecd50d75f2U)),.hi = ((u64)(0x03f97550542c242cU)),}, (strconv__Uint128){.lo = ((u64)(0xa2a650bd773df7f5U)),.hi = ((u64)(0x032df7737689b689U)),}, (strconv__Uint128){.lo = ((u64)(0xb551da312c31932aU)),.hi = ((u64)(0x028b2c5c5ed49207U)),}, (strconv__Uint128){.lo = ((u64)(0x5ddb14f4235adc22U)),.hi = ((u64)(0x0208f049e576db39U)),}, (strconv__Uint128){.lo = ((u64)(0x2fc4ee536bc49369U)),.hi = ((u64)(0x034180763bf15ec2U)),}, (strconv__Uint128){.lo = ((u64)(0xbfd0bea92303a921U)),.hi = ((u64)(0x029acd2b63277f01U)),}, (strconv__Uint128){.lo = ((u64)(0x9973cbba8269541aU)),.hi = ((u64)(0x021570ef8285ff34U)),}, (strconv__Uint128){.lo = ((u64)(0x5bec792a6a42202aU)),.hi = ((u64)(0x0355817f373ccb87U)),},
		(strconv__Uint128){.lo = ((u64)(0xe3239421ee9b4cefU)),.hi = ((u64)(0x02aacdff5f63d605U)),}, (strconv__Uint128){.lo = ((u64)(0xb5b6101b25490a59U)),.hi = ((u64)(0x02223e65e5e97804U)),}, (strconv__Uint128){.lo = ((u64)(0x22bce691d541aa27U)),.hi = ((u64)(0x0369fd6fd64259a1U)),}, (strconv__Uint128){.lo = ((u64)(0xb563eba7ddce21b9U)),.hi = ((u64)(0x02bb31264501e14dU)),}, (strconv__Uint128){.lo = ((u64)(0xf78322ecb171b494U)),.hi = ((u64)(0x022f5a850401810aU)),}, (strconv__Uint128){.lo = ((u64)(0x259e9e47824f8753U)),.hi = ((u64)(0x037ef73b399c01abU)),}, (strconv__Uint128){.lo = ((u64)(0x1e187e9f9b72d2a9U)),.hi = ((u64)(0x02cbf8fc2e1667bcU)),}, (strconv__Uint128){.lo = ((u64)(0x4b46cbb2e2c24221U)),.hi = ((u64)(0x023cc73024deb963U)),},
		(strconv__Uint128){.lo = ((u64)(0x120adf849e039d01U)),.hi = ((u64)(0x039471e6a1645bd2U)),}, (strconv__Uint128){.lo = ((u64)(0xdb3be603b19c7d9aU)),.hi = ((u64)(0x02dd27ebb4504974U)),}, (strconv__Uint128){.lo = ((u64)(0x7c2feb3627b0647cU)),.hi = ((u64)(0x024a865629d9d45dU)),}, (strconv__Uint128){.lo = ((u64)(0x2d197856a5e7072cU)),.hi = ((u64)(0x03aa7089dc8fba2fU)),}, (strconv__Uint128){.lo = ((u64)(0x8a7ac6abb7ec05bdU)),.hi = ((u64)(0x02eec06e4a0c94f2U)),}, (strconv__Uint128){.lo = ((u64)(0xd52f05562cbcd164U)),.hi = ((u64)(0x025899f1d4d6dd8eU)),}, (strconv__Uint128){.lo = ((u64)(0x21e4d556adfae8a0U)),.hi = ((u64)(0x03c0f64fbaf1627eU)),}, (strconv__Uint128){.lo = ((u64)(0xe7ea444557fbed4dU)),.hi = ((u64)(0x0300c50c958de864U)),},
		(strconv__Uint128){.lo = ((u64)(0xecbb69d1132ff10aU)),.hi = ((u64)(0x0267040a113e5383U)),}, (strconv__Uint128){.lo = ((u64)(0xadf8a94e851981aaU)),.hi = ((u64)(0x03d8067681fd526cU)),}, (strconv__Uint128){.lo = ((u64)(0x8b2d543ed0e13488U)),.hi = ((u64)(0x0313385ece6441f0U)),}, (strconv__Uint128){.lo = ((u64)(0xd5bddcff0d80f6d3U)),.hi = ((u64)(0x0275c6b23eb69b26U)),}, (strconv__Uint128){.lo = ((u64)(0x892fc7fe7c018aebU)),.hi = ((u64)(0x03efa45064575ea4U)),}, (strconv__Uint128){.lo = ((u64)(0x3a8c9ffec99ad589U)),.hi = ((u64)(0x03261d0d1d12b21dU)),}, (strconv__Uint128){.lo = ((u64)(0xc8707fff07af113bU)),.hi = ((u64)(0x0284e40a7da88e7dU)),}, (strconv__Uint128){.lo = ((u64)(0x39f39998d2f2742fU)),.hi = ((u64)(0x0203e9a1fe2071feU)),},
		(strconv__Uint128){.lo = ((u64)(0x8fec28f484b7204bU)),.hi = ((u64)(0x033975cffd00b663U)),}, (strconv__Uint128){.lo = ((u64)(0xd989ba5d36f8e6a2U)),.hi = ((u64)(0x02945e3ffd9a2b82U)),}, (strconv__Uint128){.lo = ((u64)(0x47a161e42bfa521cU)),.hi = ((u64)(0x02104b66647b5602U)),}, (strconv__Uint128){.lo = ((u64)(0x0c35696d132a1cf9U)),.hi = ((u64)(0x034d4570a0c5566aU)),}, (strconv__Uint128){.lo = ((u64)(0x09c454574288172dU)),.hi = ((u64)(0x02a4378d4d6aab88U)),}, (strconv__Uint128){.lo = ((u64)(0xa169dd129ba0128bU)),.hi = ((u64)(0x021cf93dd7888939U)),}, (strconv__Uint128){.lo = ((u64)(0x0242fb50f9001dabU)),.hi = ((u64)(0x03618ec958da7529U)),}, (strconv__Uint128){.lo = ((u64)(0x9b68c90d940017bcU)),.hi = ((u64)(0x02b4723aad7b90edU)),},
		(strconv__Uint128){.lo = ((u64)(0x4920a0d7a999ac96U)),.hi = ((u64)(0x0229f4fbbdfc73f1U)),}, (strconv__Uint128){.lo = ((u64)(0x750101590f5c4757U)),.hi = ((u64)(0x037654c5fcc71fe8U)),}, (strconv__Uint128){.lo = ((u64)(0x2a6734473f7d05dfU)),.hi = ((u64)(0x02c5109e63d27fedU)),}, (strconv__Uint128){.lo = ((u64)(0xeeb8f69f65fd9e4cU)),.hi = ((u64)(0x0237407eb641fff0U)),}, (strconv__Uint128){.lo = ((u64)(0xe45b24323cc8fd46U)),.hi = ((u64)(0x038b9a6456cfffe7U)),}, (strconv__Uint128){.lo = ((u64)(0xb6af502830a0ca9fU)),.hi = ((u64)(0x02d6151d123fffecU)),}, (strconv__Uint128){.lo = ((u64)(0xf88c402026e7087fU)),.hi = ((u64)(0x0244ddb0db666656U)),}, (strconv__Uint128){.lo = ((u64)(0x2746cd003e3e73feU)),.hi = ((u64)(0x03a162b4923d708bU)),},
		(strconv__Uint128){.lo = ((u64)(0x1f6bd73364fec332U)),.hi = ((u64)(0x02e7822a0e978d3cU)),}, (strconv__Uint128){.lo = ((u64)(0xe5efdf5c50cbcf5bU)),.hi = ((u64)(0x0252ce880bac70fcU)),}, (strconv__Uint128){.lo = ((u64)(0x3cb2fefa1adfb22bU)),.hi = ((u64)(0x03b7b0d9ac471b2eU)),}, (strconv__Uint128){.lo = ((u64)(0x308f3261af195b56U)),.hi = ((u64)(0x02f95a47bd05af58U)),}, (strconv__Uint128){.lo = ((u64)(0x5a0c284e25ade2abU)),.hi = ((u64)(0x0261150630d15913U)),}, (strconv__Uint128){.lo = ((u64)(0x29ad0d49d5e30445U)),.hi = ((u64)(0x03ce8809e7b55b52U)),}, (strconv__Uint128){.lo = ((u64)(0x548a7107de4f369dU)),.hi = ((u64)(0x030ba007ec9115dbU)),}, (strconv__Uint128){.lo = ((u64)(0xdd3b8d9fe50c2bb1U)),.hi = ((u64)(0x026fb3398a0dab15U)),},
		(strconv__Uint128){.lo = ((u64)(0x952c15cca1ad12b5U)),.hi = ((u64)(0x03e5eb8f434911bcU)),}, (strconv__Uint128){.lo = ((u64)(0x775677d6e7bda891U)),.hi = ((u64)(0x031e560c35d40e30U)),}, (strconv__Uint128){.lo = ((u64)(0xc5dec645863153a7U)),.hi = ((u64)(0x027eab3cf7dcd826U)),}}));
	}
	{ // Initializations for module builtin :
	_const_none__ = /*&IError*/I_None___to_Interface_IError((None__*)memdup(&(None__){.msg = (string){.str=(byteptr)"", .is_lit=1},.code = 0,}, sizeof(None__)));
	_const_children_bytes = sizeof(voidptr) * (_const_max_len + 1);
	}
	{ // Initializations for module main :
	}
}
void _vcleanup(void) {
}

int main(int ___argc, char** ___argv){
	_vinit(___argc, (voidptr)___argv);
	main__main();
	_vcleanup();
	return 0;
}

// THE END.
