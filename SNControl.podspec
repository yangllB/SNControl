#
# Be sure to run `pod lib lint SNControl.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SNControl'
  s.version          = '0.1.13'
  s.summary          = '网络管控'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/yangllB/SNControl'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'leleyang' => 'yang_930907@163.com' }
  s.source           = { :git => 'https://github.com/yangllB/SNControl.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.frameworks = 'UIKit', "Foundation"
  s.vendored_frameworks = "SNControl/Frameworks/SNNetWorkControl.framework"
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64', 'ENABLE_BITCODE' => 'NO' }

  s.ios.deployment_target = '11.0'
  # s.source_files = 'SNControl/Classes/**/*'
  s.resource = 'SNControl/Assets/SNControl.bundle'
  # s.resource_bundles = {
  #   'SNControl' => ['SNControl/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.dependency 'AFNetworking'
  s.dependency 'FMDB/SQLCipher'
  s.dependency 'JSONModel'
  s.dependency 'YYKit'
end
