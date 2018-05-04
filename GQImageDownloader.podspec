Pod::Spec.new do |s|

  s.name         = "GQImageDownloader"
  s.version      = "1.0.6"
  s.summary      = "图片下载工具"

  s.homepage     = "https://github.com/g763007297/GQImageDownloader"

  s.license      = "MIT (example)"
  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author       = { "developer_高" => "763007297@qq.com" }
  
  s.platform     = :ios, "6.0"

  s.source       = { :git => "https://github.com/g763007297/GQImageDownloader.git" , :tag => s.version}

  s.requires_arc = true

  s.default_subspec = 'Core'

  s.user_target_xcconfig = { 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }

  s.subspec 'Core' do |core|
    core.source_files = "GQImageDownloader/**/*.{h,m}"
  end

  s.subspec 'WebP' do |webp|
    webp.xcconfig = { 
      'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GQ_WEBP=1'
    }
    
    webp.dependency 'GQImageDownloader/Core'
    webp.ios.vendored_frameworks = 'GQImageDownloader/GQThirdPart/WebP.framework'
  end

end
