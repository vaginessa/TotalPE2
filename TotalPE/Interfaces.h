#pragma once

#include <DiaHelper.h>
#include <libpe.h>

constexpr uint32_t ItemShift = 8;

enum class TreeItemType : uint32_t {
	None = 0,
	Image,
	Directories,
	Directory,
	DirectoryExports = Directory,
	DirectoryImports,
	DirectoryResources,
	Sections = Directory + 16,
	Section,
	Headers,
	NTHeader,
	DOSHeader,
	OptionalHeader,
	RichHeader,
	Debug,
	Resources,
	ResourceTypeName,
	ResourceName,
	ResourceLnaguage,
	ContextMenu,
	CLR,
	Symbols,
	Language,
	Resource,

	ItemMask = 255,
};
DEFINE_ENUM_FLAG_OPERATORS(TreeItemType);

struct FlatResource : libpe::PEResFlat {
	std::wstring Name, Type, Language;
};

struct IMainFrame abstract {
	virtual HWND GetHwnd() const = 0;
	virtual BOOL TrackPopupMenu(HMENU hMenu, DWORD flags, int x, int y, HWND hWnd = nullptr) = 0;
	virtual CUpdateUIBase& GetUI() = 0;
	virtual HIMAGELIST GetImageList() const = 0;
	virtual int GetIconIndex(UINT id) const = 0;
	virtual int GetDataDirectoryIconIndex(int index) const = 0;
	virtual void SetStatusText(int index, PCWSTR text) = 0;
	virtual CFindReplaceDialog* GetFindDialog() = 0;
	virtual DiaSession const& GetSymbols() const = 0;
	virtual std::vector<FlatResource> const& GetFlatResources() const = 0;
	virtual int GetResourceIconIndex(WORD resType) const = 0;
	virtual DiaSymbol GetSymbolForName(PCWSTR mod, PCWSTR name) const = 0;
	virtual bool AddToolBar(HWND tb) = 0;
	virtual bool RemoveToolBar(HWND hWndToolBar) = 0;
};

struct IView abstract {
	virtual CString GetTitle() const = 0;
	virtual HWND GetHwnd() const = 0;
};
