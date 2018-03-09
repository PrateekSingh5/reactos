/*
 * Copyright (C) 2007 Francois Gouget
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_BCRYPT_H
#define __WINE_BCRYPT_H

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifndef _NTDEF_
typedef _Return_type_success_(return >= 0) LONG NTSTATUS;
typedef NTSTATUS *PNTSTATUS;
#endif

#define BCRYPT_ALGORITHM_NAME L"AlgorithmName"
#define BCRYPT_AUTH_TAG_LENGTH L"AuthTagLength"
#define BCRYPT_BLOCK_LENGTH L"BlockLength"
#define BCRYPT_BLOCK_SIZE_LIST L"BlockSizeList"
#define BCRYPT_CHAINING_MODE L"ChainingMode"
#define BCRYPT_EFFECTIVE_KEY_LENGTH L"EffectiveKeyLength"
#define BCRYPT_HASH_BLOCK_LENGTH L"HashBlockLength"
#define BCRYPT_HASH_LENGTH L"HashDigestLength"
#define BCRYPT_HASH_OID_LIST L"HashOIDList"
#define BCRYPT_KEY_LENGTH L"KeyLength"
#define BCRYPT_KEY_LENGTHS L"KeyLengths"
#define BCRYPT_KEY_OBJECT_LENGTH L"KeyObjectLength"
#define BCRYPT_KEY_STRENGTH L"KeyStrength"
#define BCRYPT_OBJECT_LENGTH L"ObjectLength"
#define BCRYPT_PADDING_SCHEMES L"PaddingSchemes"
#define BCRYPT_PROVIDER_HANDLE L"ProviderHandle"
#define BCRYPT_SIGNATURE_LENGTH L"SignatureLength"

#define BCRYPT_OPAQUE_KEY_BLOB   L"OpaqueKeyBlob"
#define BCRYPT_KEY_DATA_BLOB     (const WCHAR []){'K','e','y','D','a','t','a','B','l','o','b',0}
#define BCRYPT_AES_WRAP_KEY_BLOB (const WCHAR []){'R','f','c','3','5','6','5','K','e','y','W','r','a','p','B','l','o','b',0}
#define BCRYPT_ECCPUBLIC_BLOB    (const WCHAR []){'E','C','C','P','U','B','L','I','C','B','L','O','B',0}
#define BCRYPT_ECCPRIVATE_BLOB   (const WCHAR []){'E','C','C','P','R','I','V','A','T','E','B','L','O','B',0}
#define BCRYPT_RSAPUBLIC_BLOB    (const WCHAR []){'R','S','A','P','U','B','L','I','C','B','L','O','B',0}
#define BCRYPT_RSAPRIVATE_BLOB   (const WCHAR []){'R','S','A','P','R','I','V','A','T','E','B','L','O','B',0}

#define MS_PRIMITIVE_PROVIDER L"Microsoft Primitive Provider"
#define MS_PLATFORM_CRYPTO_PROVIDER L"Microsoft Platform Crypto Provider"

#define BCRYPT_MD5_ALGORITHM        L"MD5"
#define BCRYPT_RNG_ALGORITHM        L"RNG"
#define BCRYPT_SHA1_ALGORITHM       L"SHA1"
#define BCRYPT_SHA256_ALGORITHM     L"SHA256"
#define BCRYPT_SHA384_ALGORITHM     L"SHA384"
#define BCRYPT_SHA512_ALGORITHM     L"SHA512"
#define BCRYPT_ECDSA_P256_ALGORITHM L"ECDSA_P256"
#define BCRYPT_ECDSA_P384_ALGORITHM L"ECDSA_P384"
#define BCRYPT_ECDSA_P521_ALGORITHM L"ECDSA_P521"

#define BCRYPT_ECDSA_PUBLIC_P256_MAGIC  0x31534345
#define BCRYPT_ECDSA_PRIVATE_P256_MAGIC 0x32534345
#define BCRYPT_ECDSA_PUBLIC_P384_MAGIC  0x33534345
#define BCRYPT_ECDSA_PRIVATE_P384_MAGIC 0x34534345
#define BCRYPT_ECDSA_PUBLIC_P521_MAGIC  0x35534345
#define BCRYPT_ECDSA_PRIVATE_P521_MAGIC 0x36534345

typedef struct _BCRYPT_ALGORITHM_IDENTIFIER
{
    LPWSTR pszName;
    ULONG  dwClass;
    ULONG  dwFlags;
} BCRYPT_ALGORITHM_IDENTIFIER;

typedef struct __BCRYPT_KEY_LENGTHS_STRUCT
{
    ULONG dwMinLength;
    ULONG dwMaxLength;
    ULONG dwIncrement;
} BCRYPT_KEY_LENGTHS_STRUCT, BCRYPT_AUTH_TAG_LENGTHS_STRUCT;

typedef struct _BCRYPT_KEY_DATA_BLOB_HEADER
{
    ULONG dwMagic;
    ULONG dwVersion;
    ULONG cbKeyData;
} BCRYPT_KEY_DATA_BLOB_HEADER, *PBCRYPT_KEY_DATA_BLOB_HEADER;

typedef struct _BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO
{
    ULONG cbSize;
    ULONG dwInfoVersion;
    UCHAR *pbNonce;
    ULONG cbNonce;
    UCHAR *pbAuthData;
    ULONG cbAuthData;
    UCHAR *pbTag;
    ULONG cbTag;
    UCHAR *pbMacContext;
    ULONG cbMacContext;
    ULONG cbAAD;
    ULONGLONG cbData;
    ULONG dwFlags;
} BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO, *PBCRYPT_AUTHENTICATED_CIPHER_MODE_INFO;

typedef struct _BCRYPT_ECCKEY_BLOB
{
    ULONG dwMagic;
    ULONG cbKey;
} BCRYPT_ECCKEY_BLOB, *PBCRYPT_ECCKEY_BLOB;

#define BCRYPT_RSAPUBLIC_MAGIC      0x31415352
#define BCRYPT_RSAPRIVATE_MAGIC     0x32415352
#define BCRYPT_RSAFULLPRIVATE_MAGIC 0x33415352

typedef struct _BCRYPT_RSAKEY_BLOB
{
    ULONG Magic;
    ULONG BitLength;
    ULONG cbPublicExp;
    ULONG cbModulus;
    ULONG cbPrime1;
    ULONG cbPrime2;
} BCRYPT_RSAKEY_BLOB;

typedef struct _BCRYPT_PKCS1_PADDING_INFO
{
    LPCWSTR pszAlgId;
} BCRYPT_PKCS1_PADDING_INFO;

#define BCRYPT_PAD_NONE   0x00000001
#define BCRYPT_PAD_PKCS1  0x00000002
#define BCRYPT_PAD_OAEP   0x00000004
#define BCRYPT_PAD_PSS    0x00000008

#define BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION 1

#define BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG 0x00000001
#define BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG 0x00000002

#define BCRYPT_KEY_DATA_BLOB_MAGIC    0x4d42444b
#define BCRYPT_KEY_DATA_BLOB_VERSION1 1

typedef PVOID BCRYPT_ALG_HANDLE;
typedef PVOID BCRYPT_KEY_HANDLE;
typedef PVOID BCRYPT_HANDLE;
typedef PVOID BCRYPT_HASH_HANDLE;

#define BCRYPT_RNG_USE_ENTROPY_IN_BUFFER 0x00000001
#define BCRYPT_USE_SYSTEM_PREFERRED_RNG  0x00000002
#define BCRYPT_ALG_HANDLE_HMAC_FLAG 0x00000008

NTSTATUS WINAPI BCryptCloseAlgorithmProvider(BCRYPT_ALG_HANDLE, ULONG);
NTSTATUS WINAPI BCryptCreateHash(BCRYPT_ALG_HANDLE, BCRYPT_HASH_HANDLE *, PUCHAR, ULONG, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptDecrypt(BCRYPT_KEY_HANDLE, PUCHAR, ULONG, VOID *, PUCHAR, ULONG, PUCHAR, ULONG, ULONG *, ULONG);
NTSTATUS WINAPI BCryptDestroyHash(BCRYPT_HASH_HANDLE);
NTSTATUS WINAPI BCryptDestroyKey(BCRYPT_KEY_HANDLE);
NTSTATUS WINAPI BCryptEncrypt(BCRYPT_KEY_HANDLE, PUCHAR, ULONG, VOID *, PUCHAR, ULONG, PUCHAR, ULONG, ULONG *, ULONG);
NTSTATUS WINAPI BCryptEnumAlgorithms(ULONG, ULONG *, BCRYPT_ALGORITHM_IDENTIFIER **, ULONG);
NTSTATUS WINAPI BCryptFinishHash(BCRYPT_HASH_HANDLE, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptGenerateSymmetricKey(BCRYPT_ALG_HANDLE, BCRYPT_KEY_HANDLE *, PUCHAR, ULONG, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptGenRandom(BCRYPT_ALG_HANDLE, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptGetFipsAlgorithmMode(BOOLEAN *);
NTSTATUS WINAPI BCryptGetProperty(BCRYPT_HANDLE, LPCWSTR, PUCHAR, ULONG, ULONG *, ULONG);
NTSTATUS WINAPI BCryptHash(BCRYPT_ALG_HANDLE, PUCHAR, ULONG, PUCHAR, ULONG, PUCHAR, ULONG);
NTSTATUS WINAPI BCryptHashData(BCRYPT_HASH_HANDLE, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptImportKeyPair(BCRYPT_ALG_HANDLE, BCRYPT_KEY_HANDLE, LPCWSTR, BCRYPT_KEY_HANDLE *, UCHAR *, ULONG, ULONG);
NTSTATUS WINAPI BCryptOpenAlgorithmProvider(BCRYPT_ALG_HANDLE *, LPCWSTR, LPCWSTR, ULONG);
NTSTATUS WINAPI BCryptSetProperty(BCRYPT_HANDLE, LPCWSTR, PUCHAR, ULONG, ULONG);
NTSTATUS WINAPI BCryptDuplicateHash(BCRYPT_HASH_HANDLE, BCRYPT_HASH_HANDLE *, UCHAR *, ULONG, ULONG);
NTSTATUS WINAPI BCryptVerifySignature(BCRYPT_KEY_HANDLE, void *, UCHAR *, ULONG, UCHAR *, ULONG, ULONG);

#endif  /* __WINE_BCRYPT_H */
