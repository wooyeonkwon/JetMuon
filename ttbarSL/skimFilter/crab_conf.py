from CRABClient.UserUtilities import config

config = config()

#config.Site.blacklist = ['T2_US_MIT']

config.General.requestName = 'WWtoLNu2Q'
config.General.workArea = 'crab_projects' 

config.JobType.pluginName = 'skimFilter'
config.JobType.psetName = 'conf.py'
config.JobType.numCores = 1
config.JobType.maxMemoryMB = 2000


config.Data.inputDataset = '/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/Run3Summer22MiniAODv4-130X_mcRun3_2022_realistic_v5-v2/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting    = 'Automatic'
config.Data.unitsPerJob = 1800
#config.Data.lumiMask = 'Cert_Collisions2022_355100_362760_Golden.json'
config.Data.outLFNDirBase = '/store/user/wkwon/AnalysisResults/'
config.Data.publication = False

config.Site.storageSite = 'T3_KR_KNU'
config.JobType.outputFiles = ['skimmed_data.root']
