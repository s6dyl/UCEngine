// C++ for the Windows Runtime v1.0.161012.5
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.StartScreen.0.h"
#include "Windows.UI.Notifications.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::StartScreen {

struct __declspec(uuid("143ab213-d05f-4041-a18c-3e3fcb75b41e")) __declspec(novtable) IDualSimTile : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsPinnedToStart(bool * value) = 0;
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("50567c9e-c58f-4dc9-b6e8-fa6777eeeb37")) __declspec(novtable) IDualSimTileStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetTileForSim2(Windows::Phone::StartScreen::IDualSimTile ** result) = 0;
    virtual HRESULT __stdcall abi_UpdateDisplayNameForSim1Async(hstring name, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForSim1(Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateTileUpdaterForSim2(Windows::UI::Notifications::ITileUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForSim1(Windows::UI::Notifications::IBadgeUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateBadgeUpdaterForSim2(Windows::UI::Notifications::IBadgeUpdater ** updater) = 0;
    virtual HRESULT __stdcall abi_CreateToastNotifierForSim1(Windows::UI::Notifications::IToastNotifier ** notifier) = 0;
    virtual HRESULT __stdcall abi_CreateToastNotifierForSim2(Windows::UI::Notifications::IToastNotifier ** notifier) = 0;
};

struct __declspec(uuid("2717f54b-50df-4455-8e6e-41e0fc8e13ce")) __declspec(novtable) IToastNotificationManagerStatics3 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_CreateToastNotifierForSecondaryTile(hstring tileId, Windows::UI::Notifications::IToastNotifier ** notifier) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Phone::StartScreen::DualSimTile> { using default_interface = Windows::Phone::StartScreen::IDualSimTile; };

}

namespace Windows::Phone::StartScreen {

template <typename T> struct impl_IDualSimTile;
template <typename T> struct impl_IDualSimTileStatics;
template <typename T> struct impl_IToastNotificationManagerStatics3;

}

namespace impl {

template <> struct traits<Windows::Phone::StartScreen::IDualSimTile>
{
    using abi = ABI::Windows::Phone::StartScreen::IDualSimTile;
    template <typename D> using consume = Windows::Phone::StartScreen::impl_IDualSimTile<D>;
};

template <> struct traits<Windows::Phone::StartScreen::IDualSimTileStatics>
{
    using abi = ABI::Windows::Phone::StartScreen::IDualSimTileStatics;
    template <typename D> using consume = Windows::Phone::StartScreen::impl_IDualSimTileStatics<D>;
};

template <> struct traits<Windows::Phone::StartScreen::IToastNotificationManagerStatics3>
{
    using abi = ABI::Windows::Phone::StartScreen::IToastNotificationManagerStatics3;
    template <typename D> using consume = Windows::Phone::StartScreen::impl_IToastNotificationManagerStatics3<D>;
};

template <> struct traits<Windows::Phone::StartScreen::DualSimTile>
{
    using abi = ABI::Windows::Phone::StartScreen::DualSimTile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.StartScreen.DualSimTile"; }
};

}

}
