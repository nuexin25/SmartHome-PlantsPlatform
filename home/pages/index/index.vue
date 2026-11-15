<template>
	<view class="content">
		<view class="">温度{{temp}}℃</view>
		<view class="">湿度{{humi}}％</view>
		<switch :checked="led" @change="" />
	</view>
</template>

<script>
	const{createCommonToken} = require('@/key.js')
	export default {
		data() {
			return {
				temp:'11',
				humi:'22',
				led:true,
				token:'',
			}
		},
		onLoad() {
			const params ={ 
			author_key:'VTmVl547ApZa5O8h8xyxMkvQ0P3ima8BGox7eBSh7mwT9WGsWa9uVW2CDEmsTEJmfcUuUaZIRpmE4vaJwbniQg==',
			version:'2022-05-01',
			user_id:'375185',
			}
			this.token = createCommonToken(params);
		},
		onShow(){
			this.fetchDevData();
		},
		methods: {
			fetchDevData(){
				uni.request({
					url: 'https://iot-api.heclouds.com/thingmodel/query-device-property', //仅为示例，并非真实接口地址。
					   method:'GET',
						data: {
							product_id: '38R6xQeaZk',
							device_name: 'a1'
					    },
					    header: {
					        'authorization': this.token //自定义请求头信息
					    },
					    success: (res) => {
					        console.log(res.data);
					}
				})
			}

		}
	}
</script>

<style>
	.content {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
	}

	.logo {
		height: 200rpx;
		width: 200rpx;
		margin-top: 200rpx;
		margin-left: auto;
		margin-right: auto;
		margin-bottom: 50rpx;
	}

	.text-area {
		display: flex;
		justify-content: center;
	}

	.title {
		font-size: 36rpx;
		color: #8f8f94;
	}
</style>
