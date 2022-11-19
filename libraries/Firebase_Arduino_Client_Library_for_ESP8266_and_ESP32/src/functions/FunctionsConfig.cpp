/**
 * Google's Cloud Functions Config class, FunctionsConfig.cpp version 1.0.3
 * 
 * This library supports Espressif ESP8266 and ESP32
 * 
 * Created August 21, 2021
 * 
 * This work is a part of Firebase ESP Client library
 * Copyright (c) 2020, 2021 K. Suwatchai (Mobizt)
 * 
 * The MIT License (MIT)
 * Copyright (c) 2020, 2021 K. Suwatchai (Mobizt)
 * 
 * 
 * Permission is hereby granted, free of charge, to any person returning a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "FirebaseFS.h"

#ifdef ENABLE_FB_FUNCTIONS

#ifndef _FB_FUNCTIONS_CONFIG_CPP_
#define _FB_FUNCTIONS_CONFIG_CPP_

#include "FunctionsConfig.h"

FunctionsConfig::~FunctionsConfig()
{
    ut->clearS(_projectId);
    ut->clearS(_locationId);
    ut->clearS(_bucketId);
    clear();
}

void FunctionsConfig::mSetProjectId(const char *projectId)
{
    _projectId = projectId;
}
void FunctionsConfig::mSetLocationId(const char *locationId)
{
    _locationId = locationId;
}
void FunctionsConfig::mSetBucketId(const char *bucketId)
{
    _bucketId = bucketId;
}

void FunctionsConfig::addUpdateMasks(const char *key)
{

    for (size_t i = 0; i < _updateMask.size(); i++)
    {
        if (strcmp(_updateMask[i].c_str(), key) == 0)
            return;
    }
    _updateMask.push_back(key);
}
void FunctionsConfig::mFunctionsConfig(const char *projectId, const char *locationId, const char *bucketId)
{
    _projectId = projectId;
    _locationId = locationId;
    _bucketId = bucketId;
    _triggerType = fb_esp_functions_trigger_type_https;
    _updateMask.clear();
}

void FunctionsConfig::removeUpdateMasks(const char *key)
{
    for (size_t i = 0; i < _updateMask.size(); i++)
    {
        if (strcmp(_updateMask[i].c_str(), key) == 0)
        {
            _updateMask.erase(_updateMask.begin() + i);
            return;
        }
    }
}

void FunctionsConfig::mSetName(const char *name)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        std::string t;
        ut->appendP(t, fb_esp_pgm_str_395);
        t += _projectId;
        ut->appendP(t, fb_esp_pgm_str_364);
        t += _locationId;
        ut->appendP(t, fb_esp_pgm_str_365);
        ut->appendP(t, fb_esp_pgm_str_1);
        t += name;
        char *tmp = ut->strP(fb_esp_pgm_str_274);
        _funcCfg.set(tmp, t.c_str());
        ut->delS(tmp);
        _name = name;
    }
}

void FunctionsConfig::mSetDescription(const char *description)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_367);
        _funcCfg.set(tmp, description);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetEntryPoint(const char *entry)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_368);
        _funcCfg.set(tmp, entry);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
    _entryPoint = entry;
}

void FunctionsConfig::mSetRuntime(const char *runtime)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_369);
        _funcCfg.set(tmp, runtime);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetTimeout(const char* seconds)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_370);
        std::string s = seconds;
        ut->appendP(s, fb_esp_pgm_str_417);
        _funcCfg.set(tmp, s.c_str());
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetAvailableMemoryMb(const char* mb)
{
    int _mb = atoi(mb);

    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        if (_mb > 4096)
            _mb = 4096;
        else if (_mb > 2048 && _mb <= 4096)
            _mb = 4096;
        else if (_mb > 1024 && _mb <= 2048)
            _mb = 2048;
        else if (_mb > 512 && _mb <= 1024)
            _mb = 1024;
        else if (_mb > 256 && _mb <= 512)
            _mb = 512;
        else if (_mb > 128 && _mb <= 256)
            _mb = 256;
        else
            _mb = 128;

        char *tmp = ut->strP(fb_esp_pgm_str_371);
        _funcCfg.set(tmp, _mb);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetMaxInstances(const char* maxInstances)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        int m = atoi(maxInstances);
        char *tmp = ut->strP(fb_esp_pgm_str_377);
        _funcCfg.set(tmp, m);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetSource(const char *path, fb_esp_functions_sources_type sourceType, fb_esp_mem_storage_type storageType)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        std::string t;
        char *tmp = nullptr;
        switch (sourceType)
        {
        case functions_sources_type_storage_bucket_archive:

            ut->appendP(t, fb_esp_pgm_str_350);
            t += _bucketId;
            if (path[0] != '/')
                ut->appendP(t, fb_esp_pgm_str_1);
            t += path;
            tmp = ut->strP(fb_esp_pgm_str_381);
            _funcCfg.set(tmp, t.c_str());
            addUpdateMasks(tmp);
            ut->delS(tmp);
            _sourceType = sourceType;
            break;

        case functions_sources_type_storage_bucket_sources:
            _bucketSourcesPath = path;
            _sourceType = sourceType;
            break;

        case functions_sources_type_local_archive:

            _uploadArchiveFile = path;
            _uploadArchiveStorageType = storageType;
            _sourceType = sourceType;
            break;

        case functions_sources_type_repository:

            tmp = ut->strP(fb_esp_pgm_str_382);
            _funcCfg.set(tmp, path);
            addUpdateMasks(tmp);
            ut->delS(tmp);
            _sourceType = sourceType;
            break;

        default:
            break;
        }
    }
}
void FunctionsConfig::setSource(const uint8_t *pgmArchiveData, size_t len)
{
    _pgmArc = pgmArchiveData;
    _pgmArcLen = len;
    _sourceType = functions_sources_type_flash_data;
}

void FunctionsConfig::mSetIngressSettings(const char *settings)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_380);
        _funcCfg.set(tmp, settings);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mAddLabel(const char *key, const char *value)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        std::string t;
        ut->appendP(t, fb_esp_pgm_str_373);
        addUpdateMasks(t.c_str());
        ut->appendP(t, fb_esp_pgm_str_1);
        t += key;
        _funcCfg.set(t.c_str(), value);
    }
}
void FunctionsConfig::clearLabels()
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_373);
        _funcCfg.remove(tmp);
        removeUpdateMasks(tmp);
        ut->delS(tmp);
    }
}
void FunctionsConfig::mAddEnvironmentVariable(const char *key, const char *value)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        std::string t;
        ut->appendP(t, fb_esp_pgm_str_374);
        addUpdateMasks(t.c_str());
        ut->appendP(t, fb_esp_pgm_str_1);
        t += key;
        _funcCfg.set(t.c_str(), value);
    }
}
void FunctionsConfig::clearEnvironmentVariables()
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_374);
        _funcCfg.remove(tmp);
        removeUpdateMasks(tmp);
        ut->delS(tmp);
    }
}
void FunctionsConfig::mAddBuildEnvironmentVariable(const char *key, const char *value)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        std::string t;
        ut->appendP(t, fb_esp_pgm_str_375);
        addUpdateMasks(t.c_str());
        ut->appendP(t, fb_esp_pgm_str_1);
        t += key;
        _funcCfg.set(t.c_str(), value);
    }
}

void FunctionsConfig::clearBuildEnvironmentVariables()
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_375);
        _funcCfg.remove(tmp);
        removeUpdateMasks(tmp);
        ut->delS(tmp);
    }
}
void FunctionsConfig::mSetNetwork(const char *network)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_376);
        _funcCfg.set(tmp, network);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}
void FunctionsConfig::mSetVpcConnector(const char *vpcConnector)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_378);
        _funcCfg.set(tmp, vpcConnector);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}
void FunctionsConfig::mSetVpcConnectorEgressSettings(const char *e)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        char *tmp = ut->strP(fb_esp_pgm_str_379);
        _funcCfg.set(tmp, e);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::mSetEventTrigger(const char *eventType, const char *resource, const char *service, const char *failurePolicy)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        _triggerType = fb_esp_functions_trigger_type_event;
        char *tmp = nullptr;
        if (strlen(eventType) > 0)
        {
            tmp = ut->strP(fb_esp_pgm_str_385);
            _funcCfg.set(tmp, eventType);
            ut->delS(tmp);
        }

        if (strlen(resource) > 0)
        {
            tmp = ut->strP(fb_esp_pgm_str_391);
            _funcCfg.set(tmp, resource);
            ut->delS(tmp);
        }

        if (strlen(service) > 0)
        {
            tmp = ut->strP(fb_esp_pgm_str_392);
            _funcCfg.set(tmp, service);
            ut->delS(tmp);
        }

        if (strlen(failurePolicy) > 0)
        {
            tmp = ut->strP(fb_esp_pgm_str_393);
            std::string t;
            ut->appendP(t, fb_esp_pgm_str_394);
            static FirebaseJson js;
            js.clear();
            js.setJsonData(t.c_str());
            _funcCfg.set(tmp, js);
            ut->delS(tmp);
        }
        tmp = ut->strP(fb_esp_pgm_str_472);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

void FunctionsConfig::setIamPolicy(PolicyBuilder *policy)
{
    if (!ut)
        ut = Signer.ut;
    if (ut)
    {
        _policy = policy;
        char *tmp = ut->strP(fb_esp_pgm_str_473);
        addUpdateMasks(tmp);
        ut->delS(tmp);
    }
}

String FunctionsConfig::getTriggerUrl()
{
    return _httpsTriggerUrl.c_str();
}

void FunctionsConfig::clear()
{
    _updateMask.clear();
    _funcCfg.clear();
    ut->clearS(_entryPoint);
    ut->clearS(_name);
    ut->clearS(_httpsTriggerUrl);
    ut->clearS(_bucketSourcesPath);
    ut->clearS(_uploadArchiveFile);
    _pgmArc = nullptr;
    _pgmArcLen = 0;
    _uploadArchiveStorageType = mem_storage_type_undefined;
    _sourceType = functions_sources_type_undefined;
    _triggerType = fb_esp_functions_trigger_type_undefined;
    _policy = nullptr;
}

#endif

#endif //ENABLE